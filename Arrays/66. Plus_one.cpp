// Problem: Plus One
// Platform: LeetCode
// Difficulty: Easy

// Approach: Optimal:-
///          Simply keep adding 1 from the unit's place
//           if the number < 9 add 1 and if it is 9 then  make that place= 0 & give the carry 
//           to the number before it, if all numbers are 9 then just simply add 1 at the begining of the number
//           by using digits.insert(digits.begin(),1) .

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i] < 9){
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
            digits.insert(digits.begin(),1);
        
        return digits;
    }
    
};
