// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2018 Zhongshi Jiang
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.


m.def("random_points_on_mesh", []
(
  const int n,
  const Eigen::MatrixXd &V,
  const Eigen::MatrixXi &F,
  Eigen::MatrixXd &B,
  Eigen::MatrixXi &FI
)
{
  return igl::random_points_on_mesh(n, V, F, B, FI);
}, "random_points_on_mesh",
py::arg("n"),py::arg("V"),py::arg("F"), py::arg("B"),py::arg("FI"));

