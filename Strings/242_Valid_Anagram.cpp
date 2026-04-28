// Problem: Valid Anagram
// Problem No.: 242
// Platform: LeetCode
// Difficulty: Easy


// Approach:
// simply using the sort function.
//  sort the input string s, and string t,
// for t to be anagram of the s, after the sorting they will equal strings, 
// if equal then true, t is anagram of s, else t is not anagram of s.

//T.C = O(nlogn)
//S.C = O(1)


class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t){
            return true;
        }
        else{
            return false;
        }
        
    }
};


// Approach:  Optimal--> comparing the frequency of the strings

// if the string size of s is not equal to the string size of t, then they cannot become the anagrams.
//  make an array[26] as just the lowercase charcters are there, and keep the array's all elements as 0.
// for each character of the string s, we will add the freq of that character by 1,a dn for the each 
// chaaracter in string t, we will reduce the freq of that character by 1,

// if the two strings are the anagrams, then at the end the array will have all the elements as 0,
// if not then , they are not anagrams.

//T.C = O(n)
//S.C = O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size())  return false;

        int arr[26] ={0};
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']+=1;
            arr[t[i]-'a']-=1;
        }
    
    for(int n: arr){
        if( n != 0)
            return false;
        
    }
    return true;


        
    }
};

