// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2019 Hanxiao Shen <hanxiao@cs.nyu.edu>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#ifndef POINT_INSIDE_POLYGON_H
#define POINT_INSIDE_POLYGON_H

#include <Eigen/Core>
#include "segment_segment_intersect.h"

#include "../../igl_inline.h"
#include <Eigen/Core>

namespace igl
{
  namespace copyleft
  {
    namespace cgal
    {
      // check whether 2d point lies inside 2d polygon
      // Inputs:
      //   P: n*2 polygon, n >= 3
      //   q: 2d query point
      // Returns true if point is inside polygon
      template <typename Scalar>
      bool point_inside_polygon(
          const Eigen::Matrix<Scalar,Eigen::Dynamic,Eigen::Dynamic>& P,
          const Eigen::Matrix<Scalar,1,2>& q
      );
    }
  }
}

#ifndef IGL_STATIC_LIBRARY
#  include "point_inside_polygon.cpp"
#endif

#endif