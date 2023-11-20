class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int s=0;
        int e=n-1;
        while(s<e){
            int sum=numbers[s]+numbers[e];
            // cout<<sum<<" ";
            if(sum==target)
            {
                return {s+1,e+1};
            }
            if(sum<target)
            s++;
            else
            e--;
        }
        return {-1,-1};
    }
};