//
// Created by bangoc on 03/09/2017.
//

#include "Simple_window.h" // get access to our window library
#include "Graph.h" // get access to our graphics library facilities
int main()
{
    Graph_lib::Point tl {100,100};  // to become top left corner of window
    Simple_window win {tl,600,400,"Canvas"};  // make a simple window

    Graph_lib::Axis xa{Graph_lib::Axis::x, Graph_lib::Point{20, 300}, 280, 10, "x axis"};
    win.attach(xa);

    Graph_lib::Axis ya{Graph_lib::Axis::y, Graph_lib::Point{20, 300}, 280, 10, "y axis"};
    win.attach(ya);

    Graph_lib::Function sine{sin, 0, 100, Graph_lib::Point{20, 150}, 1000, 50, 50};
    win.attach(sine);
    win.set_label("Plot a function");

    win.wait_for_button(); // give control to the display engine
}