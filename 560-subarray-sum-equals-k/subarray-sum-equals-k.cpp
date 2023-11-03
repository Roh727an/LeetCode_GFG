class Solution {
public:
    int subarraySum(vector<int>& Arr, int k) {
        // BRUTE FORCE
        /*
        int ans=0;
        int sum=0;
        int N=Arr.size();
        for(int i=0;i<N;i++)
        {
            sum=0;
            for(int j=i;j<N;j++)
            {
                sum+=Arr[j];
                if(sum==k)
                ans+=1;
            }
        }
        return ans;
        */
        unordered_map<int,int>mp;
        int ans=0;
        mp[0]=1;
        int preSum=0;
        for(int i=0;i<Arr.size();i++)
        {
            preSum+=Arr[i];
            int leftPart=preSum-k;
            ans+=mp[leftPart];
            mp[preSum]+=1;
        }
        return ans;
    }
};