#include <stdio.h>
#include <iostream>
#include <conio.h>

class Complex
{
    double real;
    double img;
public:
    void setReal(double R)
    {
        real = R;
    }
    void setImg(double I)
    {
        img = I;
    }
    double getReal()
    {
        return real;
    }
    double getImg()
    {
        return img;
    }
    void print();
    Complex(double R = 0.0L, double I = 0.0L);
    ~Complex();
};

Complex addComplex(Complex c1, Complex c2);
Complex subtractComplex(Complex c1, Complex c2);

int main(int argc, char const *argv[])
{
    Complex c1;
    c1.setImg(0); c1.setReal(-5);
    Complex c2(8,-5);
    c1.print();
    c2.print();
    addComplex(c1, c2).print();
    subtractComplex(c1, c2).print();
    return 0;
}

void Complex::print()
{
    if (real == 0)
        std::cout << img << "i" << std::endl;
    else if (img == 0)
        std::cout << real << std::endl;
    else
        printf("%.2f%+.2fi\n", real, img);
}

Complex addComplex(Complex c1, Complex c2)
{
    Complex result;
    result.setReal(c1.getReal() + c2.getReal());
    result.setImg(c1.getImg() + c2.getImg());
    return result;
}

Complex subtractComplex(Complex c1, Complex c2)
{
    Complex result;
    result.setReal(c1.getReal() - c2.getReal());
    result.setImg(c1.getImg() - c2.getImg());
    return result;
}

Complex::Complex(double R, double I)
{
    real = R; img = I;
    printf("The constructor of %.2f%+.2fi\n", real, img);
    getch();
}

Complex::~Complex()
{
    if (real == 0)
        std::cout << "this is the destructor of " << img << "i" << std::endl;
    else if (img == 0)
        std::cout << "this is the destructor of " << real << std::endl;
    else
        printf("this is the destructor of %.2f%+.2fi\n", real, img);
    getch();
}