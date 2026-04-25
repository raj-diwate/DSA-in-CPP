// Problem: Minimum in rotated sorted array
// Platform: LeetCode
// Difficulty: Medium



// Approach 1: Brute Force
// Consider the first element nums[0] of the array as minimum element.
//    that is minimum = nums[0]
// and using the for loop iterate through the rest of the array,
// check if( nums[i] < minimum ) then update the minimum as nums[i]
// finally return the minimum element.


// Time Complexity: O(n)
// Space Complexity: O(1)

int findMin(vector<int>& nums) {
    int mini = nums[0];

    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] < mini) {
            mini = nums[i];
        }
    }

    return mini;
}


// Approach 2: Optimized (Binary Search)
// Time Complexity: O(log n)
// Space Complexity: O(1)

// Logic:
// Think of it like if the array is sorted and then rotated then , at least once 
// you should give the chance for the binary search.

// Although the array is rotated but there is a certain  point untill  which the array can be  
// determined to be sorted either in increasing/decreasing.

// So basically binary search can be applied to find the minimum in the array.

class Solution {
public:
    int findMin(vector<int>& nums) {
        int st=0, end=nums.size()-1;
        while(st < end){
            int mid = st + (end- st)/2;
            if( nums[mid] > nums[end]){
                st = mid + 1;
            }
    
            else{
                end = mid;
            }
        }
        return nums[st];
    }
};

