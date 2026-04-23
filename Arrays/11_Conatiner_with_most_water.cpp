// Problem: Conatiner With Most Water
// Platform: LeetCode

// Difficulty: Medium

// Approach: Brute force ( check all the possible boundaries(i,j) for the conatiner
// width of the conatiner will be j-i and water holding capacity will be decided by the minimum of
// height[i] and height[j]

// ( But this approach gives time limit exceeded on leetcode )

// Time Complexity: O(n²)
// Space Complexity: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();
        int maxWater=INT_MIN;

        for(int i=0;i<n;i++){
            int water =0;
            for(int j=i+1;j<n;j++){
                water = min(height[i],height[j]) * (j-i);
                maxWater = max(maxWater,water);
            }
        }
        return maxWater;
    }
};

// Approach:  Optimal 
//           -using two pointers:

// T.C = O(n)
// S.C = O(1)

class Solution {
public:
    int maxArea(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        int maxWater =  0;
        while( i< j){
            int height = min(nums[i] , nums[j]);
            int width = (j-i);
           int area = height * width;
            maxWater = max(maxWater,area);

            if( nums[i] < nums[j]){
                i++;
            } else{
                j--;
            }
        } 
        return maxWater;
    }
};
