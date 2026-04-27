// Problem: Reverse the String
// Problem No.: 344
// Platform: LeetCode
// Difficulty: Easy

// Approach: Using two pointers
// T.C= O(n)
// S.C = O(1)


class Solution {
public:
    void reverseString(vector<char>& s) {
        int start=0, end=s.size()-1;
        while(start<end){
            swap(s[start] , s[end]);
            start++;
            end--;
        }
    }
};

// Normally you can use the STL simpler and short:
reverse(s.begin(), s.end());
