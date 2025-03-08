class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    //    vector<vector<int>>result;
    //    set<vector<int>> st ; 
    //    for(int i = 0  ; i< nums.size()-2 ; i++ ){
    //     for(int j = i+1 ; j< nums.size()-1 ;j++){
    //         for(int k = j+1;k<nums.size();k++){
    //             if(nums[i]+nums[j]+nums[k]==0){
    //                 vector<int> temp={nums[i],nums[j],nums[k]};
    //                 sort(temp.begin(),temp.end());
    //                 st.insert(temp);
    //             }
    //         }
    //     }
    //    } 
    //    result.assign(st.begin(),st.end());
    //    return result;

    // Now lets code it in O(n2)

    // vector<vector<int>>result;
    // set<vector<int>>unique_triplets;
    // for(int i =  0 ; i<nums.size()-2;i++){
    //     unordered_set<int>seen;
    //     for(int j = i+1  ;j<nums.size();j++){
    //         int compliment= -nums[i]-nums[j];
    //         if(seen.find(compliment)!=seen.end()){
    //             vector<int>temp={nums[i],nums[j],compliment};
    //             sort(temp.begin(),temp.end());
    //             unique_triplets.insert(temp);
    //         }
    //         seen.insert(nums[j]);
    //     }
    // }
    // result.assign(unique_triplets.begin(),unique_triplets.end());

    // return result;

    //More Optimization needed its still tho
    //Two pointer approach 

    vector<vector<int>>result;
    sort(nums.begin(),nums.end());
    int n = nums.size();
    for(int i= 0 ; i<n;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        int j = i+1 , k= n-1;
        while(j<k){
            int sum = nums[i]+nums[j]+nums[k];
            if(sum<0) {
                j++;
            }
            else if(sum>0){
                k--;
            }
            else {
                result.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;
                while(j<k&&nums[j]==nums[j-1]) j++;
            }
        }
    }
    return result;
    }
};