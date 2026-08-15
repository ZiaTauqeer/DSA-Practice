//pattern 
/*
      *
     ***
    ***** 
   *******

   Notice here it is space * space
   The number of stars here is 2xi+1
   Number of spaces is n-i-1
*/
#include<bits/stdc++.h>
using namespace std;

void print1(int n){
    for (int i =1;i<=n;i++){
        //space
        for (int j = 0;j<n-i-1;j++){
            cout<<" ";
        }
        //star
        for (int j = 0;j<2*i+1;j++){
            cout<<"*";
        }
        //space
        for (int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        cout<<endl;
    }
}

int main(){
        int n;
        cin>>n;
        print1(n);
}