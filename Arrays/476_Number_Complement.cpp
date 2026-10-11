class Solution {
public:
    int findComplement(int num) {
        
        string ans = "";
        while(num != 0){
            ans+=char('0'+ num%2);
            num/=2;
        }
       
        reverse(ans.begin(),ans.end());

         string navin = "";
          for(int i=0;i<ans.size();i++){
            if(ans[i] == '0'){
                navin.push_back('1');
            }
            else{
                navin.push_back('0');
            }
        }

        int count = 0, numb = 0;
        for(int i=navin.size()-1;i>=0;i--){
           numb+= pow(2,count) * (navin[i]-'0');
           count++;
        }
        return numb;
    }
};