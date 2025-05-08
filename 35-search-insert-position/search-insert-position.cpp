class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0 , high = nums.size()-1;
        int ans = INT_MIN ;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]<target){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        if(ans == INT_MIN){ return low;}
        return ans+1;
    }
};