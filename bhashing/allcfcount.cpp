#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout<<"enter you string"<<endl;
    cin>>s;
    
    //precompute
    int hash[256]={0};//all ascii characters
    for (int i=0; i<s.size();i++){
        hash[s[i]]++;
    }

    int q;
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        cout<<"the number of "<<c<<"'s are "<<hash[c]<<endl;
    }
    return 0;
}