class Solution {
public:
    string frequencySort(string s) {
        vector<int> mp(128, 0);
        // Count Frequencies
        for (int i = 0; i < s.length(); i++)
            mp[s[i]]++;
// auto comparator = [&](char a, char b) {...};: Defines a lambda function comparator used for sorting the characters in the string. The lambda function takes two characters a and b and compares them based on their frequencies in the mp vector.
        auto comparator=[&](char a, char b) {
            if (mp[a] == mp[b])
                return a < b;
            return mp[a] > mp[b];
        };

        sort(s.begin(), s.end(), comparator);
        return s;
    }
};