// Problem: Permutation in String
// Problem No.: 567
// Platform: LeetCode
// Difficulty: Medium


// Approach: Hashing + Sliding Window
//  we basically want to check that permutation of s1 exists in the s2,
//  if yes we return true or else false.

// we first find out the size of s1 and s2, if the size of s1 > size of s2 
// then there is no chance of permutation of s1 can exist inside the s2, so we return false in this case.
// otherwise, we create a freqS1 vector and freqS2 vector, to count the frequency of each character of the s1 and 
// s2 respectively.

// initially we just count the frequency of the s1 in the freqS1,
// and first we make just the sliding window of the size of s1, and for this window,
// we check the freq of the chars in s2, into the freqS2, and check if the freqs1 and freqS2 is same
// then we return true and if not we make the fixed size window of the size of s1 and then check for every 
// window, the freqS1 and freqS2 are same or not.

// This freqS2 is basically dynmically changing, we add the right pointer character to the freqS2 and remove the
// first character frequency of the previous window.


//T.C = O(m x 26) = O(m)
//S.C = O(26) = O(1)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if( n > m )  return false;

        vector<int>freqS1(26,0);
        vector<int>freqS2(26,0);

        for(char ch: s1){
            freqS1[ch-'a']++;
        }
           
           
        for(int i=0;i<n;i++){
            freqS2[s2[i]-'a']++;  
        }
         if(freqS1 == freqS2)
              return true;

         int left = 0;
        for(int right = n;right<m;right++){
            
                  freqS2[s2[right]-'a']++;
                  freqS2[s2[left]-'a']--;
                  left++;
           if (freqS2 == freqS1) return true;
        }
        return false;
    }
};