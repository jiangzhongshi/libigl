// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2019 Hanxiao Shen <hanxiao@cs.nyu.edu>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#ifndef IGL_COPYLEFT_CGAL_SEGMENT_SEGMENT_INTERSECT_H
#define IGL_COPYLEFT_CGAL_SEGMENT_SEGMENT_INTERSECT_H

#include "../../igl_inline.h"
#include <Eigen/Core>

namespace igl
{
  namespace copyleft
  {
    namespace cgal
    {
      // Given two segments in 2d test whether they intersect each other
      // using orient2D
      // 
      // Inputs:
      //   A:   1st endpoint of segment 1
      //   B:   2st endpoint of segment 1
      //   C:   1st endpoint of segment 2
      //   D:   2st endpoint of segment 2
      //   eps: precision used for colinear case
      // Returns true if they intersect

      template <typename DerivedP>
      IGL_INLINE bool segment_segment_intersect(
        // input:
        const Eigen::MatrixBase<DerivedP>& A,
        const Eigen::MatrixBase<DerivedP>& B,
        const Eigen::MatrixBase<DerivedP>& C,
        const Eigen::MatrixBase<DerivedP>& D, 
        typename DerivedP::Scalar eps
      );

      // convienient wrapper
      template <typename Scalar>
      IGL_INLINE bool segment_segment_intersect(
        const Scalar a[2], 
        const Scalar b[2], 
        const Scalar c[2], 
        const Scalar d[2],
        const Scalar eps
      );
    }
  }
}

#ifndef IGL_STATIC_LIBRARY
#  include "segment_segment_intersect.cpp"
#endif


#endif
