//pattern
// ****
// ****
// ****
// ****
#include <iostream>
using namespace std;
class Solution {
public:
    void pattern1(int n) {
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                cout<<"*";
            }
            cout<<endl;
        }

    }
};

int main() {
    Solution obj;
    obj.pattern1(5);// n=5
    return 0;
}
