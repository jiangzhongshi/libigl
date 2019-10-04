// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2019 Hanxiao Shen <hanxiao@cs.nyu.edu>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#ifndef EAR_CLIPPING
#define EAR_CLIPPING

#include <Eigen/Core>
#include "../../igl_inline.h"
#include "segment_segment_intersect.h"

namespace igl
{
  namespace copyleft
  {
    namespace cgal
    {
      template <typename DerivedP>
      void ear_clipping(
        const Eigen::MatrixBase<DerivedP>& P,
        const Eigen::VectorXi& RT,
        Eigen::VectorXi& I,
        Eigen::MatrixXi& eF, // #ear*3 indices of ears
        Eigen::PlainObjectBase<DerivedP>& nP
      );

      template <typename DerivedP>
      bool is_ear(
        const Eigen::MatrixBase<DerivedP>& P,
        const Eigen::VectorXi& RT,
        const Eigen::VectorXi& L,
        const Eigen::VectorXi& R, 
        const int i
      );
    }
  }
}

#ifndef IGL_STATIC_LIBRARY
#  include "ear_clipping.cpp"
#endif


#endif