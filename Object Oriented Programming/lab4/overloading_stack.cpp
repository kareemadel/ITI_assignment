#include <iostream>
#include <conio.h>
// #include <curses.h>
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
    static int getCounter()
    {
        return counter;
    }
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
    Stack &operator=(Stack &s);
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
    s1.pop(); s2.pop();

    s1 = s2;
    s1.push(9999);
    std::cout << s2.pop() << std::endl;

    // viewContent(s1);

    std::cout << "number of objects is " << Stack::getCounter() << std::endl;
    return 0;
}

void initialize_stack(Stack &s, int size)
{
    // fill the stack with random integers \in [1..100]
    for (int i = 0; i < size; i++)
    {
        s.push(rand() % 100 + 1);
    }
}

void Stack::push(int n)
{
    // push an element to the stack
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
    // pop an element from the stack
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
    // overloaded constructor, with deafault argument SIZE
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
    // note
    std::cout << "this is the destructor of stack of size " << size << "." << std::endl;
    // zero the the variables
    for (int i = 0; i < size; i++)
        stk[i]=0;
    tos = 0;
    size = 0;
    // free the memory
    delete [] stk;
    getch();
    counter--;
}

void viewContent(Stack s)
{
    // friend function to view the stack
    int size = s.tos;
    for (int i = 0; i < size; i++)
        std::cout << s.stk[i] << std::endl;
}

void popViewVal(Stack s, int filled_size)
{
    // standalone function to view the stack
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
    // copy constructor
    size = s.size;
    std::cout << "This the copy constructor of stack of size " << size << "." << std::endl;
    getch();
    tos = 0;
    stk = new int [size];
    for (int i = 0; i < s.tos; i++)
        push(s.stk[i]);
    counter++;
}

Stack &Stack::operator=(Stack &s)
{
    std::cout << "This is =" << std::endl;
    delete [] stk;
    tos = s.tos;
    size = s.size;
    stk = new int [size];
    return *this;
}