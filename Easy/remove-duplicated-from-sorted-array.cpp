#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }

        int k = 1;
        int repeat;

        for(int i=0; i<nums.size(); i++) {
            if(i==0){
                repeat = nums[i];
            }

            else if(nums[i] != repeat) {
                repeat = nums[i];
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

int main() {
    Solution solution;

    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    int k = solution.removeDuplicates(nums);

    cout << k << endl;

    for(int num : nums) {
        cout << num << " ";
    }

    return 0;
}