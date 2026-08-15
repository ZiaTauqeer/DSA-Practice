//Parametrised Recursion method to get factorial
#include <bits/stdc++.h>
using namespace std;

int fact;
void factorial(int i,int fact){
    if (i<1){
        cout<<"the factorial is "<<fact<<endl;
        return;
    }
    factorial(i-1,fact*i);
}
int main(){
    int i;
    cout<<"enter till what number u want the factorial till:"<<endl;
    cin>>i;
    factorial(i,1);
}
//time complexity and space complexity is O(N)