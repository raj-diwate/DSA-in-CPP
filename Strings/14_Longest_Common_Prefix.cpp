#include<iostream>
#include<vector>
#include<string>
using namespace std;

string longestCommonPrefix(vector<string>&strs){
    int n = strs.size();
    string result = "";

    for(int i=0;i<strs[0].size();i++){
        char ch = strs[0][i];
        for(int j=1;j<n;j++){
            if(i >=  strs[j].length() || ch != strs[j][i]){
                return result;
            }
        }
        result+=ch;
    }
    return result;
}


int main(){
    vector<string>strs = {"flower","flow","flight"};
   string ans  = longestCommonPrefix(strs);

   cout<<ans;
   return 0;
}