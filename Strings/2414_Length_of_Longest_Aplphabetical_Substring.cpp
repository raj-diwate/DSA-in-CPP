class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();
        

        int j=1;
        int len = 1, max_len = 1;
        while(j < n){
            if(s[j]-'a' == s[j-1]-'a'+1){
                len++;
                max_len = max(max_len,len);
            }
            else{
                len = 1;
            }

            j++;
        }
        return max_len;
    }
};