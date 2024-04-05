class Solution {
public:
 bool check(char x, char y) {
        return abs(x - y) == 32;
    }
    string makeGood(string s) {
         string res = "";
        for (char c : s) {
            if (!res.empty() && check(res.back(), c)) res.pop_back();
            else res += c;
        }
        return res;
    }
};