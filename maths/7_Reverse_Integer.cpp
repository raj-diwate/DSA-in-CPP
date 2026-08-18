#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
    
        int ldigit;
        int rev = 0;
        while(x!= 0){
            ldigit=x%10;
            if(rev> INT_MAX/10 || rev<INT_MIN/10){
                return 0;
            }
            rev=rev*10+ ldigit;
            x=x/10;

            

        }
        return rev;
        
    }
};

int main(){
    
    Solution sol;

    int x;
    cout << "Enter a number: ";
    cin >> x;

    int result = sol.reverse(x);
    cout<<"Reversed Number: "<<result;

    return 0;

}

