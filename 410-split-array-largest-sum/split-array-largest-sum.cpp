class Solution {
public:
    bool isPossible(vector<int>& nums, int noOfSubarrays , int mid){
        int subarray = 1 , summation = 0;
        for(int i = 0 ;i<nums.size();i++){
            summation +=nums[i];
            if(summation>mid){
                subarray++;
                i--;
                summation=0;
            }
        }
        return subarray<=noOfSubarrays;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = INT_MIN ,high = 0 ;
        for(int i= 0 ;i<nums.size();i++){
            low=max(low,nums[i]);
            high +=nums[i];
        }
        while(low<=high){
            int mid = low + (high -low)/2;
            if(isPossible(nums,k,mid)){
                high= mid-1;
            }else{
                low= mid+1;
            }
        }
        return low;
    }
};