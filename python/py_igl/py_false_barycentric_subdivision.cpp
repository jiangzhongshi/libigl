// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2018 Zhongshi Jiang <jiangzs@nyu.edu>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
m.def("false_barycentric_subdivision", []
(
  const Eigen::MatrixXd& V,
  const Eigen::MatrixXi& F,
  Eigen::MatrixXd& NV,
  Eigen::MatrixXi& NF
)
{
  return igl::false_barycentric_subdivision(V, F, NV, NF);
}, "false_barycentric_subdivision",
py::arg("V"), py::arg("F"), py::arg("NV"), py::arg("NF"));

