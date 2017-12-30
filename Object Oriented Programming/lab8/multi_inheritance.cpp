#include <iostream>

using std::cout;
using std::initializer_list;
using std::endl;

#define M_PI 3.14159265358979323846

class Geoshape
{
    protected: float dim1, dim2;
    public:
        Geoshape(float f1 = 0, float f2 = 0)
        {dim1 = f1, dim2  = f2;}
        virtual void setDim1(float f1){dim1 = f1;}
        virtual void setDim2(float f2){dim2 = f2;}
        float getDim1(){return dim1;}
        float getDim2(){return dim2;}
        virtual float calculateArea() = 0;
};

class Circle: public Geoshape
{
    public:
        Circle(float r = 0): Geoshape(r, r)
        {}
        float calculateArea(){return M_PI * dim1 * dim2;}
        void setRadius(float r){dim1 = dim2 = r;}
        void setDim1(float r){setRadius(r);}
        void setDim2(float r){setRadius(r);}
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

class Square: public Rectangle
{
    public:
        Square(float l = 0): Rectangle(l, l)
        {}
        float calculateArea(){return dim1 * dim2;}
        void setLength(float l){dim1 = dim2 = l;}
        void setDim1(float l){setLength(l);}
        void setDim2(float l){setLength(l);}
};

float sumArea(initializer_list<Geoshape *> lst);

int main(int argc, char const *argv[])
{
    Circle c1(5);
    Circle c2(10);
    Triangle t1(5, 10);
    Triangle t2(5, 8);
    Rectangle r1(7, 8);
    Rectangle r2(9, 14);
    Square s1(7);
    Square s2(7);

    cout << sumArea({&c1, &c2, &t1, &t2, &r1, &r2, &s1, &s2}) << endl;
    return 0;
}

float sumArea(initializer_list<Geoshape *> lst)
{
    int size = lst.size();
    float sum = 0;
    for (int i = 0; i < size; i++)
        sum += lst.begin()[i]->calculateArea();
    return sum;
}