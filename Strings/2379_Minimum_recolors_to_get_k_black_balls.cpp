class Solution {
public:
    int minimumRecolors(string s, int k) {
        int n = s.size();
         int count = 0;
        for(int i=0;i<k;i++){
            if(s[i] == 'B')
            count++;
        }
        int max_count = count;
        for(int j=k;j<n;j++){
            if(s[j] == 'B'){
                count++;
            }
            if(s[j-k] == 'B'){
                count--;
            }
            max_count = max(max_count,count);
        }
        int operations = k - max_count;
        return operations;
    }
};