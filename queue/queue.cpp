#include "queue.hpp"

template<class T>
Queue<T>::~Queue() {
    delete[] mQueue;
}

template<class T>
bool Queue<T>::isEmpty() {
    bool ret {false};
    if (mRear == -1) {
        ret = true;
    }
    return ret;
}

template<class T>
bool Queue<T>::isFull() {
    bool ret {false};
    if (mRear == mSize) {
        ret = true;
    }
    return ret;
}


template<class T>
bool Queue<T>::enqueue(const T data) {
    bool ret {false};
    if (this->isFull()) {
        printf("Queue overflow, do not enqueue \n");
    }
    else {
        mRear += 1;
        mQueue[mRear] = data;
        ret = true;
    }
    return ret;
}

template<class T>
bool Queue<T>::dequeue(T& data) {
    bool ret {false};
    if (isEmpty()) {
        printf("Queue already been empty\n");
    }
    else {
        data = mQueue[mFront];
        mFront++;
        ret = true;
    }
    return ret;
}

template<class T>
T Queue<T>::peek() {
    if (isEmpty()) {
        printf("Queue already been empty\n");
    }
    else {
        return mQueue[mFront];
    }
}

int main(void) {
    
}