class Solution {
public:
    int evalRPN(vector<string>& S) {
        // 1.Create a Stack
        stack<int>s;
        // 2.Scan the Postfix Expression from left to right
         for(int i=0; i<S.size(); i++){
            string x = S[i];
            // Operator
            if(x=="+"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a+b);
            }
            else if(x=="-"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b-a);
            }
            else if(x=="*"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a*b);
            }
            else if(x=="/"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b/a);
            }
            // Operand
            else{
                s.push(stoi(x));
            }
        }

        return s.top();
    }
};