#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

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
    int getSTos()
    {
        return tos;
    }
    void emptyStack()
    {
        tos = 0;
    }
    void push(int n);
    int pop();
    void popAll()
    {
        int filled_size = tos;
        for (int i = 0; i < filled_size; i++)
            std::cout << pop() << std::endl;
    }
    Stack(int z = SIZE);
    ~Stack();
    Stack(Stack &s);
    friend void viewContent(Stack s);
};
int Stack::counter = 0;

void initialize_stack(Stack &s, int size);
void popViewVal(Stack s, int filled_size);
void popViewRef(Stack &s, int filled_size);

int main(int argc, char const *argv[])
{
    // initialize the stack
    srand(time(NULL));
    Stack s1;
    Stack s2(2000);
    initialize_stack(s1, SIZE);
    initialize_stack(s2, s2.getSize());

    int n = 3;
    switch (n)
    {
    case 1:
        viewContent(s2);
        s2.popAll();
        break;
    case 2:
        popViewRef(s2, s2.getSTos());
        std::cout << "now what's in the stack?" << std::endl;
        s2.pop();
        break;
    case 3:
        // popViewVal(s1, s1.getSTos());
        popViewVal(s2, s2.getSTos());
        break;
    case 4:
        popViewRef(s2, s2.getSTos());
        std::cout << "now what's in the stack?" << std::endl;
        s2.popAll();
        break;
    }
    std::cout << "number of objects is " << Stack::getCounter() << std::endl;
    return 0;
}

void initialize_stack(Stack &s, int size)
{
    for (int i = 0; i < size; i++)
    {
        s.push(rand() % 100 + 1);
    }
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
    for (int i = 0; i < size; i++)
        stk[i]=0;
    tos = 0;
    delete [] stk;
    getch();
    counter--;
}

void viewContent(Stack s)
{
    int size = s.tos;
    for (int i = 0; i < size; i++)
        std::cout << s.stk[i] << std::endl;
}

void popViewVal(Stack s, int filled_size)
{
    for (int i = 0; i < filled_size; i++)
    {
        std::cout << s.pop() << std::endl;
    }
}


void popViewRef(Stack &s, int filled_size)
{
    for (int i = 0; i < filled_size; i++)
    {
        std::cout << s.pop() << std::endl;
    }
}

Stack::Stack(Stack &s)
{
    size = s.size;
    std::cout << "This the copy constructor of stack of size " << size << "." << std::endl;
    tos = 0;
    stk = new int [size];
    for (int i = 0; i < s.tos; i++)
        push(s.stk[i]);
    counter++;
}
