class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
       int mini =1 , maxi = INT_MIN;
       for(int i= 0 ;i<nums.size();i++){
        // mini=min(mini,nums[i]);
        maxi=max(maxi,nums[i]);
       } 
       int low = mini , high = maxi ;
       while(low<=high){
        int mid = low + (high-low)/2;
        if(possible(nums,mid,threshold)){
            high=mid-1;
        }else{
            low=mid+1;
        }
       }
       if(low>=maxi) return maxi;
       return low;
    }
    bool possible(vector<int>nums,int mid,int limit){
        int sum = 0 ; 
        // cout<<"mid"<<mid<<" ";
        for(int i = 0 ;i<nums.size();i++){
            
            sum+=(nums[i]+mid-1)/mid;
            // cout<<"SUM INSIDE"<<sum<<endl;
        }
        // cout<<"sum"<<sum<<endl;
        return sum<=limit;
    }
};