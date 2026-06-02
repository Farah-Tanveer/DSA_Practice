#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
    void HANOI(int n,char S,char A,char D){
        if(n==1){
            cout<<"Mov disk 1 from "<<S<< " to "<<D<<endl;
            return;
        }
        HANOI(n-1,S,D,A);
        cout<<"Mov disk "<<n<<" from "<<S<< " to "<<D<<endl;
        HANOI(n-1,A,S,D);
    }
int main() {
    // Your code here
    char source='S',dest='D',aux= 'A';
    int n = 3;
    HANOI(n,source,aux,dest);
    return 0;
}