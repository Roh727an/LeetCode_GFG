class Solution {
public:
    int myAtoi(string s) {
        int len=s.length();
        // Skip the Spaces as well as +,- sign at the begining & count +,-
        int i=0,pos=0,neg=0;
        while(i<len && s[i]==' ')
        {
            i++;
        }
        while(i<len &&  s[i]=='+' || s[i]=='-')
        {
            if(s[i]=='+') pos++;
            else if(s[i]=='-') neg++;
            i++;
        }
        // If pos & neg >0 -> INVALID
        if(pos>0 && neg>0  || pos>1 || neg>1)
        return 0;

        long long int num=0;
        // Convert into Number
        while(i<len && (s[i]>='0' && s[i]<='9'))
        {
            if(num>2147483647)
            break;
            num=(num*10) + (s[i]-'0');
            i++;
        }
        // We get the Num 
        if(neg>0 && num!=0)
        num=-num;

        if(num>2147483647)
        return 2147483647;
        if(num<-2147483648)
        return -2147483648;

        return num;
    }
};