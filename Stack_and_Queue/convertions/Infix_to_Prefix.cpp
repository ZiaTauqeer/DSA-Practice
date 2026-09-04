#include <bits/stdc++.h>
using namespace std;


//This code uses the same infix to postfix convertion with changes, changes have been highlighted


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

string InfixToPostfix(string s){
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
        //changed this //
        while(!st.empty()&&precedence(s[i])</*Important don't put = sign*/precedence(st.top())){// IMPORTANT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            //line above this changed
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
    //this line is added
    return ans;
    //above line is added new
}

string InfixToPrefix(string s) {
    int l = s.size();

    // Reverse the infix expression
    reverse(s.begin(), s.end());

    // Replace '(' with ')' and vice versa
    for (int i = 0; i < l; i++) {
        if (s[i] == '(') {
            s[i] = ')';
            //i++; //(this not needed in prefix convertion)
        } else if (s[i] == ')') {
            s[i] = '(';
            //i++; //same with this
        }
    }

    string prefix = InfixToPostfix(s);  // Convert the modified infix to postfix

    // Reverse the postfix expression to get the prefix
    reverse(prefix.begin(), prefix.end());

    return prefix;  // Return the prefix expression
}

int main() {
    string s = "(p+q)*(c-d)";  // Infix expression
    cout << "Infix expression: " << s << endl;
    cout << "Prefix Expression: " << InfixToPrefix(s) << endl;  // Output the prefix expression
    return 0;
}