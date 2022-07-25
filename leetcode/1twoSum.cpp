#include <bits/stdc++.h>
using namespace std;

class Solution {

    set<int> numSet;
    map<int, int> numMap;

public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> ret;
        for(int i = 0; i< nums.size(); i++){
            numSet.insert(nums[i]);
            numMap[nums[i]] = i;
        }

        for(int i = 0; i<nums.size(); i++){
            int findNum = target - nums[i];

            if(numSet.find(findNum) != numSet.end()){
                ret.push_back(i);
                ret.push_back(numMap[findNum]);
            }
        }
    }
};
