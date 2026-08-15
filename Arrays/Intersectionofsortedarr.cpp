#include<bits/stdc++.h>
using namespace std;

vector <int> IntersectionofArr(vector <int> &a,int n, vector<int> &b, int m){
    int i=0;
    int j=0;
    vector <int> intersectionarr;

    while (i<n && j<m){
        if (a[i]<b[j]){
            i++;
        }
        else if(b[j]<a[i]){
            j++;
        }
        else{//when pointers of both arrays are equal
            intersectionarr.push_back(a[i]);//the element of both array will be same so push any one of them 
            i++;
            j++;
        }
    }

    return intersectionarr;
}


int main(){

    int n, m;

    // Taking size of first array
    cout << "Enter size of first sorted array: ";
    cin >> n;

    vector<int> a(n);

    // Taking elements of first sorted array
    cout << "Enter elements of first sorted array: ";
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }


    // Taking size of second array
    cout << "Enter size of second sorted array: ";
    cin >> m;

    vector<int> b(m);

    // Taking elements of second sorted array
    cout << "Enter elements of second sorted array: ";
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    // Calling the intersection function
    vector<int> result = IntersectionofArr(a, n, b, m);
    // Printing the intersection
    cout << "Intersection of the two arrays is: ";
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}