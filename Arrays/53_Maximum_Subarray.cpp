// Problem: Maximum Subarray
// Platform: LeetCode
// Difficulty: Medium

//Approach : brute force:
// Logic: Find all the subarray's and for each subarray
//        by iterating through two loops, one loop for the start of the subarray and the 
//        other one for the end of the subarray. 
//        calculate the sum for each subarray.
///   ---> every time update the maximum subarray.

// T.C = O(n2)
//S.C = O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            int currentSum = 0;

            for (int j = i; j < nums.size(); j++) {
                currentSum += nums[j];   // extend subarray
                maxSum = max(maxSum, currentSum);
            }
        }

        return maxSum;
    }
};


// Approach 2: Optimal Approch ( kadane's Algorithm )
// logic : Keep adding numbers to a running sum.
//If the running sum becomes negative by taking the current number, then start fresh from current number.
//Keep track of the max sum.

//TC = O(n)
// SC = O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     int currSum=0;
     int MaxSum=INT_MIN;
     for(int i=0;i<nums.size();i++){
        currSum+=nums[i];
        if(currSum > MaxSum){
            MaxSum = currSum;
        }
        if(currSum < 0){
            currSum= 0;
        }
     }
       return MaxSum; 
    }
};
