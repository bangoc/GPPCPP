//
// Created by bangoc on 03/09/2017.
//

#include <sstream>
#include "Simple_window.h" // get access to our window library
#include "Graph.h" // get access to our graphics library facilities
int main()
{
    Graph_lib::Point tl {100,100};  // to become top left corner of window
    Simple_window win {tl,600,400,"Canvas"};  // make a simple window

    // Draw sin function
    Graph_lib::Axis xa{Graph_lib::Axis::x, Graph_lib::Point{20, 300}, 280, 10, "x axis"};
    win.attach(xa);
    Graph_lib::Axis ya{Graph_lib::Axis::y, Graph_lib::Point{20, 300}, 280, 10, "y axis"};
    win.attach(ya);
    Graph_lib::Function sine{sin, 0, 100, Graph_lib::Point{20, 150}, 1000, 50, 50};
    win.attach(sine);
    win.set_label("Chapter 12 drawing example");

    // Draw a planet model
    Graph_lib::Circle c{Graph_lib::Point{100, 200}, 50};
    Graph_lib::Ellipse e{Graph_lib::Point{100, 200}, 75, 25};
    e.set_color(Graph_lib::Color::dark_red);
    c.set_color(Graph_lib::Color::dark_blue);
    Graph_lib::Mark m{Graph_lib::Point{100, 200}, 'x'};

    // Draw a red triangle
    Graph_lib::Polygon poly;
    poly.add(Graph_lib::Point{300, 200});
    poly.add(Graph_lib::Point{350, 100});
    poly.add(Graph_lib::Point{400, 200});
    poly.set_color(Graph_lib::Color::red);
    poly.set_style(Graph_lib::Line_style(Graph_lib::Line_style::dash, 4));
    win.attach(poly);

    // Draw a filled rectangle
    Graph_lib::Rectangle r{Graph_lib::Point{200, 200}, 100, 50};
    r.set_fill_color(Graph_lib::Color::yellow);
    win.attach(r);

    // Draw a polyline and fill it green
    Graph_lib::Closed_polyline poly_rect;
    poly_rect.add(Graph_lib::Point{100, 50});
    poly_rect.add(Graph_lib::Point{200, 50});
    poly_rect.add(Graph_lib::Point{200, 100});
    poly_rect.add(Graph_lib::Point{100, 100});
    poly_rect.add(Graph_lib::Point{50, 75});

    poly_rect.set_style(Graph_lib::Line_style(Graph_lib::Line_style::dash, 2));
    poly_rect.set_fill_color(Graph_lib::Color::green);
    win.attach(poly_rect);

    // Write some text about sizes
    std::ostringstream oss;
    oss << "screen size: " << Graph_lib::x_max() << "*" << Graph_lib::y_max()
        << "; window size: " << win.x_max() << "*" << win.y_max();
    Graph_lib::Text sizes{Graph_lib::Point{100, 20}, oss.str()};

    // Load some picture in gif format
    // * You need to fix these path then
    Graph_lib::Image ii {Graph_lib::Point{225, 225}, "/home/bangoc/git/GPPCPP/Resource/image.gif"};

    Graph_lib::Image cal{Graph_lib::Point{225, 225}, "/home/bangoc/git/GPPCPP/Resource/snow_cpp.gif"};
    cal.set_mask(Graph_lib::Point{40, 40}, 200, 150);

    win.attach(c);
    win.attach(e);
    win.attach(m);

    win.attach(sizes);
    win.attach(ii);
    win.attach(cal);

    win.wait_for_button(); // give control to the display engine
}