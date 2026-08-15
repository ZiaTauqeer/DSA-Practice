#include<bits/stdc++.h>
using namespace std;

int main(){
    int ld;
    int n;
    int revnum=0;
    cout<<"enter a number"<<endl;
    cin>>n;
    while( n>0){
    ld=n%10;
    revnum=(revnum*10) + ld;
    n=n/10;
    }
    cout<<"The reversed number is:"<<revnum<<endl;
}
/*
Time complexity is O(log N) bcz division is taking place*/