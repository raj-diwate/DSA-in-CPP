class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int>fresh;
        int i=0, j=0;
        while(i < m && j < n){
            if(nums1[i] < nums2[j]){
             fresh.push_back(nums1[i++]);
             
            }
            else{
                fresh.push_back(nums2[j++]);
            
            }
        }
      while(i < m){
          fresh.push_back(nums1[i++]);
      }
      while( j < n){
        fresh.push_back(nums2[j++]);
      }
      if((m+n) % 2 == 1){
        return fresh[(m+n)/2];
      }
      return (fresh[(m+n)/2] + fresh[(m+n)/2 -1] ) /2.0;
    }
};