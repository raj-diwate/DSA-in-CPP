#include<iostream>
#include<algorithm>
#include<string>
#include<set>
#include<unordered_map>
using namespace std;

int longKdistinct(string &s,int k){
    int n = s.size();
    unordered_map<char,int>mp;
    int max_len = 0;

   int l=0,r=0;
   while(r <n){
      mp[s[r]]++;
      while(mp.size() > k){
        mp[s[l]]--;
        if(mp[s[l]] == 0){
            mp.erase(s[l]);

        }
        l++;

      }
      max_len = max(max_len,r-l+1);
      r++;
   }
    return max_len; 
   
}

int main(){
    string s = "aaabbccd";
    int k = 2;
  

    cout<<longKdistinct(s,k);
    return 0;
}


/* 
    int n = s.size();
    int max_len = 0;
   
    for(int i=0;i<n;i++){
        set<char>st;
        for(int j=i;j<n;j++){
            st.insert(s[j]);
            if(st.size() <= k){
                max_len = max(max_len, j-i+1);
            }
            else{
                break;
            }
        }
        return max_len;
    */