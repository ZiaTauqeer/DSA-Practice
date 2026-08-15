#include <bits/stdc++.h>
using namespace std;

int n;
int i;
void printn(int i,int n) {
    if(i>n){
        return;
    }
    cout<<i<<endl;
    printn(i+1,n);
}

int main() {
    cout<<"Enter till what number u want to be printed";
    cin >> n;
    printn(i,n);

    return 0;
}
/*Time complexity is O(N)*/