// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2018 Zhongshi Jiang
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.


m.def("uniformly_sample_two_manifold", []
(
    const Eigen::MatrixXd & W,
    const Eigen::MatrixXi & F, 
    const int k, 
    const double push,
    Eigen::MatrixXd & WS
)
{
  return igl::uniformly_sample_two_manifold(W,F,k,push,WS);
}, "uniformly_sample_two_manifold",
py::arg("W"),py::arg("F"), py::arg("k"),py::arg("push"), py::arg("WS"));

