// Problem: 3Sum Closest
// Problem No.: 16
// Platform: LeetCode
// Difficulty: Medium

// Approach: Brute force 
// take the closestSum as the sum of first three elements of the nums,
// then iterate through the nums and then find the sum of the all three elements and then 
// find the absolute difference of the sum and target, and compare it with the absolute difference
// of the closestSum and target, if it is less than the closestSum and target then, update the closest sum
// as the sum of the current sum of the three indices that are taken.

//T.C = O(n3)
//S.C = O(1)


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int closestSum = nums[0]+nums[1]+nums[2];
        int n= nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    int sum = nums[i]+nums[j]+nums[k];
                  
                   if(abs(sum-target) < abs(closestSum-target)){
                    closestSum=sum;
                   }
                }
            }
        }
        return closestSum;
        
    }
};

