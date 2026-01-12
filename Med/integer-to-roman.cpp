#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        const int number[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const string symbols[13] = {"M",  "CM", "D",  "CD", "C",  "XC", "L", "XL", "X",  "IX", "V",  "IV", "I"};

        string roman = "";

        for(int i=0; i<13; i++){
            while(num >= number[i]){
                roman += symbols[i];
                num -= number[i];
            }
        }

        return roman;
    }
};

int main() {
    Solution solution;
    string ans = solution.intToRoman(3749);

    cout << ans << endl;

    return 0;
}