//
// Created by bangoc on 04/09/2017.
//

#include "Simple_window.h"
#include "GUI.h"

#include <iostream>
#include <fstream>
#include <string>

struct Distribution {
    int year, young, middle, old;
};

std::istream& operator>>(std::istream& is, Distribution& d) {
    char ch1 = 0;
    char ch2 = 0;
    char ch3 = 0;
    Distribution dd;

    if (is >> ch1 >> dd.year >> ch2 >> dd.young >> dd.middle >> dd.old >> ch3) {
        if (ch1 != '(' || ch2 != ':' || ch3 != ')') {
            is.clear(std::ios_base::failbit);
            return is;
        }
    } else {
        return is;
    }
    d = dd;
    return is;
}

class Scale {
    int cbase;
    int vbase;
    double scale;
 public:
    Scale(int b, int vb, double s): cbase {b}, vbase {vb}, scale{s} {}
    int operator()(int v) const {return cbase + (v - vbase) * scale;}
};

int main() {
    constexpr int xmax = 600;
    constexpr int ymax = 400;

    constexpr int xoffset = 100;
    constexpr int yoffset = 60;

    constexpr int xspace = 40;
    constexpr int yspace = 40;

    constexpr int xlength = xmax - xoffset - xspace;
    constexpr int ylength = ymax - yoffset - yspace;

    constexpr int base_year = 1960;
    constexpr int end_year = 2040;

    constexpr double xscale = double(xlength)/(end_year - base_year);
    constexpr double yscale = double(ylength)/100;

    Scale xs {xoffset, base_year, xscale};
    Scale ys {ymax - yoffset, 0, -yscale};

    Simple_window win {Graph_lib::Point{100, 100}, xmax, ymax, "Aging Japan"};
    Graph_lib::Axis x {Graph_lib::Axis::x, Graph_lib::Point{xoffset, ymax - yoffset}, xlength,
            (end_year - base_year)/10,
            "year 1960    1970    1980     1990     "
            "2000      2010      2020      2030     2040"};
    x.label.move(-100, 0);

    Graph_lib::Axis y {Graph_lib::Axis::y, Graph_lib::Point{xoffset, ymax - yoffset}, ylength, 10,
            "% of population"};

    Graph_lib::Line current_year {Graph_lib::Point{xs(2008), ys(0)}, Graph_lib::Point{xs(2008), ys(100)}};
    current_year.set_style(Graph_lib::Line_style::dash);

    Graph_lib::Open_polyline children;
    Graph_lib::Open_polyline adults;
    Graph_lib::Open_polyline aged;

    std::string file_name = "/home/bangoc/git/GPPCPP/Resource/japanese-age-data.txt";
    std::ifstream ifs {file_name};
    if (!ifs)
        throw std::string("can't open " + file_name);

    for (Distribution d; ifs >> d;) {
        if (d.year < base_year || end_year < d.year)
            throw std::string("year out of range");
        if (d.young + d.middle + d.old != 100)
            throw std::string("percentages don't add up");
        const int x = xs(d.year);
        children.add(Graph_lib::Point{x, ys(d.young)});
        adults.add(Graph_lib::Point{x, ys(d.middle)});
        aged.add(Graph_lib::Point{x, ys(d.old)});
    }

    Graph_lib::Text children_label {Graph_lib::Point{20, children.point(0).y}, "age 0-14"};
    children.set_color(Graph_lib::Color::red);
    children_label.set_color(Graph_lib::Color::red);

    Graph_lib::Text adults_label {Graph_lib::Point{20, adults.point(0).y}, "age 15-64"};
    adults.set_color(Graph_lib::Color::blue);
    adults_label.set_color(Graph_lib::Color::blue);

    Graph_lib::Text aged_label{Graph_lib::Point{20, aged.point(0).y}, "age 65+"};
    aged.set_color(Graph_lib::Color::dark_green);
    aged_label.set_color(Graph_lib::Color::dark_green);

    win.attach(children);
    win.attach(adults);
    win.attach(aged);

    win.attach(children_label);
    win.attach(adults_label);
    win.attach(aged_label);

    win.attach(x);
    win.attach(y);
    win.attach(current_year);

    Graph_lib::gui_main();
}