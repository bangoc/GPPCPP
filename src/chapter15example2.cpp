//
// Created by bangoc on 04/09/2017.
//

#include <sstream>
#include <string>
#include "Simple_window.h"
#include "GUI.h"

int fac(int n) {
    int r = 1;
    while (n > 1) {
        r *= n;
        --n;
    }
    return r;
}

double term(double x, int n) { return pow(x, n)/fac(n);}

double expe(double x, int n) {
    double sum = 0;
    for (int i = 0; i < n; ++i)
        sum += term(x, i);
    return sum;
}

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

    Graph_lib::Function real_exp {exp, r_min, r_max, orig, 200, x_scale, y_scale};
    real_exp.set_color(Graph_lib::Color::blue);

    Simple_window win {Graph_lib::Point{100, 100}, xmax, ymax, "Approximation"};

    constexpr int xlength = xmax - 40;
    constexpr int ylength = ymax - 40;

    Graph_lib::Axis x {Graph_lib::Axis::x, Graph_lib::Point{20, y_orig}, xlength, xlength/x_scale, "one notch == 1"};
    Graph_lib::Axis y {Graph_lib::Axis::y, Graph_lib::Point{x_orig, ylength + 20}, ylength, ylength / y_scale, "one notch == 1"};

    x.set_color(Graph_lib::Color::red);
    y.set_color(Graph_lib::Color::red);

    win.attach(x);
    win.attach(y);

    win.attach(real_exp);
    for (int n = 0; n < 50; ++n) {
        std::ostringstream ss;
        ss << "exp approximation; n== " << n;
        std::string title = ss.str();
        win.copy_label(title.c_str());
        Graph_lib::Function e([n](double x) -> double {return expe(x, n);},
                   r_min, r_max, orig, 200, x_scale, y_scale);
        win.attach(e);
        win.wait_for_button();
        win.detach(e);

    }
}