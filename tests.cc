#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "edge.hh"

using quady::Edge;

TEST_CASE("Edge properties", "[edge]") {
    Edge* edge = Edge::make();

    REQUIRE(edge->Rot()->InvRot() == edge);
    REQUIRE(edge->Sym()->Sym() == edge);

    REQUIRE(edge->Onext() == edge);
    REQUIRE(edge->Oprev() == edge);

    REQUIRE(edge->Dnext() == edge);
    REQUIRE(edge->Dprev() == edge);
}
