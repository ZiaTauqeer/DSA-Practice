#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number whose factors you want to see:"<<endl;
    cin>>n;
    for (int i=1; i<=n;i++){
        if (n%i==0){
            cout<<i<<" ";
        }
    }
}
/*Time complexity is O(N)*/