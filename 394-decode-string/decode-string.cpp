class Solution {
public:
    string decodeString(string s) {
        int n=s.size();
        int i=0;
        stack<string>st;
        string ans="";
        while(i<n)
        {
            string temp="";
            if(s[i]==']')
           { 
            while(!st.empty() && st.top()!="[")
            {
                temp=st.top()+temp;
                st.pop();
            }
            st.pop();
            
            string t="";
            while(!st.empty() && isdigit(st.top()[0]))
            {
              t=st.top()+t;
              st.pop();
            }          
             int x=stoi(t);
          
            int j=0;
            string d="";
            while(j<x)
            {
             d=temp+d;
             j++;
            }   
            st.push(d);
            }else
             st.push(string(1,s[i]));
             i++;
        }
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};