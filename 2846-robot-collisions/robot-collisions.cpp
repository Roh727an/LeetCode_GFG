class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        // 1.Create a Index Array
        vector<int>idx;
        for(int i=0;i<n;i++)
        idx.push_back(i);
        // 2.Sort the Index array according to Position Array(Trick)
        auto comp=[&](int i1,int i2){
            return positions[i1]<=positions[i2];
        };
        sort(idx.begin(),idx.end(),comp);

        stack<int>st;
        // Iterate over Sorted Index Array(Left to Right)
        for(auto id:idx)
        {
            // IF any Robot Moves to Right (Chance of Collision)
            if(directions[id]=='R')
            st.push(id);
            // Robot Moving Left (Collision)
            else{
                // Collisions(Main Logic)
                while(!st.empty()&& healths[id]>0){
                    // Curret health is More
                    if(healths[id]>healths[st.top()]){
                        healths[id]--;
                        healths[st.top()]=0;
                        st.pop();
                    }
                    // Stack top has more health
                    else if(healths[id]<healths[st.top()]){
                        healths[st.top()]--;
                        healths[id]=0;
                    }
                    // Both have same health
                    else{
                        healths[id]=0;
                        healths[st.top()]=0;
                        st.pop();
                    }
                }
            }
        }
       vector<int>ans;
       for(int i=0;i<n;i++)
       {
        if(healths[i]>0)
        ans.push_back(healths[i]);
       }
       return ans;

    }
};