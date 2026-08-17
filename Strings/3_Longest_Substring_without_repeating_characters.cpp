// Problem: Group Anagrams
// Problem No.: 49
// Platform: LeetCode
// Difficulty: Medium


// Approach:  Sliding Window + Hashing  
// Simply created an unordered_map<char,int>
// made a skiding window, where the window's each character element should have the 
// frequency of 1, if the frequency of any character in the window is more than 1, then from left ,
// remove the character from the window and update the left.

//T.C = O(N)
//S.C = O(N)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;
        int left =0,right =0;
        int max_len = 1;
    
        unordered_map<char,int>mp;
        for(right =0;right<n;right++){
            mp[s[right]]++;
            while(mp[s[right]] > 1){
                mp[s[left]]--;
                left++;
            }
            max_len = max(max_len,right-left+1);
            
        }
        return max_len;
    }
};