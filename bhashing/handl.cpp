//code for finding highest and lowest frequencies
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
 map<int,int> mpp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
          mpp[arr[i]]++;

    }
int largest = mpp.begin()->second;
int smallest = mpp.begin()->second;

   for(auto it :mpp){
    cout<<it.first<<"->"<<it.second<<endl;
    if(it.second>largest){
        largest  =it.first;

    }
    else if(it.second<smallest){
        smallest=it.first;
    }
   }
  
cout<<"most repeated number is "<<largest<<endl;
cout<<"least repeated number is "<<smallest<<endl;
return 0;
}