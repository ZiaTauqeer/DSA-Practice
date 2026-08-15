#include <bits/stdc++.h>
using namespace std;

vector <int> SortedArr(vector <int> a,vector<int> b){
    int n1 = a.size();
    int n2 = b.size();
    int i =0;//pointer of 1st arr
    int j=0;//pointer of 2nd arr
    vector <int> UnionArr;

    while (i<n1 && j<n2){
        if(a[i]<=b[j]){//when element at first pointer is smaller than element in second pointer
            if(UnionArr.size()==0 || //if size of union array is zero means if the union array is empty then we take whatever element we have or
            UnionArr.back()!=a[i]){// if the last element in union array is not the same as the one pointer i is pointing 
                UnionArr.push_back(a[i]);//take the element pointed by i pointer
            }
            i++;//move the pointer 
        }
        else{
             if(UnionArr.size()==0 || //if size of union array is zero means if the union array is empty then we take whatever element we have or
            UnionArr.back()!=b[j]){// if the last element in union array is not the same as the one pointer j is pointing 
                UnionArr.push_back(b[j]);//take the element pointed by j pointer
            }
            j++;//move the pointer
        }

    }

    while (j<n2){
        if(UnionArr.size()==0 || //if size of union array is zero means if the union array is empty then we take whatever element we have or
        UnionArr.back()!=b[j]){// if the last element in union array is not the same as the one pointer j is pointing 
            UnionArr.push_back(b[j]);//take the element pointed by j pointer
            }
            j++;//move the pointer
        }
    while(i<n1){
        if(UnionArr.size()==0 || //if size of union array is zero means if the union array is empty then we take whatever element we have or
        UnionArr.back()!=a[i]){// if the last element in union array is not the same as the one pointer i is pointing 
            UnionArr.push_back(a[i]);//take the element pointed by i pointer
        }
        i++;//move the pointer 
    }

    return UnionArr;
}


int main(){

    int n1, n2;

    // Taking size of first array
    cout << "Enter size of first array: ";
    cin >> n1;

    vector<int> a(n1);

    // Taking elements of first array
    cout << "Enter elements of first sorted array: ";
    for(int i = 0; i < n1; i++){
        cin >> a[i];
    }

    // Taking size of second array
    cout << "Enter size of second array: ";
    cin >> n2;

    vector<int> b(n2);

    // Taking elements of second array
    cout << "Enter elements of second sorted array: ";
    for(int i = 0; i < n2; i++){
        cin >> b[i];
    }

    // Calling the function
    vector<int> result = SortedArr(a, b);

    // Printing the union array
    cout << "Union of the two arrays is: ";

    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}