#include <iostream>

template<class T>
class Stack {
public:
    Stack() : mArray(new T[100]), mTop(-1), mSize(100) {}
    Stack(uint32_t size);
    ~Stack();
    Stack(const Stack& other);
    Stack(const Stack&& other);
    Stack& operator =(const Stack& other);
    Stack& operator =(const Stack&& other);

    void push(T data);
    void pop();
    T top();
    bool empty();
    size_t size();
    void printStack();
    bool isFull();
private:
    T* mArray;
    int32_t mTop;
    uint32_t mSize;
};