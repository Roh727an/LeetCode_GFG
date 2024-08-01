class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(int i=0;i<details.size();i++)
        {
            string str=details[i];
            string ageS=str.substr(11,2);
            int age=stoi(ageS);
            if(age>60)
            ans++;
        }
        return ans;
    }
};