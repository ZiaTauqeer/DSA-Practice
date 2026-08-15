#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    int b;
    cout<<"Enter 1st number"<<endl;
    cin>>a;
    cout<<"Enter 2nd number"<<endl;
    cin>>b;
    while(a>0 && b>0){
        if (a>b) a=a%b;
        else b = b%a;
    }
    if (a==0) cout<<"The gcd is "<< b;
    else cout<<"The gcd is "<<a;
}