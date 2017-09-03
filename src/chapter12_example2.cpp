//
// Created by bangoc on 03/09/2017.
//

#include "Simple_window.h" // get access to our window library
#include "Graph.h" // get access to our graphics library facilities
int main()
{
    using namespace Graph_lib;  // our graphics facilities are in Graph_lib
    Point tl {100,100};  // to become top left corner of window
    Simple_window win {tl,600,400,"Canvas"};  // make a simple window

    Axis xa{Axis::x, Point{20, 300}, 280, 10, "x axis"};
    win.attach(xa);

    Axis ya{Axis::y, Point{20, 300}, 280, 10, "y axis"};
    win.attach(ya);

    Function sine{sin, 0, 100, Point{20, 150}, 1000, 50, 50};
    win.attach(sine);
    win.set_label("Plot a function");

    win.wait_for_button(); // give control to the display engine
}