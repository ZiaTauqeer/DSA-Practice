#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of elements in array"<<endl;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cout<<"enter array element"<<endl;
        cin>>arr[i];
    }
    int sn;
    cout<<"Enter number to be searched"<<endl;
    cin>>sn;
    int i;
    for(i=0;i<n;i++){
        if (arr[i]==sn){
            cout<<"Number found in index number-"<<i;
            break;
        }
    }
    if (i==n){
        cout<<"Number not found";
    }

}
