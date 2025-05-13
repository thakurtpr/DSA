class Solution {
public:
    bool isPossible(vector<int>& weights,int capacity, int days){
        int day = 1 ,load=0 ;
        for(int i = 0 ; i<weights.size();i++){ 
            load+=weights[i];           
            if(load>capacity){
                day++;
                load = weights[i];
            }
        }
        return day<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MIN, high = 0 ;
        for(int i = 0 ;i< weights.size();i++){
            low =max(weights[i],low);
            high += weights[i];
        }
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isPossible(weights,mid,days)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }

};