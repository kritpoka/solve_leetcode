#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int left = 0;
        vector<int> last(128, -1);

        for(int right=0; right<s.size(); right++){
            if(last[s[right]] >= left){
                left = last[s[right]] + 1;
            }

            cout << s[right] << endl;

            last[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }

    // int lengthOfLongestSubstring(string s) {
    //     int maxLen = 0;

    //     for(int i=0; i<s.size(); i++){
    //         vector<bool> visit(128, false);

    //         for(int j=i; j<s.size(); j++){
    //             if(visit[s[j]]){
    //                 break;
    //             }else{
    //                 if(maxLen < j-i+1)
    //                     maxLen = j-i+1;
    //                 visit[s[j]] = true;
    //             }
    //         }
    //     }

    //     return maxLen;
    // }
};

int main(){
    Solution solution;

    string input[3] = {"abcabcbb", "bbbbb", "pwwkew"};

    // int ans = solution.lengthOfLongestSubstring(input);

    for(string str : input){
        cout << solution.lengthOfLongestSubstring(str) << endl;
    }

    return 0;
}