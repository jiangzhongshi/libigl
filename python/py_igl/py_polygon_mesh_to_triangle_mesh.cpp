// This file is part of libigl, a simple c++ geometry processing library.
//
// Copyright (C) 2018 Zhongshi Jiang <jiangzs@nyu.edu>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

m.def("polygon_mesh_to_triangle_mesh", []
(
  const std::vector<std::vector<int>>&P,
  Eigen::MatrixXi& F
)
{
  return igl::polygon_mesh_to_triangle_mesh(P, F);
},
 R"igl_Qu8mg5v7(// Triangulate a general polygonal mesh into a triangle mesh.
  //
  // Inputs:
  //   vF  list of polygon index lists
  // Outputs:
  //   F  eigen int matrix #F by 3
  //
  // Example:
  //   vector<vector<double > > vV;
  //   vector<vector<int > > vF;
  //   read_triangle_mesh("poly.obj",vV,vF);
  //   MatrixXd V;
  //   MatrixXi F;
  //   list_to_matrix(vV,V);
  //   triangulate(vF,F);
  //)igl_Qu8mg5v7" ,
py::arg("P"), py::arg("F"));
