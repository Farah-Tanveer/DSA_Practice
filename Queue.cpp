#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define size 100
class Queue{
    int arr[size];
    int front;
    int rear;
public:
    Queue(){
        front=-1;
        rear=-1;
    }
    bool isEmpty(){
        if(front==-1&&rear==-1) return true;
        else return false;
    }
    bool isFull(){
        if(rear==size-1) return true;
        else return false;
    }
    void enqueue(int e){
        if(!isFull()){
            if(front==-1)
            {
                front++;
            }
            rear++;
            arr[rear]=e;
        }
        else
            cout<<"Queue is full\n";
    }
    void dequeue(){
        int ele;
        if(!isEmpty()){
            ele=arr[front];
            if(front==rear){
                rear=front=-1;
            }
            else
                front++;
        }
    }
    int peek(){
        if(isEmpty()){
            cout<<"Queue is empty!\n";
            return -1;
        }
        else{
            return arr[front];
        }
    }
    void display()
    {
        if(isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue: ";

        for(int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};  
int main() {
    // Your code here
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();

    q.display();

    cout << "Front element: "<< q.peek() << endl;
    return 0;
}