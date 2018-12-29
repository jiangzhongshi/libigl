// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2018 Zhongshi Jiang <jiangzs@nyu.edu>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

m.def("ramer_douglas_peucker", []
(
  const Eigen::MatrixXd &P, 
  double tol,
  Eigen::MatrixXd &S,
  Eigen::MatrixXi &J
)
{
  Eigen::VectorXi Jt;
  igl::ramer_douglas_peucker(P, tol, S, Jt);
  J =Jt;
},
 R"igl_Qu8mg5v7(// Ramer-Douglas-Peucker piecewise-linear curve simplification.
  //
  // Inputs:
  //   P  #P by dim ordered list of vertices along the curve
  //   tol  tolerance (maximal euclidean distance allowed between the new line
  //     and a vertex)
  // Outputs:
  //   S  #S by dim ordered list of points along the curve
  //   J  #S list of indices into P so that S = P(J,:)
  //)igl_Qu8mg5v7" ,
py::arg("P"), py::arg("tol"), py::arg("S"), py::arg("J"));

m.def("ramer_douglas_peucker", []
(
  const Eigen::MatrixXd &P, 
  double tol,
  Eigen::MatrixXd &S,
  Eigen::MatrixXi &J,
  Eigen::MatrixXd &Q
)
{
  Eigen::VectorXi Jt;
  igl::ramer_douglas_peucker(P, tol, S, Jt, Q);
  J=Jt;
},
 R"igl_Qu8mg5v7(// Run (Ramer-)Duglass-Peucker curve simplification but keep track of where
  // every point on the original curve maps to on the simplified curve.
  //
  // Inputs:
  //   P  #P by dim list of points, (use P([1:end 1],:) for loops)
  //   tol  DP tolerance
  // Outputs:
  //   S  #S by dim list of points along simplified curve
  //   J  #S indices into P of simplified points
  //   Q  #P by dim list of points mapping along simplified curve
  //)igl_Qu8mg5v7" ,
py::arg("P"), py::arg("tol"), py::arg("S"), py::arg("J"), py::arg("Q"));
