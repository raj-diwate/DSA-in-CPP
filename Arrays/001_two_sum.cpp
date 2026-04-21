// Problem: Two Sum
// Platform: LeetCode
// Difficulty: Easy
#include<vector>
#include<unordered_map>
using namespace std;

// Approach 1:
// Brute force using two loops to check all pairs

// Time Complexity: O(n^2)
// Space Complexity: O(1)

/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]+nums[j] == target){
                return{i,j};
            }
        }
     }
     return {};
    }
};
*/

// Approach 2 (Optimized):
// Using unordered_map (hash map)
// Time Complexity: O(n)
// Space Complexity: O(n)


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int needed = target - nums[i];

            if(mp.find(needed) != mp.end()){
                return {mp[needed],i};
            }
            mp[nums[i]]=i;
        }
        return{};
        
    }
};
