#include <iostream>

template<class T>
class Queue {
public:
    Queue();
    Queue(uint32_t size) : mQueue(new T[size]), mFront(0), mRear(-1), mSize(size) {}
    ~Queue();
    Queue(const Queue& obj);
    Queue(const Queue&& obj);
    Queue& operator=(const Queue& obj);
    Queue& operator=(const Queue&& obj);
	bool isFull();
	bool isEmpty();
	T peek();
	bool enqueue(const T);
	bool dequeue(T&);
    

private:
    T* mQueue;
    uint32_t mFront;
    int32_t mRear;
    uint32_t mSize;
};