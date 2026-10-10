class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string>ans;
        int n1 = list1.size();
        int n2 = list2.size();
      int  min_idexSum = n1+n2-2;
        
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(list1[i] == list2[j] && min_idexSum > i+j){
                    min_idexSum = i+j;
                    ans.clear();
                    ans.push_back(list1[i]);  
                }  
                else if(list1[i] == list2[j] && i+j == min_idexSum){
                    ans.push_back(list1[i]);
                }
            }
        }
        return ans;
    }
};