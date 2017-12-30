#include <stdio.h>
#include <iostream>

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
    void print()
    {
        if (real == 0)
            std::cout << img << "i" << std::endl;
        else if (img == 0)
            std::cout << real << std::endl;
        else
            printf("%.2f%+.2fi\n", real, img);
    }
};

Complex addComplex(Complex c1, Complex c2);
Complex subtractComplex(Complex c1, Complex c2);

int main(int argc, char const *argv[])
{
    Complex c1, c2;
    c1.setImg(0); c1.setReal(-5);
    c2.setImg(8); c2.setReal(+5);
    c1.print();
    c2.print();
    addComplex(c1, c2).print();
    subtractComplex(c1, c2).print();
    return 0;
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
