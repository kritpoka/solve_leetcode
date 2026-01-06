#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }

        long t = x;
        long rev = 0;

        while(t > 0){
            rev = rev * 10 + (t % 10);
            t /= 10;
        }

        return x == rev;
    }
};

int main(){
    Solution solution;

    bool ans = solution.isPalindrome(1211);

    if(ans){
        cout << "True" << endl;
    } else{
        cout << "False" << endl;
    }

    return 0;
}