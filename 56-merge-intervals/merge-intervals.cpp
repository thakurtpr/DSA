class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // if(intervals.size()==1){
        //     return intervals;
        // }
        // sort(intervals.begin(),intervals.end());
        // vector<vector<int>>result;
        // result.push_back(intervals[0]);
        // for(int i=1 ; i<intervals.size();i++){
        //     if(result.back().back()>=intervals[i][0]){
        //         if(result.back().back()<=intervals[i][1]){
        //             result.back()[1]=intervals[i][1];
        //         }
        //     }else{
        //         result.push_back(intervals[i]);
        //     }
        // }
        // return result;

        // THIS IS OF O(nlogn)time and o(n) space 

        //Need to optimize the space 
        if(intervals.size()==1){
            return intervals;
        }
        int ptr = 0; 
        sort(intervals.begin(),intervals.end());
        for(int i = 1 ; i < intervals.size();i++){
            if(intervals[ptr][1]>=intervals[i][0]){
                if(intervals[ptr][1]<intervals[i][1]){
                    intervals[ptr][1]=intervals[i][1];
                }
                
            }else{
                ptr++;
                intervals[ptr][0]=intervals[i][0];
                intervals[ptr][1]=intervals[i][1];
            }
        }
        intervals.erase(intervals.begin()+ptr+1,intervals.begin()+intervals.size());
        return intervals;
    }
};