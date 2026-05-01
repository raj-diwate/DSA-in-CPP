// Problem: Single element
// Problem No.: 136
// Platform: LeetCode
// Difficulty: Easy


// Approach: Brute force:
// Using the two for loops, count the freqency of each element, and similtaneously if the
// frequency of any element is exactly queal to1 , then return that element.
// Since givent hat except that one single element all the elements are twice.

// Basically iterate through the the loop and check if any element is present only once then return it.

//T.C = O(n2)
//S.C = O(1)


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
      
      for(int i=0;i<n;i++){
        int count =0;
        for(int j=0;j<n;j++){
            if(nums[i] == nums[j]){
                count++;

            }
        }
        if(count == 1){
            return nums[i];
        }
      }
      return -1;
    }
};


// Approach 2: Better
//Using the unordered_map  count the frequency of each number, and then iterate and check for the element 
//with the freqency equal to 1.

// T.C = O(n)
// S.C = O(1)

  class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n =  nums.size();
     unordered_map<int,int> freq;

     for(int num: nums){
         freq[num]++;
     }
   for(pair<int,int> it: freq){
        if(it.second == 1){
            return it.first;
        }
        
     }
       return -1; 
    }
};


// Appraoch 3: Optimal 
// Using the XOR opertion
// XOR of a number with itself = 0
// XOR of a number with 0 = the number itself

//all duplicates gets cancelled out, except the only single element present.
//a ^ a = 0  
//0 ^ b = b

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;

        for(int num: nums){
            ans^=num;
        }
        return ans;
    }
};
