#include<iostream>
#include<chrono>
using namespace std;
using namespace chrono;
template<class T>
class vector{
    T *arr;
    int size;
    int capacity;
public:
    vector(){
        size=0;
        capacity=2;
        arr=new T[capacity];
    }
    void expand(){
        capacity*=2;
        T *temp=new T[capacity];
        for(int i=0;i<size;i++){
            temp[i]=arr[i];
        }
        delete[] arr;
        arr=temp;
    }
    void push_back(T i){
        if(capacity==size){
            expand();
        }
        arr[size++]=i;
    }
    void pop_back(){
        if(size>0)
            size--;
    }
    bool empty(){
        if(size==0){
            return true;
        }
        return false;
    }
    int Size(){
        return size;
    }
    T get(int idx){
        return arr[idx];
    }
    void set(int i,int x){
        arr[i]=x;
    }
    int minElement(){
        if(empty()) return -1;
        int min=arr[0];
        for(int i=0;i<size;i++){
            if(arr[i]<min) min=arr[i];
        }
        return min;
    }
    int maxElement(){
        if(empty()) return -1;
        int max=arr[0];
        for(int i=0;i<size;i++){
            if(arr[i]>max) max=arr[i];
        }
        return max;
    }
    void clear(){
        size=0;
    }
    void display(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    ~vector(){
        delete[] arr;
    }
};
int main(){
     auto start = high_resolution_clock::now();

     vector<int> v;
    v.push_back(10);
    v.push_back(5);
    v.push_back(30);
    v.push_back(2);
    cout<<"Vector Elements: "; v.display();
    cout<<"Size: "<<v.Size()<<endl;
    cout<<"IsEmpty: "<<v.empty()<<endl;
    cout<<"Element at index 2 :"<<v.get(2)<<endl;
    v.set(1,15); cout<<"After set operation: ";
    v.display();
    cout<<"Minimun Element: ";
    if(v.minElement()==-1){
        cout<<"Vector is empty!"<<endl;}
    else{
        cout<<v.minElement()<<endl;}

    cout<<"Maximium Element: ";
    if(v.maxElement()==-1){
        cout<<"Vector is empty!"<<endl;}
    else{
        cout<<v.maxElement()<<endl;}  
    v.pop_back(); cout<<"After pop_back: "; v.display();

    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start);
    cout << "Time: " << duration.count() << " microseconds";
   
    return 0;
}