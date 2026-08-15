#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"the size of array is ?"<<endl;
    cin>>n; // how big the array is 
    int arr[n];
    for (int i =0; i<n; i++){
        cout<<"enter array elements"<<endl;
        cin>>arr[i]; //elements to be put in the array
    }

    //precompute (hash that stores numbers and increments if they are present in the array)

    int hash[13] = {0};
    for (int i=0;i<n;i++){
        hash[arr[i]] +=1 ;
    }

    int q;
    cin>>q;
    while(q--){
        int number; 
        cout<<"enter the number"<<endl;
        cin>>number; // get the number whose count u want
        //fetch
        cout<<"the number of "<<number<<"'s are"<<endl<<hash[number] <<endl; //tells the count of each number in the array
    }
}