class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // 1.Convert into Minutes
        vector<int>minutes;
        for(int i=0;i<timePoints.size();i++){
            string curr=timePoints[i];
            int hr=stoi(curr.substr(0,2));
            int mn=stoi(curr.substr(3,2));
            int time=hr*60+mn;
            minutes.push_back(time);
        }
        // 2.Sort the Time array
        sort(minutes.begin(),minutes.end());

        // 3.Find the difference
        int ans=INT_MAX;
        for(int i=0;i<minutes.size()-1;i++)
        {
            ans=min(ans,minutes[i+1]-minutes[i]);
        }
        // AM PM CONVERSION
        int lastDiff=minutes[0]+1440 - minutes[minutes.size()-1];
        ans=min(ans,lastDiff);
        return ans;
    }
};