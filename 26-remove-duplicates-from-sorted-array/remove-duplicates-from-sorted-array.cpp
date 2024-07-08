class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        // Insert elements into Set
        for (int i = 0; i < nums.size(); i++)
            st.insert(nums[i]);
        int idx=0;
        // Put Back Elements from Set to nums
        for (auto it = st.begin(); it != st.end(); it++) {
            nums[idx++]=*it; // it is ptr so *it is value stored in it
        }
        return idx;
    }
};