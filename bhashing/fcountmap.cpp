#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"enter the size of array"<<endl;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cout<<"enter array element:"<<endl;
        cin>>arr[i];
    }

    //precompute
    map<int,int>mpp;
    for (int i =0; i<n;i++){
        mpp[arr[i]]++;
    }

    /*for (auto it: mpp){
        cout<<it.first<<"->"<<it.second<<endl;
    }*/

    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        cout<<"the number of "<<number<<"'s are "<<mpp[number]<<endl;
    }
    return 0;
}