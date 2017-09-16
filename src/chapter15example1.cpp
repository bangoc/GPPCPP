//
// Created by bangoc on 03/09/2017.
//

#include "Simple_window.h"
#include "GUI.h"

double one(double) {return 1;}
double slope(double x) {return x/2;}
double square(double x) {return x * x;}
double sloping_cos(double x) { return cos(x) + slope(x); }

int main() {
    constexpr int xmax = 600;
    constexpr int ymax = 400;

    constexpr int x_orig = xmax/2;
    constexpr int y_orig = ymax/2;
    Graph_lib::Point orig {x_orig, y_orig};

    constexpr int r_min = -10;
    constexpr int r_max = 11;

    constexpr int n_points = 400;

    constexpr int x_scale = 30;
    constexpr int y_scale = 30;

    Simple_window win {Graph_lib::Point{100, 100}, xmax, ymax, "Function graphing"};

    Graph_lib::Function s {one, r_min, r_max, orig, n_points, x_scale, y_scale};
    Graph_lib::Function s2 {slope, r_min, r_max, orig, n_points, x_scale, y_scale};
    Graph_lib::Function s3 {square, r_min, r_max, orig, n_points, x_scale, y_scale};

    win.attach(s);
    win.attach(s2);
    win.attach(s3);

    // Function labels
    Graph_lib::Text ts {Graph_lib::Point{100, y_orig - 40}, "one"};
    Graph_lib::Text ts2 {Graph_lib::Point{100, y_orig + y_orig/2 -20}, "x/2"};
    Graph_lib::Text ts3 {Graph_lib::Point{x_orig - 100, 20}, "x*x"};

    win.attach(ts);
    win.attach(ts2);
    win.attach(ts3);

    constexpr int xlength = xmax - 40;
    constexpr int ylength = ymax - 40;

    Graph_lib::Axis x {Graph_lib::Axis::x, Graph_lib::Point{20, y_orig}, xlength, xlength/x_scale, "one notch == 1"};
    Graph_lib::Axis y {Graph_lib::Axis::y, Graph_lib::Point{x_orig, ylength + 20}, ylength, ylength / y_scale, "one notch == 1"};

    x.set_color(Graph_lib::Color::red);
    y.set_color(Graph_lib::Color::red);

    win.attach(x);
    win.attach(y);

    Graph_lib::Function s4 {cos, r_min, r_max, orig, 400, 30, 30};
    s4.set_color(Graph_lib::Color::blue);
    Graph_lib::Function s5 {sloping_cos, r_min, r_max, orig, 400, 30, 30};
    x.label.move(-160, 0);
    x.notches.set_color(Graph_lib::Color::dark_red);

    win.attach(s4);
    win.attach(s5);

    Graph_lib::Function f1 {log, 0.000001, r_max, orig, 200, 30, 30};
    Graph_lib::Function f2 {sin, r_min, r_max, orig, 200, 30, 30};
    f2.set_color(Graph_lib::Color::blue);
    Graph_lib::Function f3 {cos, r_min, r_max, orig, 200, 30, 30};
    Graph_lib::Function f4 {exp, r_min, r_max, orig, 13, x_scale, y_scale};
    f4.set_color(Graph_lib::Color::green);

    win.attach(f1);
    win.attach(f2);
    win.attach(f3);
    win.attach(f4);
    win.wait_for_button();
}