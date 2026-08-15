#include <bits/stdc++.h>
using namespace std;

int n;
int i;
void printn(int i,int n) {
    if(i>n){
        return;
    }
    printn(i+1,n);
    cout<<i<<endl;
}

int main() {
    cout<<"Begin count down from what number?"<<endl;
    cin >> n;
    printn(1,n);

    return 0;
}
/*Time complexity is O(N)*/