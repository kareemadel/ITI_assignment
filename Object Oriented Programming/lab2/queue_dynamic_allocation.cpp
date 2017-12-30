#include <iostream>
#include <stdlib.h>
#include <time.h>

#define SIZE 5



class Queue
{
    // class attributes
    static int counter;
    // object attributes
    int rear;
    int size;
    int * queue;
public:
    // class member functions (class function)
    static int getCounter();
    // object member functions
    int getSize()
    {
        return size;
    }
    void enqueue(int n);
    int dequeue();
    void display();
    void bubble_sort();
    void selection_sort();
    void max_heapify(int i, int queue_size);
    void build_max_heap();
    void min_heapify(int i, int queue_size);
    void build_min_heap();
    void heap_sort();
    void insertion_sort();
    Queue(int z = SIZE);
    ~Queue();
};
int Queue::counter = 0;

void swap(int &a, int &b);

int main(int argc, char const *argv[])
{
    srand48(time(NULL));
    Queue q1;
    
    Queue q2(10);
    int q2_size = q2.getSize();
    for (int i = 0; i < SIZE; i++)
    {
        q1.enqueue(i);
    }
    for (int i = q2_size; i > 0; i--)
    {
        q2.enqueue(drand48() * 100);
    }

    std::cout << std::endl << "displaying is the queue of size " << q2.getSize() << std::endl;
    q2.display();
    std::cout << std::endl;

    std::cout << "Bubble Sort" << std::endl;
    q2.bubble_sort();
    q2.display();
    std::cout << std::endl;

    std::cout << "Selection Sort" << std::endl;
    q2.selection_sort();
    q2.display();
    std::cout << std::endl;

    std::cout << "Heap Sort" << std::endl;
    q2.heap_sort();
    q2.display();
    std::cout << std::endl;

    std::cout << "Insertion Sort" << std::endl;
    q2.insertion_sort();
    q2.display();
    std::cout << std::endl;

    std::cout << "number of objects is " << Queue::getCounter() << std::endl;
    return 0;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int Queue::getCounter()
{
    return counter;
}

void Queue::enqueue(int n)
{
    if (rear == size)
        std::cout << "queue is full." << std::endl;
    else
    {
        queue[rear] = n;
        rear++;
    }
}

int Queue::dequeue()
{
    int result = -1;
    if (rear == 0)
        std::cout << "Queue is empty." << std::endl;
    else
    {
        result = queue[0];
        for (int i = 0; i < rear; i++)
        {
            queue[i] = queue[i + 1];
        }
        rear--;

    }
    return result;
}

Queue::Queue(int z)
{
    rear = 0;
    size = z;
    queue = new int [size];
    counter++;
    std::cout << "this is the constructor of queue of size " << size << "." << std::endl;
}

Queue::~Queue()
{
    // destructor
    std::cout << "this is the destructor of queue of size " << size << "." << std::endl;
    delete [] queue;
    counter--;
}

void Queue::display()
{
    for (int i = 0; i < rear; i++)
    {
        std::cout << queue[i] << " ";
    }
    std::cout << std::endl;
}

void Queue::bubble_sort()
{
    bool isSorted = false;
    for (int i = 0; i < rear - 1 && !isSorted; i++)
    {
        isSorted = true;
        for (int j = 0; j < rear - 1 - i; j++)
        {
            if (queue[j] > queue[j + 1])
            {
                swap(queue[j], queue[j + 1]);
                isSorted = false;
            }
        }
    }
}

void Queue::selection_sort()
{
    int min_index;
    for (int i = 0; i < rear; i++)
    {
        min_index = i;
        for (int j = i + 1; j < rear; j++)
        {
            if (queue[min_index] > queue[j])
                min_index = j;
        }
        if (min_index != i)
        {
            swap(queue[i], queue[min_index]);
        }
    }
}


void Queue::max_heapify(int i, int queue_size)
{
    /*
     *  maintain the max heap propertry for node i
    */
    int left_child = 2*i + 1;
    int right_child = 2*i + 2;
    int largest = i;
    if (left_child < queue_size && queue[left_child] > queue[i])
        largest = left_child;
    if (right_child < queue_size && queue[right_child] > queue[largest])
        largest = right_child;
    if (largest != i)
    {
        swap(queue[i], queue[largest]);
        max_heapify(largest, queue_size);
    }
}

void Queue::build_max_heap()
{
    // build a max heap
    for (int i = rear / 2; i > -1; i--)
        max_heapify(i, rear);
}

void Queue::min_heapify(int i, int queue_size)
{
    // maintain the minimum heap property for node i
    int left_child = 2*i + 1;
    int right_child = 2*i + 2;
    int smallest = i;
    if (left_child < queue_size && queue[left_child] < queue[smallest])
        smallest = left_child;
    if (right_child < queue_size && queue[right_child] < queue[smallest])
        smallest = right_child;
    if (smallest != i)
    {
        swap(queue[i], queue[smallest]);
        min_heapify(smallest, queue_size);
    }
}

void Queue::build_min_heap()
{
    // build a minimum heap
    for (int i = rear / 2; i > -1; i--)
        min_heapify(i, rear);
}

void Queue::heap_sort()
{
    // sort an array by building a heap and then use heap sort
    // use build_max_heap/build_min_heap and max_heapify/min_heapify
    // to sort in increasing/decreasing
    build_max_heap();
    // build_min_heap();
    int last_heap_index;
    for (last_heap_index = rear - 1; last_heap_index > 0; last_heap_index--)
    {
        swap(queue[last_heap_index], queue[0]);
        max_heapify(0, last_heap_index);
        // min_heapify(0, last_heap_index);
    }
}

void Queue::insertion_sort()
{
    for (int i = 1; i < rear; i++)
    {
        for (int j = i - 1; j > -1 && queue[j + 1] < queue[j]; j--)
            swap(queue[j], queue[j + 1]);
    }
}