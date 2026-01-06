#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char chr : s){
            if(chr == '(' || chr == '[' || chr == '{'){
                st.push(chr);
            }else{
                if(st.empty()){
                    return false;
                }

                char top = st.top();

                if((chr == ')' && top != '(') || (chr == ']' && top != '[') || (chr == '}' && top != '{')){
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }
};

int main(){
    Solution solution;
    bool ans = solution.isValid("()");

    if(ans){
        cout << "True" << endl;
    } else{
        cout << "False" << endl;
    }

    return 0;
}