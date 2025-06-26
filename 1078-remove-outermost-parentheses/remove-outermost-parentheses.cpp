class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0 ;
        string result = ""; 
        for(int i = 0 ; i  < s.size(); i++){
            
            if(s[i]=='('){
                if(cnt>0){
                    result +=s[i];
                }
                cnt++;
            }else{
                cnt--;
                if(cnt>0){
                    result+=s[i];
                }
            }
        }
        return result;
    }
};