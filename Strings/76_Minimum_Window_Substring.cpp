class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        int count = n;
        int left = 0,start_idx = 0;
        int min_len = INT_MAX;
        int hash[256] = {0};

        for(int i=0;i<n;i++){
            hash[t[i]]++;
        }

        for(int right=0;right<m;right++){
         
          if(hash[s[right]] > 0)  {
            count--;
          } 
          hash[s[right]]--;
          while(count == 0){
            if(right-left+1 < min_len){
                min_len = right-left+1;
                start_idx = left;
            }
            hash[s[left]]++;
            if(hash[s[left]] > 0){
            count++;
          }
            left++;
          }

        }
        if(min_len == INT_MAX) return "";
        return s.substr(start_idx,min_len);
    }
};