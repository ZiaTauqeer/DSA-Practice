#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout<<"enter you string"<<endl;
    cin>>s;
    
    //precompute
    int hash[26]={0};
    for (int i=0; i<s.size();i++){
        hash[s[i]-'a']++;
    }

    int q;
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        cout<<"the number of "<<c<<"'s are "<<hash[c-'a']<<endl;
    }
    return 0;
}