#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int index = digits.size() - 1;
        // cout << index;

        while(index >= 0){
            if(digits[index] + 1 == 10){
                // cout << "before plus one: " << digits[index] << endl;
                digits[index] = 0;
                // cout << "after plus one: " << digits[index] << endl;
                index--;
            }else{
                // cout << "before: " << digits[index] << endl;
                digits[index] += 1;
                // cout << "after: " << digits[index] << endl;
                return digits;
            }
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main(){
    Solution solution;
    vector<int> digits = {9, 9, 9};

    vector<int> ans = solution.plusOne(digits);

    for(int num : ans){
        cout << num << endl;
    }

    return 0;
}