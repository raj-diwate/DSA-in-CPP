#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {

        int st = 0, end = x, ans = 0;

        while(st <= end) {

            long long mid = st + (end - st) / 2;

            if(mid * mid <= x) {
                ans = mid;
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return ans;
    }
};

int main() {

    Solution sol;

    int x;
    cout << "Enter a number: ";
    cin >> x;

    int result = sol.mySqrt(x);

    cout << "Sq. root is: " << result;

    return 0;
}