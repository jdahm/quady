#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <filesystem>

#include "cell.hh"
#include "obj.hh"

using namespace quady;
namespace fs = std::filesystem;


TEST_CASE("Serialization", "[obj]") {
    Cell *this_cell = Cell::makeTetrahedron();
    const std::string filename{fs::temp_directory_path() / "tetrahedron.txt"};

    objWriteCell(this_cell, filename.c_str());
    Cell *other_cell = objReadCell(filename.c_str());

  {
    CellFaceIterator this_faces(this_cell), other_faces(other_cell);

    Face *this_face, *other_face;
    while ((this_face = this_faces.next()) != 0 and (other_face = this_faces.next()) != 0) {
      REQUIRE(this_face->getID() == other_face->getID());

      FaceEdgeIterator this_edges(this_face), other_edges(other_face);

      Edge *this_edge, *other_edge;
      while ((this_edge = this_edges.next()) != 0 and (other_edge = other_edges.next()) != 0)
        REQUIRE(this_edge->Dest()->getID() == other_edge->Dest()->getID());
    }
  }

  {
    CellVertexIterator this_vertices(this_cell), other_vertices(other_cell);

    Vertex *this_vertex, *other_vertex;
    while ((this_vertex = this_vertices.next()) != 0 and (other_vertex = other_vertices.next()) != 0) {
      REQUIRE(this_vertex->getID() == other_vertex->getID());

      VertexEdgeIterator this_edges(this_vertex), other_edges(other_vertex);

      Edge *this_edge, *other_edge;
      while ((this_edge = this_edges.next()) != 0 and (other_edge = other_edges.next()) != 0)
        REQUIRE(this_edge->Left()->getID() == other_edge->Left()->getID());
    }
  }
}
