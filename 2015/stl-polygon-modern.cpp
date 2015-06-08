// listvec-perimers.cpp -> find all perimeters of polygons

#include "stdafx.h"
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

// let's define these types and spare some <>'s
typedef double coord;
typedef vector<coord> point;
typedef list<point> polygon;

// why waste files, when we can use stringstream
string idata("\
        (1, 5) (3, 5) (3, 6) (4, 10) (0,10), (0,2)\n \
        (10, 20) (10, 25) (5, 25) (3, 25)\n \
        ");

// handy operator for printing points
auto operator << (ostream& ostr, point& p) -> decltype(ostr) {
    return ostr << '(' << p[0] << ", " << p[1] << ')';
}

// handy operator for printing poly's
// and brief overview of possible iterators
auto operator << (ostream& ostr, polygon& poly) -> decltype(ostr) {
    // now let's iterate and find perimeter ...
    // first -> iterators overview
    cout << "Polygon: " << endl;

    /*
    //C++99 iterator classic
    for (polygon::iterator it=poly.begin(); it != poly.end(); ++it) {
    cout << *it << endl;        // explicit cast here to get operator
    }
    */

    //Cxx11 range based iterator
    for (point& p: poly) {
        cout << p << endl;
    }

    /*
    // Modern C++ approach
    // the [] is lambda

    for_each(poly.begin(), poly.end(), [](point& p) -> void {
    cout << p << endl;
    });
    */

    if (!poly.size()) {
        ostr << "N/A" << endl;
    }
    return ostr;
}

// operator to read poly's
auto operator >> (istream& istr, polygon &poly) -> decltype(istr) {
    coord x, y;
    while (     istr >> x >> y ) {
        point p(2);
        p[0] = x; p[1] = y;
        poly.push_back(p);
    }

    return istr;
}

double perimeter(polygon &poly) {
    auto perim = 0.0;

    if ( !poly.size() ) {
        return 0;
    }

    /*
       for (auto fp = poly.back(); !poly.empty(); poly.pop_front()) {
       auto p = poly.front();

       perim += sqrt((p[0] - fp[0]) * (p[0] - fp[0]) + (p[1] - fp[1]) * (p[1] - fp[1]));
       fp = p;
       }
       */

    auto fp = poly.back();
    for (point& p: poly) {
        perim += sqrt((p[0] - fp[0]) * (p[0] - fp[0]) + (p[1] - fp[1]) * (p[1] - fp[1]));
        fp = p;
    }

    return perim;
}

// task - find perimeters of all polygons in the file

int main() {
    string linebuf;

    // craete stream for the input data
    istringstream istr(idata);
    while (getline(istr, linebuf)) {
        if ( istr.fail() ) break;
        // clear junk symbols so that we can
        // easily read some floating point vals
        for (auto &c: linebuf) {
            if (c == '(' || c == ')' || c == ',' )
                c = ' ';
        }

        // create stream for my line only
        istringstream iline(linebuf);

        // read the polygon
        polygon poly;
        iline >> poly;

        // print poly
        cout << poly;

        // calculate perimeter
        cout << "Perimeter: " << perimeter(poly) << endl;
    }

    return 0;
}

