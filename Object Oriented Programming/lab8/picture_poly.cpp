#include <iostream>
#include "graphics.h"

class Shape
{
    public:
        virtual void draw() = 0;
};

class Point
{
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

class Circle: public Shape
{
    int radius; Point center;
    public:
        Circle(int rad  =  1, int x  =  1, int y  =  1)
        {
            radius  =  rad;
            center.setx(x);
            center.sety(y);
        }
        void draw(){
            circle(center.getx(), center.gety(), radius);
        }
};

class Rectangle: public Shape
{
    Point Upper_corner;
    Point Lower_corner;
    public:
        Rectangle(int uc_x = 50, int uc_y = 50, int lc_x = 100, int lc_y  =  100) : Upper_corner(uc_x,uc_y), Lower_corner(lc_x,lc_y)
        {}

        void draw()
        {
            rectangle(Upper_corner.getx(), Upper_corner.gety(), Lower_corner.getx(), Lower_corner.gety());
        }
};

class Line: public Shape
{
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

    int shape_count;
    Shape ** shape_ptr;
    public:
        picture(Shape ** shape_ptr_0 = NULL, int shape_count_0 = 0)
        {
            shape_count = shape_count_0;
            shape_ptr = shape_ptr_0;
        }
        void paint()
        {
            for (int i = 0; i < shape_count; i++)
                shape_ptr[i]->draw();
        }
        void setShapes(int shape_count_0, Shape ** shape_ptr_0)
        {
            shape_count = shape_count_0;
            shape_ptr = shape_ptr_0;
        }
};

int main(int argc, char const *argv[])
{
    initgraph();
    Shape ** shapes = new Shape * [5];
    shapes[0]  =  new Circle (100,500,500);
    shapes[1]  =  new class Rectangle (150, 150, 300, 300);
    shapes[2] = new Line(5, 5, 50, 50);
    shapes[3] = new Circle (60,300,300);
    shapes[4] = new Line(5, 5, 100, 150);
    picture picture_1(shapes, 5);
    picture_1.paint();
    return 0;
}