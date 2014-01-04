// This file is part of libigl, a simple c++ geometry processing library.
// 
// Copyright (C) 2013 Alec Jacobson <alecjacobson@gmail.com>
// 
// This Source Code Form is subject to the terms of the Mozilla Public License 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.
#include "project_to_line_segment.h"
#include "project_to_line.h"
#include <Eigen/Core>

template <
  typename DerivedP, 
  typename DerivedS, 
  typename DerivedD, 
  typename Derivedt, 
  typename DerivedsqrD>
IGL_INLINE void igl::project_to_line_segment(
  const Eigen::PlainObjectBase<DerivedP> & P,
  const Eigen::PlainObjectBase<DerivedS> & S,
  const Eigen::PlainObjectBase<DerivedD> & D,
  Eigen::PlainObjectBase<Derivedt> & t,
  Eigen::PlainObjectBase<DerivedsqrD> & sqrD)
{
  project_to_line(P,S,D,t,sqrD);
  const int np = P.rows();
  // loop over points and fix those that projected beyond endpoints
#pragma omp parallel for
  for(int p = 0;p<np;p++)
  {
    if(t(p)<0)
    {
      sqrD(p) = (P.row(p)-S).squaredNorm();
      t(p) = 0;
    }else if(t(p)>1)
    {
      sqrD(p) = (P.row(p)-D).squaredNorm();
      t(p) = 1;
    }
  }
}

#ifndef IGL_HEADER_ONLY
// Explicit template specialization
template void igl::project_to_line_segment<Eigen::Matrix<double, 1, 3, 1, 1, 3>, Eigen::Matrix<double, 1, 3, 1, 1, 3>, Eigen::Matrix<double, 1, 3, 1, 1, 3>, Eigen::Matrix<double, 1, 1, 0, 1, 1>, Eigen::Matrix<double, 1, 1, 0, 1, 1> >(Eigen::PlainObjectBase<Eigen::Matrix<double, 1, 3, 1, 1, 3> > const&, Eigen::PlainObjectBase<Eigen::Matrix<double, 1, 3, 1, 1, 3> > const&, Eigen::PlainObjectBase<Eigen::Matrix<double, 1, 3, 1, 1, 3> > const&, Eigen::PlainObjectBase<Eigen::Matrix<double, 1, 1, 0, 1, 1> >&, Eigen::PlainObjectBase<Eigen::Matrix<double, 1, 1, 0, 1, 1> >&);
#endif