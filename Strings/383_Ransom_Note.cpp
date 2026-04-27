// Problem: Ransom Note
// Problem No.:383
// Platform: LeetCode
// Difficulty: Easy


// Approach:  Counting the frequency of the each character in magazine  using craeting a  vector<int> freq(26,0) 
//            and for each character in ransom note redduce the frequency of the 
//            characters in magazine.  
//            if the frequency of the any of the characters  < 0 , then the ransom note requires 
//            that particular character more than present in the magazine, and hence return false,
//            else true.

//T.C = O(m+n)
//      m = magazine.length()
//      n = ransomNote.length()
//S.C = O(1)

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26,0);

        for(char ch: magazine){
            freq[ch-'a']++;
        }
        for(char ch: ransomNote){
            freq[ch-'a']--;
        
        if(freq[ch-'a'] <0){
            return false;
        }
    }
   return true;
        
    }
};
