#include "ear_clipping.h"
#include <igl/slice.h>
#include <igl/copyleft/cgal/point_inside_polygon.h>
#include <igl/copyleft/cgal/orient2D.h>

template <typename DerivedP>
IGL_INLINE bool igl::copyleft::cgal::is_ear(
  const Eigen::MatrixBase<DerivedP>& P,
  const Eigen::VectorXi& RT,
  const Eigen::VectorXi& L,
  const Eigen::VectorXi& R, 
  const int i
){
  typedef typename DerivedP::Scalar Scalar;

  int a = L(i), b = R(i);
  if(RT(i) != 0 || RT(a) != 0 || RT(b) != 0) return false;
  Scalar A[2] = {P(a, 0), P(a, 1)};
  Scalar B[2] = {P(i, 0), P(i, 1)};
  Scalar C[2] = {P(b, 0), P(b, 1)};
  if(igl::copyleft::cgal::orient2D(A, B, C)<=0) return false;
  
  // check if any vertex is lying inside triangle (a,b,i);
  int k=R(b);
  while(k!=a){
    Eigen::MatrixXd T(3,2);
    T<<P.row(a),P.row(i),P.row(b);
    Eigen::RowVector2d q=P.row(k);
    if(point_inside_polygon(T,q)) 
      return false;
    k=R(k);
  }
  return true;
}

// https://www.geometrictools.com/Documentation/TriangulationByEarClipping.pdf
template <typename DerivedP>
IGL_INLINE void igl::copyleft::cgal::ear_clipping(
  const Eigen::MatrixBase<DerivedP>& P,
  const Eigen::VectorXi& RT,
  Eigen::VectorXi& I,
  Eigen::MatrixXi& eF, 
  Eigen::PlainObjectBase<DerivedP>& nP
){

  Eigen::VectorXi L(P.rows());
  Eigen::VectorXi R(P.rows());
  for(int i=0;i<P.rows();i++){
    L(i) = (i-1+P.rows())%P.rows();
    R(i) = (i+1)%P.rows();
  }

  Eigen::VectorXi ears; // mark ears
  Eigen::VectorXi X; // clipped vertices
  ears.setZero(P.rows());
  X.setZero(P.rows());

  // initialize ears
  for(int i=0;i<P.rows();i++){
    ears(i) = is_ear(P,RT,L,R,i);
  }

  // clip ears until none left
  while(ears.maxCoeff()==1){
    
    // find the first ear
    int e = 0;
    while(e<ears.rows()&&ears(e)!=1) e++;
    
    // find valid neighbors
    int a = L(e), b = R(e);
    if(a == b) break;

    // clip ear and store face
    eF.conservativeResize(eF.rows()+1,3);
    eF.bottomRows(1)<<a,e,b;
    L(b) = a;
    L(e) = -1;
    R(a) = b;
    R(e) = -1;
    ears(e) = 0; // mark vertex e as non-ear

    // update neighbor's ear status
    ears(a) = is_ear(P,RT,L,R,a);
    ears(b) = is_ear(P,RT,L,R,b);
    X(e) = 1;

    // when only one edge left
    // mark the endpoints as clipped
    if(L(a)==b && R(b)==a){
      X(a) = 1;
      X(b) = 1;
    }
  }
  
  // collect remaining vertices if theres any
  for(int i=0;i<X.rows();i++)
    X(i) = 1-X(i);
  I.resize(X.sum());
  int j=0;
  for(int i=0;i<X.rows();i++)
    if(X(i)==1){
      I(j++) = i;
    }
  igl::slice(P,I,1,nP);
}

#ifdef IGL_STATIC_LIBRARY
template void igl::copyleft::cgal::ear_clipping<Eigen::Matrix<double, -1, -1, 0, -1, -1> >(Eigen::MatrixBase<Eigen::Matrix<double, -1, -1, 0, -1, -1> > const&, Eigen::Matrix<int, -1, 1, 0, -1, 1> const&, Eigen::Matrix<int, -1, 1, 0, -1, 1>&, Eigen::Matrix<int, -1, -1, 0, -1, -1>&, Eigen::PlainObjectBase<Eigen::Matrix<double, -1, -1, 0, -1, -1> >&);
#endif