// Problem: Group Anagrams
// Problem No.: 49
// Platform: LeetCode
// Difficulty: Medium

//Approach: we make an unordered_map of string , vector<string>
// and we iterate through the every string in strs, we copy it into the word,
// then we sort the word, so it is lexicographically sorted ,then we map the string s from the 
// to the word. i.e mp[word] .push_back(s)

// and then do this for every string in the strs,
// and create a vector<vector<string>> and then push , one by one the values of the map,
// which will be the anagrams grouped together, of the sorted word.

// T.C = O(n x klog k ) here the k is the size of the copied string
// S.C = O(K)



class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,vector<string>>mp;


         
        for(string s : strs){
          string word = s;
          sort(word.begin(),word.end());
          mp[word].push_back(s);
        }

        vector<vector<string>>ans;
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};
