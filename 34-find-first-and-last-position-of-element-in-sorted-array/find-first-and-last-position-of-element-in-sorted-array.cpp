class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int low = 0 ; 
        int high = arr.size()-1;
        int firstIndex=-1,lastIndex=-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid]==target){
                high=mid-1;
                firstIndex=mid;
            }else if(arr[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        low=0 ;
        high = arr.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid]==target){
                low=mid+1;
                lastIndex=mid;
            }else if(arr[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return {firstIndex,lastIndex};
    }
};