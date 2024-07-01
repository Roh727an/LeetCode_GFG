class Solution {
public:
bool oddCheck(int n){
    return n%2!=0;
}
    bool threeConsecutiveOdds(vector<int>& arr) {  
        if(arr.size()<3)
        return false;
        for(int i=0;i<arr.size()-2;i++){
            if(oddCheck(arr[i])&&oddCheck(arr[i+1]) && oddCheck(arr[i+2]))
            return true;
        }
        return false;
    }
};