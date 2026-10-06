class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
      int l=0, r=0;
      int max_fruits = 0;
         unordered_map<int,int>mp;
        while( r < n){
          mp[fruits[r]]++;
          
           if(mp.size() <= 2){
            max_fruits = max(max_fruits,r-l+1);
           }
           if(mp.size() > 2){
            mp[fruits[l]]--;
            if(mp[fruits[l]] == 0){
                mp.erase(fruits[l]);
            }
            l++;
           }
           r++;
        }
        return max_fruits;
    }
};