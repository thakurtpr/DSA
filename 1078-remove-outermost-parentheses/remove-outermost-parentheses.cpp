class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string res="";

        for(int i=0; i<s.size(); i++) {
            if(s[i]=='(' && s[i+1]==')') i++;
            else {
                i++;
                while(true) {
                    if(s[i]=='(') {
                        res+=s[i];
                        cnt++;
                        i++;
                    } else {
                        if(cnt!=0) {
                            cnt--;
                            res+=s[i];
                            i++;
                        } else break;
                    }
                }
            }
        }
        return res;
    }
};