#include <iostream>
using std::cout;

#define M_PI 3.14159265358979323846

class Geoshape
{
    protected: float dim1, dim2;
    public:
        Geoshape(float f1 = 0, float f2 = 0)
        {dim1 = f1, dim2  = f2;}
        void setDim1(float f1){dim1 = f1;}
        void setDim2(float f2){dim2 = f2;}
        float getDim1(){return dim1;}
        float getDim2(){return dim2;}
        float calculateArea(){return 0.0;}
};

class Circle: protected Geoshape
{
    public:
        Circle(float r = 0): Geoshape(r, r)
        {}
        float calculateArea(){return M_PI * dim1 * dim2;}
        void setRadius(float r){dim1 = dim2 = r;}
        float getRadius(){return dim1;}
};

class Triangle: public Geoshape
{
    public:
        Triangle(float b = 0, float h = 0): Geoshape(b, h)
        {}
        float calculateArea(){return 0.5 * dim1 * dim2;}
};

class Rectangle: public Geoshape
{
    public:
        Rectangle(float l = 0, float w = 0): Geoshape(l, w)
        {}
        float calculateArea(){return dim1 * dim2;}
};

class Square: protected Rectangle
{
    public:
        Square(float l = 0): Rectangle(l, l)
        {}
        float calculateArea(){return dim1 * dim2;}
        void setLength(float l){dim1 = dim2 = l;}
};

int main(int argc, char const *argv[])
{
    Circle c1(5);
    c1.calculateArea();
    // c1.Geoshape::setDim1(7);
    // c1.setDim1(7);
    // c1.setDim2(8);
    c1.setRadius(7);
    c1.calculateArea();

    Triangle t(3, 4);
    t.calculateArea();

    Rectangle r1(2, 3);
    // r1.setDim1(4);
    // r1.setDim2(5);

    Square s1(5);
    s1.calculateArea();
    // s1.setDim1(3);
    // s1.setDim2(2);
    return 0;
}