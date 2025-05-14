class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int>temp;
        int r=k,count=1;

        for(int i = 0 ;i<arr.size();i++,count++){
            if(count==arr[i]){
                cout<<"count inside if="<<count<<endl;
                continue;
            }
            while(count!=arr[i]){
                cout<<"count inside while "<<count<<endl;
                if(k==0) break;
                temp.push_back(count);
                count++;
                k--;
                cout<<k<<endl;
            }

        }
        if(k!=0){
            return arr[arr.size()-1]+k;
        }
        // cout<<"temp "<<temp[r];
        return temp[r-1];
    }
};