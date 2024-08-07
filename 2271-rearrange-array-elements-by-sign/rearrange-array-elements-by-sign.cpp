class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int pos=0,neg=1;
        for(int i=0;i<n;i++)
        {
            int ele=nums[i];
            if(ele>=0 && pos<n){
                ans[pos]=ele;
                pos=pos+2;
            }
            else if(ele<0 && neg<n){
                ans[neg]=ele;
                neg=neg+2;
            }
        }
        return ans;
    }
};