#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    T* arr;
    int topIndex;
    int capacity;

    void resize() {
        int newCapacity = capacity * 2;
        T* newArr = new T[newCapacity];

        for (int i = 0; i <= topIndex; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:
    // Constructor
    Stack(int size = 10) {
        capacity = size;
        arr = new T[capacity];
        topIndex = -1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Push
    void push(T value) {
        if (topIndex == capacity - 1) {
            resize();
        }
        arr[++topIndex] = value;
    }

    // Pop
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        topIndex--;
    }

    // Peek
    T top() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return T();  // default value
        }
        return arr[topIndex];
    }

    // Check empty
    bool isEmpty() {
        return topIndex == -1;
    }

    // Size
    int size() {
        return topIndex + 1;
    }

    // Display (bottom to top)
    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }

        for (int i = 0; i <= topIndex; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};