// Problem: Squares of a sorted array
// Problem No.: 977
// Platform: LeetCode
// Difficulty: easy


// Approach:Find the squares of all the elements of the array, and place them in the respective orders
// the vector ans.
// and then sort the vector ans, 

// Time Complexity: O(nlogn)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
       vector<int>ans;
       for(int i=0;i<n;i++){
        ans.push_back(nums[i] *  nums[i]);
       }

       sort(ans.begin(),ans.end());
       return ans;
    }
    
};


//Approach: take a start and end pointer and comapare the absolute values, the one is greater
// find it's square and place it at the n-1 and , move the greater elements pointer.
// basically we placing the square of the largest values at the end of the array,
// and the largest square is deterined using the comparing the absolute values frm both the ends.

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
    int st=0, end=n-1;
    int idex=n-1;

    while(st <= end){
        if(abs(nums[st]) > abs(nums[end]) ){
            ans[idex] = nums[st] * nums[st];
            st++;
        }
        else{
            ans[idex] = nums[end] * nums[end];
            end--;
        }
    
    idex--;
    }
    return ans;

    }
    
};
