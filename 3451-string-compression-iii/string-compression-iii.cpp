class Solution {
public:
    string compressedString(string word) {
        string ans="";
        int num=0;
        char ch=word[0];
        for(int i=0;i<word.size();i++){
            if(num>=9 || ch!=word[i]){
                // Push
                ans.push_back(num+'0');
                ans.push_back(ch);
                // Reset
                ch=word[i];
                num=1;
            }
            else
            num++;
        }
        ans.push_back(num+'0');
                ans.push_back(ch);
        return ans;
    }
};