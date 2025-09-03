class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if((int)strs.size() <2){
            return strs[(int)strs.size()-1];
        }
        string temp = strs[0];
        int minCount = temp.length() ,count=0 ;
        for(int i = 1 ;i < (int)strs.size();i++){
            count=0;
            for(int j = 0 ;j < (int)strs[i].size();j++){
                cout<<strs[i][j]<<endl;
                if(strs[i][j]==temp[j]){
                    count++;
                }else{
                    break;
                }
            }
            minCount=min(count,minCount);
        }
        return temp.substr(0,minCount);
    }
};