class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>op;
        vector<int>temp;
        int idx=0;
        for(int i=1;i<=n;i++)
        {
            if(target==temp)
            break;
            int ele=i;
            temp.push_back(ele);
            op.push_back("Push");
            if(ele!=target[idx])
            {
                temp.pop_back();
                op.push_back("Pop");
            }
            else
            idx++;
        }
        return op;
    }
};