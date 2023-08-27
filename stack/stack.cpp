#include "stack.hpp"

using namespace std;

template<class T>
Stack<T>::Stack(uint32_t size) {
    if (size == 0) {
        printf("Stack size must be greater than 0\n");
    }
    else {
        mArray = new T[size];
        mSize = size;
        mTop = -1;
    }
}

template<class T>
Stack<T>::~Stack()  {
<<<<<<< HEAD
    delete mArray;
=======
<<<<<<< HEAD
    delete mArray;
=======
    delete[] mArray;
>>>>>>> ec94f2e (update double linked list)
>>>>>>> 9e2c02b (update double linked list)
}

template<class T>
void Stack<T>::pop() {
   mTop--;
}

template<class T>
bool Stack<T>::isFull() {
    bool ret {false};
    if (mTop == (mSize - 1)) {
        ret = true;
    }
    return ret;
}

template<class T>
void Stack<T>::push(T data) {
    if (mSize == 0) {
        printf("Stack cannot be equal to 0\n");
    }
    else if (mTop == mSize - 1) {
        printf("buffer full, cannot push \n");
    }
    else {
        mTop += 1;
        mArray[mTop] = data;
    }
}

template<class T>
size_t Stack<T>::size() {
    return mSize;
}

template<class T>
bool Stack<T>::empty() {
    bool ret {false};
    if (mTop == -1) {
        ret = true;
    }
    return ret;
}

template<class T>
T Stack<T>::top() {
    return mArray[mTop];
}

template<class T>
void Stack<T>::printStack() {
    printf("[");
    for (auto itr = 0; itr <= mSize - 2 ; itr++) {
        std::cout<<mArray[itr]<<" ";
    }
    std::cout<<mArray[mSize - 1]<<"]\n";
}

int main(void) {
    std::cout<<"Hello world! \n";
    Stack<int32_t> stack(4);
    Stack<char*> charStack(6);
    Stack<string> strStack(2);
    stack.push(1);
    stack.push(2);
    stack.pop();
    stack.push(3);
    stack.push(4);
    stack.pop();
    stack.push(5);
    stack.push(6);
    stack.push(7);
    charStack.push((char*)"aloo");
    charStack.push((char*)"This");
    charStack.push((char*)"is");
    charStack.push((char*)"Dat");
    charStack.push((char*)"length");
    charStack.push((char*)"5");
    stack.printStack();
    charStack.printStack();   
    strStack.push("Wellcome");
    strStack.push("my github");
    strStack.printStack();
}