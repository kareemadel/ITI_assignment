#include <iostream>
#include <conio.h>

#define SIZE 5

class Stack
{
    int tos;
    int stk[SIZE];
public:
    void push(int n);
    int pop();
    Stack();    // constructor
    int getTos()
    {
        return tos;
    }
    friend void ViewContent(Stack stack);
};

int main(int argc, char const *argv[])
{
    Stack s1;
    Stack s2;
    s1.push(7);
    s1.push(8);
    s2.push(3);
    s2.push(30);
    std::cout << s1.pop() << std::endl;
    std::cout << s1.pop() << std::endl;
    std::cout << s2.pop() << std::endl;
    std::cout << s2.pop() << std::endl;
    return 0;
}


void Stack::push(int n)
{
    if (tos == SIZE)
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

Stack::Stack()
{
    tos = 0;
}

void ViewContent(Stack stack)
{
    int i;
    for (i = 0; i < stack.tos; i++)
    {
        std::cout << stack.stk[i] << std::endl;
    }
}