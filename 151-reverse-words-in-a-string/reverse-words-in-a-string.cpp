class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string temp="";
        // int flag = 0 ;
        for(int i = 0 ;i  <s.size();i++){
            if(s[i]!=' '){
                temp+=s[i];
            }else if(temp!=""){
                words.push_back(temp);
                temp="";
            }
        }

        if(temp!=""){
            words.push_back(temp);
        }
        reverse(words.begin(),words.end());
        string result = "";
        for(int i = 0 ; i< words.size();i++){
            result+=words[i];
            if(i!=words.size()-1) result+=" ";
        }
        return result;
    }
};