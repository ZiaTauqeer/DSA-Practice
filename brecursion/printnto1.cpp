#include <bits/stdc++.h>
using namespace std;

int n;
int i;
void printn(int i,int n) {
    if(i<1){
        return;
    }
    cout<<i<<endl;
    printn(i-1,n);
}

int main() {
    cout<<"Begin count down from what number?"<<endl;
    cin >> n;
    printn(n,n);

    return 0;
}
/*Time complexity is O(N)*/