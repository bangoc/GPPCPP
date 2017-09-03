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

    // Draw sin function
    Axis xa{Axis::x, Point{20, 300}, 280, 10, "x axis"};
    win.attach(xa);
    Axis ya{Axis::y, Point{20, 300}, 280, 10, "y axis"};
    win.attach(ya);
    Function sine{sin, 0, 100, Point{20, 150}, 1000, 50, 50};
    win.attach(sine);
    win.set_label("Chapter 12 drawing example");

    // Draw a planet model
    Circle c{Point{100, 200}, 50};
    Ellipse e{Point{100, 200}, 75, 25};
    e.set_color(Color::dark_red);
    c.set_color(Color::dark_blue);
    Mark m{Point{100, 200}, 'x'};

    // Draw a red triangle
    Polygon poly;
    poly.add(Point{300, 200});
    poly.add(Point{350, 100});
    poly.add(Point{400, 200});
    poly.set_color(Color::red);
    poly.set_style(Line_style(Line_style::dash, 4));
    win.attach(poly);

    // Draw a filled rectangle
    Rectangle r{Point{200, 200}, 100, 50};
    r.set_fill_color(Color::yellow);
    win.attach(r);

    // Draw a polyline and fill it green
    Closed_polyline poly_rect;
    poly_rect.add(Point{100, 50});
    poly_rect.add(Point{200, 50});
    poly_rect.add(Point{200, 100});
    poly_rect.add(Point{100, 100});
    poly_rect.add(Point{50, 75});

    poly_rect.set_style(Line_style(Line_style::dash, 2));
    poly_rect.set_fill_color(Color::green);
    win.attach(poly_rect);

    // Write some text about sizes
    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max()
        << "; window size: " << win.x_max() << "*" << win.y_max();
    Text sizes{Point{100, 20}, oss.str()};

    // Load some picture in gif format
    // * You need to fix these path then
    Image ii {Point{225, 225}, "/home/bangoc/git/GPPCPP/Resource/image.gif"};

    Image cal{Point{225, 225}, "/home/bangoc/git/GPPCPP/Resource/snow_cpp.gif"};
    cal.set_mask(Point{40, 40}, 200, 150);

    win.attach(c);
    win.attach(e);
    win.attach(m);

    win.attach(sizes);
    win.attach(ii);
    win.attach(cal);

    win.wait_for_button(); // give control to the display engine
}