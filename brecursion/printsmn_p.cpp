//Parametrised Recursion method to get summation
#include <bits/stdc++.h>
using namespace std;

int sum;
void summation(int i,int sum){
    if (i<1){
        cout<<"the summation is "<<sum<<endl;
        return;
    }
    summation(i-1,sum+i);
}
int main(){
    int i;
    cout<<"enter till what number u want the summation till:"<<endl;
    cin>>i;
    summation(i,0);
}