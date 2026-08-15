//pattern
// ****
// ***
// **
// *
#include<bits/stdc++.h>
using namespace std;

void print1(int n){
    for (int i =1;i<=n;i++){
        for (int j = 0;j<n-i+1;j++){//if n=4,first iteration 4-0 so 4 stars then 4-1 so 3 stars etc 
            cout<<"*";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>> n;
    print1(n);
}