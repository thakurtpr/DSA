class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int maxi=INT_MIN;
        for(int i =0;i<piles.size();i++){
            if(piles[i]>=maxi){
                maxi=max(maxi,piles[i]);
            }
        }
        // cout<<maxi;
        int low=1,high=maxi;
        int ans = INT_MAX;
        while(low<=high){
            int mid = low + (high-low)/2;
            long long sum = 0 ;
            for(int i= 0 ;i<piles.size();i++){
                // piles[i]/mid
                
                sum+=(piles[i]+mid-1)/mid;
                // cout<<"piles="<<piles[i]<<"mid="<<mid<<"sum="<<sum<<endl;
            }
            // cout<<sum<<endl;
            if(sum<=h){
                // cout<<"Sum="<<sum<<"h="<<h<<"ans"<<ans<<"mid"<<mid<<endl;
                if(mid<=ans){
                    ans=mid;
                }
                high=mid-1;
            }else{
                low=mid+1;
            }
            
        }
        return ans;
    }
};