class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n = s.size();
        int l = 0, r = 0, max_len = 0;
        int countT = 0, countF = 0;

        while(r<n){
            if(s[r] == 'T'){
                countT++;
            }
            else{
                countF++;
            }

            while(min(countT,countF) > k){
                if(s[l] == 'T'){
                    countT--;
                }
                else{
                    countF--;
                }
                l++;
            }
            max_len = max(max_len,r-l+1);
            r++;
        }
    return max_len;
    }
};