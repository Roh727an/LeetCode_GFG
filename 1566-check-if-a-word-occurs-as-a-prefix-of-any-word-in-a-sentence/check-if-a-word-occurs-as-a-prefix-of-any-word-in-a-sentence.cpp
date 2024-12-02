class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int wordCnt=1;
        string sub;
        for(int i=0;i<sentence.length();i++){
            // Form Word
            if(sentence[i]!=' '){
            sub="";
            while(sentence[i]!=' '&& i<sentence.length())
            sub+=sentence[i++];
            if(sub.find(searchWord)==0)
            return wordCnt;
            else
            wordCnt++;
            }
        }
        if(sub.find(searchWord)==0)
            return wordCnt;
        else
        return -1;
    }
};