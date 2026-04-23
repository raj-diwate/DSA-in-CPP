//  Problem: Largest Perimeter Triangle
// Platform: LeetCode 976

// Difficulty: Easy

// Approach: Brute force
//  loop through all indices i of the nums
// then, loop through j=i+1
// and then loop through k=j+1
// nums[i] , nums[j], nums[k] are the sides of triangle

// Concept: Sum of two sides of triangle is always greater than the third side.
// A triangle can be formed only when this condition is followed.

for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
              int a = nums[i];
              int b= nums[j];
              int c= nums[k];

              if( a+b > c && a+c > b && b+c > a){
                maxPerimeter=max(maxPerimeter,a+b+c);
              }
            }
        }
      }
      return maxPerimeter;

// Time Complexity: O(n3)
// Space Complexity: O(1)

// Approach 2: Optimal ( Using Sorting: Since we want the triangle with the largest perimeter.)
// Since the largest element of array will be the n-1 element and second and third largest will be 
// (n-2) and (n-3) 

// so obviously,
// largest + second largest > third largest and,
// largest + third largest > second largest
// so we just need to check for the 
//      second largest + third largest > largest

//T.C = O(nlogn)
// S.C = O(1)

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
     sort(nums.begin(),nums.end());
      
      for(int i=n-1;i>=2;i--){
        int a=nums[i];
        int b=nums[i-1];
        int c=nums[i-2];
        if(b+c > a){
            return a+b+c;
        }

      }

      return 0;
    }
};
