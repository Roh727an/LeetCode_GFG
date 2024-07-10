class Solution {
public:
    int minOperations(vector<string>& logs) {
        int step=0;
        for(int i=0;i<logs.size();i++)
        {
            if(logs[i]=="../" && step>0)
            step--;
            else if(logs[i]!="./" && logs[i]!="../")
            step+=1;
        }
        return step;
    }
};