class Solution {
public:
    bool scoreBalance(string s) {
        int n = s.size();
    
        int totalSum = 0;
        for(char ch: s){
            totalSum+= ch-'a'+1;
        }
       int leftSum = 0, rightSum = 0;

        for(int i=0;i<n;i++){
            leftSum+=s[i]-'a'+1;
            rightSum = totalSum - leftSum;
            if(leftSum == rightSum)
             return true;

            
        }
        return false;
    }
};