class Solution {
public:
bool isVowel(char ch)
{
    if(ch=='a' ||ch=='e' ||ch=='i' ||ch=='o' ||ch=='u' || ch=='A' ||  ch=='E' ||ch=='I' ||ch=='O' ||ch=='U')
    return true;

    else
    return false;
}
    bool halvesAreAlike(string s) {
        int v1=0;
        int n=s.length();
        // First Half
        for(int i=0;i<n/2;i++)
        {
            if(isVowel(s[i]))
            v1++;
        }
        // Second Half
        for(int i=n/2;i<n;i++)
        {
            if(isVowel(s[i]))
            v1--;
        }

        return v1==0;
    }
};