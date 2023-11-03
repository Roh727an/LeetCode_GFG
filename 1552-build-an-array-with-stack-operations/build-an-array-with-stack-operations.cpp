class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        // 
        vector<string>op;
        // Index pointer for traversing Target Array
        int idx=0;
        // Iterate from 1 to N
        for(int i=1;i<=n;i++)
        {
            // If idx crosses target's Last element then We found Our Operations-> Break
            if(idx>=target.size())
            break;

            int ele=i;
            // Push the element
            op.push_back("Push");
            // If the element is not in our Target then Pop it
            if(ele!=target[idx])
            {
                op.push_back("Pop");
            }
            // If it is in our Target array then update idx to next element of Target Array
            else
            idx++;
        }
        // Return the Operation Vector
        return op;
        // Time Complexity->O(N)
        // Space Complexity-> O(1)
    }
};