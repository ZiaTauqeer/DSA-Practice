#include<bits/stdc++.h>
using namespace std;

int main(){
    int lastdigit;
    int n;
    int count = 0;
    cout<<"enter a number"<<endl;
    cin>>n;
    while( n>0){
    lastdigit=n%10;
    count=count+1;
    n=n/10;
    }
    cout<<"The number of digits is:"<<count<<endl;
}
/*
Time complexity is O(log N) bcz division is taking place*/