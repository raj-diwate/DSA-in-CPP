// Problem: Search in rotated Sorted Array
// Platform: LeetCode

// Difficulty: Medium


//  Approach:Brute Force Method:-
//Scan every element one by one.
// Time Complexity: O(n)
// Space Complexity:  O(1)


for(int i = 0; i < nums.size(); i++) {
    if(nums[i] == target)
        return i;
}
return -1;


// Approach: Optimal Way:-
// Using Binary Search ( Although the array is rotated, binary search can be
//used since either left or right part of the array will be in sorted manner)
 
// Time Complexity: O(log n)
// Space Complexity:  O(1)


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st=0, end=nums.size()-1;
       

        while(st <= end ){
         int mid = st + (end-st) /2;
         if(nums[mid]  == target)
         return mid;
//left half is sorted
         if(nums[st] <=  nums[mid]){
            if(nums[st] <= target && target < nums[mid]){
                end = mid-1;

            }
            else{
                st = mid+1;
            }
         }
//right half is sorted
         else{
            if(nums[mid] < target && target <= nums[end]){
                  st = mid + 1;
            }
            else{
                end = mid-1;
            }
        }

    }
    return -1;
        
    }
};
