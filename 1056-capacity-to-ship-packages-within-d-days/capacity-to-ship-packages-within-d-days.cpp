class Solution {
public:
// Find The Maximum Element from the Array
    int maxElement(vector<int>& nums,int &sum)
    {
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            sum+=nums[i];
        }
        return maxi;
    }
// Calculate the Days need to ship when Max Weight is W
    int daysNeedtoShip(vector<int>& nums,int w){
        int day=0;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {   
            sum+=nums[i];
            if(sum > w){
                // cout<<"Break for "<<nums[i]<<" as the Sum "<<sum<<endl;
                day+=1;
                sum=nums[i];
            }
        }
        // cout<<"For w "<<w<<" Days is "<<day<<endl;
        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        int maxi=maxElement(weights,sum);
        int ans=INT_MAX;
        // LINEAR SEARCH
        /*
        for(int i=maxi;i<=sum;i++){
            int d=daysNeedtoShip(weights,i);
            if(d<days){
                ans=min(ans,i);
            }
        }
        */
        // BINARY SEARCH
        int s=maxi;
        int e=sum;
        while(s<=e){
            int mid=(e-s)/2 + s;
            int d=daysNeedtoShip(weights,mid);
            // Left Half
            if(d < days){
                ans=mid;
                e=mid-1;
            }
            // Right Half
            else
            s=mid+1;
        }
        return ans;
    }
};