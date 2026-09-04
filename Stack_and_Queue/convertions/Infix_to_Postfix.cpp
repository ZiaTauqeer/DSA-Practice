#include <bits/stdc++.h>
using namespace std;
//assigning precedence
int precedence(char c){
    if (c == '^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if (c=='+' || c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}

void InfixToPostfix(string s){
    stack<char> st;
    string ans;
    int n = s.size();

    for (int i=0; i<n;i++){
        char c = s[i];
// check for operand
        if((c>='a'&& c<='z')
        || (c>='A'&& c<='Z')
        || (c>='0'&& c<='9')){
            ans +=c; // add the operand to ans
        }
//if second character is an operand add it to the string
        else if(c =='('){
            st.push('(');
        }
//if u get closibg bracket
        else if (c==')'){
            while(st.top()!='('){//keep popping till u pop the first opening bracket that shows up
                ans+= st.top();//keep adding stack stuff to answer before popping
                st.pop();
        }
        st.pop();
    }
    else{
        while(!st.empty()&&precedence(s[i])<=precedence(st.top())){
            ans+= st.top();
            st.pop();//pop based on priority
        }
        st.push(c);
    }
}
// Pop all the remaining elements from the stack
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    cout << "Postfix expression: " << ans << endl;  // Output the result
}

int main(){
    string exp = "(p+q)*(m-n)";  // Infix expression
    cout << "Infix expression: " << exp << endl;
    InfixToPostfix(exp);  // Convert the infix expression to postfix
    return 0;
}