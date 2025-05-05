class Solution {
public:
    int findPeakElement(vector<int>& nums) {
       int low=0,high=nums.size()-1;
    //    if(nums.size()==1 || nums.size()==2) return 0 ;
       while(low<high){
        int mid = low + (high-low)/2;
        
        if(nums[mid+1]<nums[mid]){
            high=mid;
        }else{
            low=mid+1;
        }
       }

       return low; 
    }
};