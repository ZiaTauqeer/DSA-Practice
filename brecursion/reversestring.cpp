#include <bits/stdc++.h>
using namespace std;

bool reversestring(int i,string &s){
    if (i >=s.size()/2){ //signifies half way of the string
        return true;
    }
    if (s[i] != s[s.size() - i -1]){
        return false;
    } 
    reversestring(i+1,s);
}

int main(){
    string s;
    cout<<"Enter a string"<<endl;
    cin>>s;
    cout<<reversestring(0,s);
    return 0;
}