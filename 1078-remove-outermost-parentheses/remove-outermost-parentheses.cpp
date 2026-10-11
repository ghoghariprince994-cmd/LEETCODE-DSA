class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<string>st;
        int i=0;
        int n=s.size();
        int l=0;
        int r=0;
        string ans="";
        while(i<n)
        {
            if(s[i]=='(')
            {
                st.push("(");
                l++;
            }else{
                st.push(")");
                r++;
            }
            if(l==r)
            {
                st.pop();
                string temp="";
                while(!st.empty())
                {
                    string x=st.top();
                    st.pop();
                    temp=x+temp;
                    
                }
                temp.erase(0,1);
                ans=ans+temp;
                l=0;
                r=0;

            }
            i++;
        }
       
       return ans;
    }
};