//Printing 1 to n using backtrack
#include <bits/stdc++.h>
using namespace std;

int n;
int i;
void printn(int i,int n) {
    if(i<1){
        return;
    }
    printn(i-1,n);
    cout<<i<<endl;

}

int main() {
    cout<<"Enter till what number u want to be printed";
    cin >> n;
    printn(n,n);

    return 0;
}
/*Time complexity is O(N)*/