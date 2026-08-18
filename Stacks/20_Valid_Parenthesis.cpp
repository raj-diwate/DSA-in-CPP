#include<iostream>
#include<stack>
#include<string>

using namespace std;
 
bool validParenthesis(string s){
    stack<char>st;
    int n = s.size();

    for(int i=0;i<n;i++){
        
        if(s[i] == '(' || s[i] == '[' || s[i] == '{' ){
            st.push(s[i]);
        }
        else{
            if (st.empty()){
            return false;
        }
        if(s[i] == ')' && st.top() == '(' || 
        s[i] == ']' && st.top() == '[' || 
        s[i] == '}' && st.top() == '{' ) {
            st.pop();
        }
        else{
            return false;
        }
        
    }
   
  }
   return st.empty();
}

int main(){
   string s= "()[]{}";
   cout<<boolalpha<<validParenthesis(s);
   return 0;
}