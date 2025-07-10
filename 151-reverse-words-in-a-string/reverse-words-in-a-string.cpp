class Solution {
public:
    string reverseWords(string s) {
        vector<string> words ; 
        string w = "";
        for(char ch: s){
            if(ch!=' '){
                w+=ch;
            }else if(!w.empty()){
                words.push_back(w);
                w="";
            }
        }
        if(!w.empty()){
            words.push_back(w);
        }
        reverse(words.begin(),words.end());
        string ans = "";
        for(int i = 0 ; i < words.size() ; i++){
            ans +=words[i];
            if(i!=words.size()-1){
                ans+=" ";
            }
        }
        return ans;
    }
};