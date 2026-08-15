//pattern
// 1
// 22
// 333
// 4444
#include<bits/stdc++.h>
using namespace std;

void print1(int n){
    for (int i =0;i<=n;i++){
        for (int j = 1;j<=i;j++){
            cout<<i<< " ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>> n;
    print1(n);
}