#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;

        // unordered_map<char, int> roman = {
        //     {'I',1},
        //     {'V',5},
        //     {'X',10},
        //     {'L',50},
        //     {'C',100},
        //     {'D',500},
        //     {'M',1000},
        // };

        int roman[128];
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;

        for(int i=0; i<s.size()-1; i++){
            if(roman[s[i]] < roman[s[i+1]]){
                result -= roman[s[i]];
            } else{
                result += roman[s[i]];
            }
        }

        return result + roman[s[s.size() - 1]];
    }
};

int main(){
    Solution solution;

    int ans = solution.romanToInt("MCMXCIV");
    cout << ans << endl;

    return 0;
}