class Solution {
public:
    // O(n^2) solution
      int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<(long long)((long long)m*(long long)k)){
            return -1;
        }
        int mini = INT_MAX , maxi = INT_MIN;
        for(int i = 0 ; i<bloomDay.size();i++){
            if(bloomDay[i]<mini){
                mini=bloomDay[i];
            }
            if(bloomDay[i]>maxi){
                maxi=bloomDay[i];
            }
        }
        int low = mini ,high =maxi ,mid=0 , value= 0,result=INT_MAX;
        while(low<=high){
            mid = low + (high - low)/2;
            if(possible(bloomDay,mid,k,m)){
                // result=min(result,mid);
                high=mid-1;
            }else{
                low=mid+1;
                // high=mid-1;
            }
        }
        return low;
    }
    bool possible(vector<int> arr,int mid,int k,int m){
        // cout<<"mid"<<mid<<endl;
        int summation = 0, count = 0;
        for(int i = 0 ;i<arr.size();i++){
            // cout<<""<<count<<endl;
            if(arr[i]<=mid){
                count++;
                // continue;
            }else{
                summation+=(count/k);
                count=0;
            }
        }
        summation+=(count/k);
        return summation>=m;
    }
};
    
// int minDays(vector<int>& bloomDay, int m, int k){
//     if(bloomDay.size()<m*k) return -1;
//     sort(bloomDay.begin(),bloomDay.end());
//     return bloomDay[m*k-1];
// }
// };