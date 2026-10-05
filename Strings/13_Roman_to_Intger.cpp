class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mp= {
            {'I',1},{'V',5},{'X',10},{'C',100},{'L',50},{'M',1000},{'D',500}
        };
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            if(i == n-1){
                ans+=mp[s[i]];
            }
            else if(mp[s[i]] < mp[s[i+1]]){
                ans-=mp[s[i]];
            }
            else{
                ans+=mp[s[i]];
            }
        }
        return ans;
    }
};