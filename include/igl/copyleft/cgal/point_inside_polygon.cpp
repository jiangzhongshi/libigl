// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2019 Hanxiao Shen <hanxiao@cs.nyu.edu>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#include "point_inside_polygon.h"
#include "orient2D.h"

// Ray casting algorithm
// [https://www.geeksforgeeks.org/how-to-check-if-a-given-point-lies-inside-a-polygon/]
template <typename Scalar>
IGL_INLINE bool igl::copyleft::cgal::point_inside_polygon(
    const Eigen::Matrix<Scalar,Eigen::Dynamic,Eigen::Dynamic>& P,
    const Eigen::Matrix<Scalar,1,2>& q
){
  for(int i=0;i<P.rows();i++){
    int i_1 = (i+1) % P.rows();
    double a[2] = {P(i  ,0),P(i  ,1)};
    double b[2] = {P(i_1,0),P(i_1,1)};
    double c[2] = {q(0  ,0),q(0  ,1)};
    if(igl::copyleft::cgal::orient2D(a,b,c)<0)
      return false;
  }
  return true;
}

#ifdef IGL_STATIC_LIBRARY
template bool igl::copyleft::cgal::point_inside_polygon<double>(Eigen::Matrix<double, -1, -1, 0, -1, -1> const&, Eigen::Matrix<double, 1, 2, 1, 1, 2> const&);
#endif