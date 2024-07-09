class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int time=customers[0][0];
        double avg=0;
        for(int i=0;i<customers.size();i++)
        {
            if(time<customers[i][0])
            time=customers[i][0];

            time+=customers[i][1];
            // cout<<time<<endl;
            avg+=(time-customers[i][0]);
        }
        return avg/customers.size();
    }
};