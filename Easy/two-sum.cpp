#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable;

        // for(int i=0; i<nums.size(); i++){
        //     hashTable[nums[i]] = i;
        // }

        // for(pair<int, int> i : hashTable){
        //     cout << "key: " << i.first << " value: " << i.second << endl;
        // }

        for(int i=0; i<nums.size(); i++){
            int complement = target - nums[i];

            // cout << hashTable.count(complement) << " " << hashTable[15] << endl;
            
            // if(hashTable.count(complement) && hashTable[complement] != i){ // check if complement in table by key && value != i
            //     return {i, hashTable[complement]};
            // }
            auto it = hashTable.find(complement);
            if(it != hashTable.end()){
                return {it->second, i};
            }
            hashTable[nums[i]] = i;
        }

        return {}; 
    }
};

int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9;

    Solution solution;
    vector<int> ans = solution.twoSum(nums, target);

    for(int num : ans){
        cout << num << endl;
    }

    return 0;
}