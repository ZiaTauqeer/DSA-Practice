//Functional Recursion method to get factorial
#include <bits/stdc++.h>
using namespace std;

int i;
int factorial(int i){
    if (i==0) {
        return 1;
    }
    return i * factorial(i-1);

}
int main(){
    int i;
    cout<<"enter which number's factorial u want:"<<endl;
    cin>>i;
    cout<< factorial(i);
}
//time complexity and space complexity is O(N)