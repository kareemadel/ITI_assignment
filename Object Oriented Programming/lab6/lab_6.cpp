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

class picture{

    int circle_count,line_count,rectangle_count;
    circ *circle_pointer;
    rectang *rectangle_pointer;
    Line *line_pointer;
public:
    picture()
    {
        circle_count = 0;
        line_count = 0;
        rectangle_count = 0;
        circle_pointer = NULL;
        rectangle_pointer = NULL;
        line_pointer = NULL;
    }
    picture(int circle_count_0, int rectangle_count_0, int line_count_0, circ *circle_pointer_0, rectang *rectangle_pointer_0, Line *line_pointer_0)
    {
        circle_count = circle_count_0;
        rectangle_count = rectangle_count_0;
        line_count = line_count_0;
        circle_pointer = circle_pointer_0;
        rectangle_pointer = rectangle_pointer_0;
        line_pointer = line_pointer_0;

    }
    void paint()
    {

        for (int i  =  0; i < circle_count; ++i)
        {
            circle_pointer[i].draw();
        }
        for (int i  =  0; i < rectangle_count; ++i)
        {
            rectangle_pointer[i].draw();
        }
        for (int i  =  0; i < line_count; ++i)
        {
            line_pointer[i].draw();
        }
    }
    void setCircles(int circle_count_0, circ *circle_pointer_0)
    {
        circle_count  =  circle_count_0;
        circle_pointer  =  circle_pointer_0;
    }
    void setRect(int rectangle_count_0, rectang *rectangle_pointer_0)
    {
        rectangle_count  =  rectangle_count_0;
        rectangle_pointer  =  rectangle_pointer_0;
    }
    void setLine(int line_count_0, Line *line_pointer_0)
    {
        line_count  =  line_count_0;
        line_pointer  =  line_pointer_0;
    }
};

int main(int argc, char const *argv[])
{
    initgraph();
    circ *cicle_1  =  new circ (100,70,100);
    rectang *rectangle_1  =  new rectang (150, 150, 300, 300);
    picture picture_1(1,1,0,cicle_1,rectangle_1,NULL);
    picture_1.paint();
    circ *c3  =  new circ (70,70,150);
    picture_1.setCircles(1, c3);
    return 0;
}