#include <iostream>
#include <conio.h>

#define SIZE 5

class Stack
{
    // class attributes
    static int counter;
    // object attributes
    int tos;
    int size;
    int * stk;
public:
    // class member functions (class function)
    static int getCounter();
    // object member functions
    int getSize()
    {
        return size;
    }
    void push(int n);
    int pop();
    Stack(int z = SIZE);
    ~Stack();
};
int Stack::counter = 0;

int main(int argc, char const *argv[])
{
    Stack s1;

    Stack s2(10);
    int s2_size = s2.getSize();
    for (int i = 0; i < SIZE; i++)
    {
        s1.push(i);
    }
    for (int i = 0; i < s2_size; i++)
    {
        s2.push(i);
    }
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << s1.pop() << std::endl;
    }
    for (int i = 0; i < s2_size; i++)
    {
        std::cout << s2.pop() << std::endl;
    }

    std::cout << "number of objects is " << Stack::getCounter() << std::endl;
    std::cout << "number of objects is " << s1.getCounter() << std::endl;
    return 0;
}

int Stack::getCounter()
{
    return counter;
}

void Stack::push(int n)
{
    if (tos == size)
        std::cout << "stack is full." << std::endl;
    else
    {
        stk[tos] = n;
        tos++;
    }
}

int Stack::pop()
{
    int result = -1;
    if (tos == 0)
        std::cout << "Stack is empty." << std::endl;
    else
    {
        tos--;
        result = stk[tos];
    }
    return result;
}

Stack::Stack(int z)
{
    tos = 0;
    size = z;
    stk = new int [size];
    counter++;
    std::cout << "this is the constructor of stack of size " << size << "." << std::endl;
    getch();
}

Stack::~Stack()
{
    // destructor
    std::cout << "this is the destructor of stack of size " << size << "." << std::endl;
    delete [] stk;
    getch();
    counter--;
}
