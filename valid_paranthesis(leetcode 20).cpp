#include<iostream>
#include<stack>
using namespace std;

bool isMatching(char open, char close){
    if(open=='(' && close==')') return true;
    if(open=='{' && close=='}') return true;
    if(open=='[' && close==']') return true;
    return false;
}

bool isValid(string s){
    stack<char> st;

    for(int i=0; i<s.length(); i++){
        char ch = s[i];

        if(ch=='(' || ch=='{' || ch=='['){
            st.push(ch);
        }
        else{
            if(st.empty()) return false;

            if(!isMatching(st.top(), ch))
                return false;

            st.pop();
        }
    }

    return st.empty();
}

int main(){
    string s = "{[()]}";
    if(isValid(s))
        cout<<"Valid";
    else
        cout<<"Invalid";
}