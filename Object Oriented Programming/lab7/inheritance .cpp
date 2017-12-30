#include <iostream>
using std::cout;


class Base
{
    // only the class and children can access its attribute
    protected: int a, b;
    public:
        Base (int x = 0, int y = 0)
        {
            a = x; b = y;
        }
        void setA(int x){a = x;}
        void setB(int y){b = y;}
        int getA(){return a;}
        int getB(){return b;}
        int calculateSum(){return a + b;}
};


class Derived: public Base
{
    int c;
    public:
        Derived(int x1 = 0, int y1 = 0, int z1 = 0): Base(x1, y1)
        {c = z1;}
        void setC(int z1){c = z1;}
        int getC(){return c;}
        // int calculateSum(){return a + b + c;}
        int calculateSum(){return Base::calculateSum() + c;}
};

int main(int argc, char const *argv[])
{
    Derived obj1;
    Derived obj2(3, 2, 7);
    Base b1(7, 8);
    obj2.calculateSum();
    obj2.Base::calculateSum();
    return 0;
}