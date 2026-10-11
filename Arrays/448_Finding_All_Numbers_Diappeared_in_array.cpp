class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        set<int>st;
        for(int n: nums){
            st.insert(n);
        }

        for(int i=1;i<=n;i++){
            if(st.find(i) == st.end()){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};