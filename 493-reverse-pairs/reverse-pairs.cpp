class Solution {
public:
    int reversePairs(vector<int>& nums) {
        //O(n^2)
        // int count = 0 ; 
        // for(int i = 0 ; i<nums.size()-1;i++){
        //     for(int j =i+1;j<nums.size();j++){
        //         long long value = 2*(long long)nums[j];
        //         if(nums[i]>value){
        //             count++;
        //         }
        //     }
        // }
        // return count;
        return mergeSort(nums,0,nums.size()-1);
    }
    int mergeSort(vector<int>& arr, int l, int r) {
        int count=0;
        if(l>=r) return count;
          
        int mid = l+(r-l)/2;
        count+=mergeSort(arr,l,mid);
        count+=mergeSort(arr,(mid+1),r);
        count+=countPairs(arr,l,mid,r);
        count+=merge(arr,l,mid,r);
        
        return count;
        
    }
    int countPairs(vector<int>&arr,int low,int mid, int high){
        int right=mid+1,count=0;
        for(int i = low ; i<=mid;i++){
            while(right<=high && arr[i]>2*(long long)arr[right])
                right++;
            count+=(right-(mid+1));
        }
        return count;
    }
    int merge(vector<int>&arr,int low,int mid ,int high ){
        int count = 0 ; 
        vector<int> temp;   // temporary array
        int left = low;     //starting index of left half 
        int right = mid + 1; //starting index of right half
        while(left<=mid && right<=high){
            
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }else{
               
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
        return count;
    }
};