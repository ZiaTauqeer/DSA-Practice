//Functional Recursion method to get summation
#include <bits/stdc++.h>
using namespace std;

int i;
int sum(int i){
    if (i==0) {
        return 0;
    }
    return i + sum(i-1);

}
int main(){
    int i;
    cout<<"enter till what number u want the summation till:"<<endl;
    cin>>i;
    cout<<sum(i);
}