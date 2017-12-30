#include <iostream>
#include "graphics.h"

class Point{
    int x;
    int y;
public:

    Point(int x0  =  0, int y0  =  0)
    {
        x  =  x0; y  =  y0;
    }
    void setx(int x0)
    {
        x  =  x0;
    }
    void sety(int y0)
    {
        y  =  y0;
    }
    int getx()
    {
        return x;
    }
    int gety()
    {
        return y;
    }

};

class circ{
    int radius; Point center;
public:
    circ(int rad  =  1, int x  =  1, int y  =  1)
    {
        radius  =  rad;
        center.setx(x);
        center.sety(y);
    }
    void draw(){
        circle(center.getx(), center.gety(), radius);
    }
};

class rectang{
    Point Upper_corner;
    Point Lower_corner;
public:
    rectang(int uc_x = 50, int uc_y = 50, int lc_x = 100, int lc_y  =  100) : Upper_corner(uc_x,uc_y), Lower_corner(lc_x,lc_y)
    {}

    void draw()
    {
        rectangle(Upper_corner.getx(), Upper_corner.gety(), Lower_corner.getx(), Lower_corner.gety());
    }
};

class Line{
    Point p1;
    Point p2;
public:
    Line(int p1_x = 0, int p1_y = 0, int p2_x = 2, int p2_y = 2)
    {
        p1.setx(p1_x);
        p1.sety(p1_y);
        p2.setx(p2_x);
        p2.sety(p2_y);
    }
    void draw()
    {
        line(p1.getx(), p1.gety(), p2.getx(), p2.gety());
    }
};

int main(int argc, char const *argv[])
{
    initgraph();
    circ circle_1(100,70,100);
    circle_1.draw();
    circ circle_2(50,50,70);
    circle_2.draw();
    rectang rectangle(150, 150, 300, 300);
    rectangle.draw();
    return 0;
}