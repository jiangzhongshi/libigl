// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2019 Hanxiao Shen <hanxiao@cs.nyu.edu>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#include "segment_segment_intersect.h"
#include "orient2D.h"

// https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/
template <typename Scalar>
IGL_INLINE bool igl::copyleft::cgal::segment_segment_intersect(
  const Scalar a[2], 
  const Scalar b[2], 
  const Scalar c[2], 
  const Scalar d[2],
  const Scalar eps
)
{
  short t1 = orient2D(a,b,c);
  short t2 = orient2D(b,c,d);
  short t3 = orient2D(a,b,d);
  short t4 = orient2D(a,c,d);

  // assume m,n,p are colinear, check whether p is in range [m,n]
  auto on_segment = [](
    const Scalar m[2],
    const Scalar n[2],
    const Scalar p[2],
    const Scalar eps
  ){
    // if segment is open, meaning there is a neighborhood (-eps,eps)
    // s.t. if p is within the neighborhood, it's considered on segment
    // if eps is 0, meaning the segments are closed, e.g., exactly equal 
    // to end points is considered intersection)
      return ((p[0] >= std::min(m[0],n[0])-eps) &&
              (p[0] <= std::max(m[0],n[0])+eps) &&
              (p[1] >= std::min(m[1],n[1])-eps) &&
              (p[1] <= std::max(m[1],n[1])+eps));
  };
  
  // colinear case        
  if((t1 == 0 && on_segment(a,b,c,eps)) ||
     (t2 == 0 && on_segment(c,d,b,eps)) ||
     (t3 == 0 && on_segment(a,b,d,eps)) ||
     (t4 == 0 && on_segment(c,d,a,eps))) 
     return true;
  
  // ordinary case
  return (t1 != t3 && t2 != t4);
}

template <typename DerivedP>
IGL_INLINE bool igl::copyleft::cgal::segment_segment_intersect(
  const Eigen::MatrixBase<DerivedP>& A,
  const Eigen::MatrixBase<DerivedP>& B,
  const Eigen::MatrixBase<DerivedP>& C,
  const Eigen::MatrixBase<DerivedP>& D, 
  typename DerivedP::Scalar eps
)
{
  typedef typename DerivedP::Scalar Scalar;

  Scalar a[2] = {A(0),A(1)};
  Scalar b[2] = {B(0),B(1)};
  Scalar c[2] = {C(0),C(1)};
  Scalar d[2] = {D(0),D(1)};
    
  return segment_segment_intersect(a,b,c,d,eps);

}

#ifdef IGL_STATIC_LIBRARY
template bool igl::copyleft::cgal::segment_segment_intersect<Eigen::Matrix<double, 1, 2, 1, 1, 2> >(Eigen::MatrixBase<Eigen::Matrix<double, 1, 2, 1, 1, 2> > const&, Eigen::MatrixBase<Eigen::Matrix<double, 1, 2, 1, 1, 2> > const&, Eigen::MatrixBase<Eigen::Matrix<double, 1, 2, 1, 1, 2> > const&, Eigen::MatrixBase<Eigen::Matrix<double, 1, 2, 1, 1, 2> > const&, Eigen::Matrix<double, 1, 2, 1, 1, 2>::Scalar);
#endif