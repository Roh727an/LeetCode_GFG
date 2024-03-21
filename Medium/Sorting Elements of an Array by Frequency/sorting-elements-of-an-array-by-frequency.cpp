#include <bits/stdc++.h>
using namespace std;
int main()
 {
	 int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        vector<int>nums;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) {
            int num;
            cin>>num;
            nums.push_back(num);
            mp[num]++;
        }
    sort(nums.begin(),nums.end(),[&](int a,int b){
        return mp[a]!=mp[b]?mp[a]>mp[b]:a<b;
    });
    for(int i=0;i<n;i++) {
            cout<<nums[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}