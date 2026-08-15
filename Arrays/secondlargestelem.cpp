#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of array "<<endl;
    cin>>n;
    int arr[n];
    for (int i = 0; i<n;i++){
        cout<<"Enter array element:"<<endl;
        cin>>arr[i];
    }
    int largest = arr[0];
    for (int i=0;i<n;i++){
        if (arr[i]>largest){
            largest = arr[i];
        }
    }
    int s_largest = arr[0];
    for (int i=0;i<n;i++){
        if (arr[i]>s_largest && arr[i]<largest){// or write && arr[i]!=largest
            s_largest = arr[i];
        }
    }
    cout<<"The second largest element is:"<<s_largest<<endl;

}







































/* First code without help*/