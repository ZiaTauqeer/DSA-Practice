#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n){
    if (n<=1) return n;
    int last = fibonacci(n-1);
    int second_last = fibonacci(n-2);
    return last + second_last;
}

int main(){
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    cout<<fibonacci(n);
}
//Time complexity is O(2^n)