#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }

        string prefix = strs[0];

        for(int i=1; i<strs.size(); i++){
            int j = 0;
            for(; j<strs[i].size() && j<prefix.size(); j++){
                if(prefix[j] != strs[i][j]){
                    prefix = prefix.substr(0,j);
                    break;
                }
            }

            if (j < prefix.size()) {
                prefix = prefix.substr(0, j);
            }

            if(prefix == ""){
                break;
            }
        }

        return prefix;
    }
};

int main(){
    Solution solution;
    vector<string> test = {"flower","flow","flight"};

    string ans = solution.longestCommonPrefix(test);

    cout << ans << endl;

    return 0;
}