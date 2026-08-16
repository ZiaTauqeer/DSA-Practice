#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of array:"<<endl;
    cin>>n;
    vector <int> arr(n);
    for (int i =0; i<n; i++){
        cout<<"Enter array elements(Must be 0,1 or 2 only)"<<endl;
        cin>>arr[i];
    }
    int low =0;
    int mid = 0;
    int high = n-1;
    while(mid<=high){
        if (arr[mid]==0){
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[high],arr[mid]);
            high--;
        }
    }

    cout << "Sorted array: ";

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}