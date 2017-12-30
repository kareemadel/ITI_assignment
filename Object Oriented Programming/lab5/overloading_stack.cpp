#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define SIZE 5

template <class T> class Stack;
template <class T> void ViewContent(Stack <T> s);

template <class T>
class Stack
{
    // object attributes
    int tos, size;
    T * stk;
    // class member functions (class function)
    static int counter;
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
        void push(T n);
        T pop();
        Stack(int s = SIZE);
        ~Stack();
        Stack(Stack & s);
        friend void ViewContent(Stack s);
        Stack & operator=(Stack & s);
};
template <class T>
int Stack<T>::counter = 0;

template <class T>
void initialize_stack(Stack <T> &s, int size);

int main(int argc, char const *argv[])
{
    Stack <char> s1(5);
    s1.push('k');
    ViewContent(s1);
}


template <class T>
void initialize_stack(Stack <T> &s, int size)
{
    // fill the stack with random integers \in [1..100]
    for (int i = 0; i < size; i++)
    {
        s.push(rand() % 100 + 1);
    }
}

template <class T>
void Stack <T>::push(T n)
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

template <class T>
T Stack <T>::pop()
{
    // pop an element from the stack
    T result = -1;
    if (tos == 0)
        std::cout << "Stack is empty." << std::endl;
    else
    {
        tos--;
        result = stk[tos];
    }
    return result;
}

template <class T>
Stack <T>::Stack(int z)
{
    // overloaded constructor, with deafault argument SIZE
    tos = 0;
    size = z;
    stk = new T [size];
    counter++;
    std::cout << "this is the constructor of stack of size " << size << "." << std::endl;
    getch();
}

template <class T>
Stack <T>::~Stack()
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

template <class T>
void viewContent(Stack <T> s)
{
    // friend function to view the stack
    int size = s.tos;
    for (int i = 0; i < size; i++)
        std::cout << s.stk[i] << std::endl;
}

template <class T>
Stack <T>::Stack(Stack <T> &s)
{
    // copy constructor
    size = s.size;
    std::cout << "This the copy constructor of stack of size " << size << "." << std::endl;
    getch();
    tos = 0;
    stk = new T [size];
    for (int i = 0; i < s.tos; i++)
        push(s.stk[i]);
    counter++;
}

template <class T>
Stack <T> &Stack <T>::operator=(Stack <T> &s)
{
    std::cout << "This is =" << std::endl;
    delete [] stk;
    tos = s.tos;
    size = s.size;
    stk = new T [size];
    return *this;
}