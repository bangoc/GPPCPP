//
// Created by bangoc on 10/09/2017.
//

#include "Simple_window.h"

int main() {
    Simple_window win {Point{100, 100}, 600, 400, "16 * 16 Color matrix"};
    Vector_ref<Rectangle> vr;
    for (int i = 0; i < 16; ++i)
        for (int j = 0; j < 16; ++j) {
            vr.push_back(new Rectangle{Point{i*20, j*20}, 20, 20});
            vr[vr.size() - 1].set_fill_color(Color{i*16 + j});
            win.attach(vr[vr.size() - 1]);
        }
    win.wait_for_button();
}