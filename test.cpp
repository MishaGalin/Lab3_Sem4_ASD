#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "generator.h"
#include "dinamic.h"
#include "optimal.h"
#include <vector>

TEST_CASE("Check primitive generator", "[generator]") {
    vector<int> input{ -2,5,-1,6,4,0,-3,-4,2,1,0 };
    vector<int> check{6,4,2,0};
    cout << endl;
    Generator a;
    a.Read(input);
    a.Find();
    a.print();
    cout << endl;
    REQUIRE(a.Result==check);
}

TEST_CASE("Check dinamic generator", "[dinamic]") {
    vector<int> input{ -2,5,-1,6,4,0,-3,-4,2,1,0 };
    vector<int> check{ 6,4,2,0 };
    Dinamic b;
    b.Read(input);
    b.Find();
    b.print();
    cout << endl;
    REQUIRE(b.Result == check);
}

TEST_CASE("Check optimal find maximum", "[optimal]") {
    vector<double> content{ 0.5, 1, 2, 5, 0.1, 10, 0.01 };
    double MAX = 175000;
    Optimal c;
    c.Read(content);
    c.print();
    cout << endl;
    REQUIRE(c.Maximum[0][c.N-1] == MAX);
}