// Problem: Jump Game
// Platform: LeetCode
// Difficulty: Medium

//Approach : Optimal 
//T.C = O(n)
//S.C = O(1)

// the maximum jump we can take or travel for ith index is nums[i].
// And we need to check weather we can reach the last index or not, if yes true or else false.
// Also we need to return true if we go beyond the array, like obviously then we can reach the last index as well.

//1.) firstly  let the maxReachable be nums[0] ,
// 2.) then itherate throught the full array, and if i becomes gretaer than maxReacable then return false,
//     becuase since the max Reachable is less than i, we cannot reach the last index.
// 3.) other wise maxReachable = max(maxReachable, i+nums[i]);

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReachable = nums[0];

        for(int i=0;i<n;i++){
            if( i > maxReachable ){
                return false;

            }
            
            maxReachable = max(maxReachable, i+nums[i]);
        }
        return true;
        
    }
};


  
