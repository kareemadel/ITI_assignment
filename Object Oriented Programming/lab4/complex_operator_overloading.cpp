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
    // ~Complex();
    Complex operator +(Complex z);
    Complex operator+(double num);
    friend  Complex operator+(double num, Complex z);
    Complex & operator-(const Complex & z);
    Complex operator=(Complex z);
    Complex operator+=(Complex z);
    Complex operator-=(Complex z);
    bool operator==(Complex z);
    Complex operator++();
    Complex operator++(int );
    Complex operator--();
    Complex operator--(int );
    bool operator>(Complex z);
    bool operator<(Complex z);
};

Complex addComplex(Complex c1, Complex c2);
Complex subtractComplex(Complex c1, Complex c2);

int main(int argc, char const *argv[])
{
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex temp;
    if (c2 > c1)
        printf("c2 > c1\n");
    temp = c1;
    std::cout << "c1 is "; c1.print();
    std::cout << "c2 is "; c2.print();
    std::cout << "c1 + c2 is "; (c1 + c2).print();
    std::cout << "c1 + 5 is "; (c1 + 5).print();
    std::cout << "5 + c2 is "; (5 + c2).print();
    std::cout << "c1 - c2 is "; (c1 -c2).print();
    std::cout << "temp is "; temp.print();
    std::cout << "afer temp += c1, temp is "; temp += c1, temp.print();
    std::cout << "afer temp -= c1, temp is "; temp -= c1, temp.print();
    if (c1 == c1)
        std::cout << "equal itself" << std::endl;
    std::cout << "c1++.print()"; (c1++).print();
    std::cout << "now c1 is"; c1.print();
    std::cout << "++c1.print()"; (++c1).print();
    std::cout << "now c1 is"; c1.print();

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



Complex Complex::operator+(Complex z)
{
    Complex result(real + z.real, img + z.img);
    return result;
}


Complex Complex::operator+(double num)
{
    Complex result(real + num, img);
    return result;
}

Complex operator+(double num, Complex z)
{
    Complex result(z.real + num, z.img);
    return result;
}


Complex& Complex::operator-(const Complex &z)
{
    Complex result(real - z.real, img - z.img);
    return result;
}


Complex Complex::operator=(Complex z)
{
    real = z.real; img = z.img;
    return *this;
}

Complex Complex::operator+=(Complex z)
{
    real += z.real; img += z.img;
    return *this;
}

Complex Complex::operator-=(Complex z)
{
    real -= z.real; img -= z.img;
    return *this;
}

bool Complex::operator==(Complex z)
{
    return real == z.real && img == z.img;
}

// prefix
Complex Complex::operator++()
{
    real++;
    return *this;
}

Complex Complex::operator++(int )
{
    Complex old(real, img);
    real++;
    return old;
}

Complex Complex::operator--()
{
    real++;
    return *this;
}

Complex Complex::operator--(int )
{
    Complex old(real, img);
    real++;
    return old;
}

bool Complex::operator>(Complex z)
{
    return (real > z.real || (real == real && img > z.img));
}

bool Complex::operator<(Complex z)
{
    return (real < z.real || (real == real && img < z.img));
}

Complex::Complex(double R, double I)
{
    real = R; img = I;
    // printf("The constructor of %.2f%+.2fi\n", real, img);
    // getch();
}

// Complex::~Complex()
// {
//     if (real == 0)
//         std::cout << "this is the destructor of " << img << "i" << std::endl;
//     else if (img == 0)
//         std::cout << "this is the destructor of " << real << std::endl;
//     else
//         printf("this is the destructor of %.2f%+.2fi\n", real, img);
//     getch();
// }