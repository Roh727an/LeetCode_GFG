class Solution {
public:
bool Rec(string s,int left,int right)
{
    if(left>=right)
    return true;

    if(!isalnum(s[left])) 
    return Rec(s,left+1,right);
    else if(!isalnum(s[right]))
    return Rec(s,left,right-1);
    else if(tolower(s[left])!=tolower(s[right])) 
    return false;

    return Rec(s,left+1,right-1);
}
    bool isPalindrome(string s) {
        // Recursive Approch
        // return Rec(s,0,s.length());
        // Iterative Approch
        int left=0,right=s.length();
        while(left<right)
        {
            if(!isalnum(s[left])) 
            left++;
            else if(!isalnum(s[right]))
            right--;
            else if(tolower(s[left])!=tolower(s[right])) 
            return false;
            else
            {
                left++;
                right--;
            }
        }
        return true;
    }
};