#include<iostream>
#include<algorithm>
using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        int ldigit = 0;
        long long rev = 0;

        if( x<0){
            return false;
        }
        
        while(temp != 0){
            ldigit = temp%10;
            rev =rev*10+ldigit;
            temp = temp/10;
        }
        return rev == x;
        
    }
};

int main() {
    Solution sol;

    int x;
    cout << "Enter a number: ";
    cin >> x;

    bool result = sol.isPalindrome(x);

    if (result) {
        cout << x << " is a palindrome." <<endl;
    } else {
        cout << x << " is not a palindrome." <<endl;
    }

    return 0;
}