class Solution {
public:
    string largestOddNumber(string num) {
        // int num = 0  ;
        // num = stoi(num);
        // cout<<num<<endl;
        for(int i = num.length()-1;i>=0;i--){
            char value = num[i];
            int int_value = value - '0';
            if(int_value%2!=0){
                return num.substr(0,i+1);
            }
        }
        return "";
        
    }
};