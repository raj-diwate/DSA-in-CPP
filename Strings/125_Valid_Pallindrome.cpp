// Problem: Valid Pallindrome
// Problem No.: 125
// Platform: LeetCode
// Difficulty: Easy

//Approach : Brute force - Using the alnum() fuction to check whether the charcter the character is 
//                         alphanumeric or not.

// Basically what alnum does internally, can be explicitly written as a function to check that if 
// the current character of string is alphanumeric or not by

if((ch >= 'A' && ch <= 'Z') ||
   (ch >= 'a' && ch <= 'z') ||
   (ch >= '0' && ch <= '9'))


// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned ="";

        for(char ch: s){
            if(isalnum(ch)){
                cleaned+=tolower(ch);
            }
        }

        string reversed="";
        for(int i=cleaned.size()-1;i>=0;i--){
            reversed+=cleaned[i];
        }
        return cleaned == reversed;
    }
};


//Approach : Optimal Using two pointers
//T.C= O(n)
//S.C = O(1)

// the idea is to take two pointers left = 0, rigth =string.size()-1
// move the left pointer untill it finds the alphanumeric character
// similarly move the right pointer inwards until it finds the alphanumeric character.

//if the lowercase versions of both the left and right alphanumeric characters are not same then,
// return false, but if same then move the left forward and roght inwards, while( left < right )


class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        int left=0, right= n-1;

        while(left<right){
            while(left < right && !isalnum(s[left])){
                left++;
            }
            while(left < right && !isalnum(s[right])){
                right--;
            }
            if( tolower(s[left]) != tolower(s[right]) ){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
