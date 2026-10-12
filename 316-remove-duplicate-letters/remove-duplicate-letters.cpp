class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char>st;
        string ans="";
        vector<bool> seen(26, false);
        unordered_map<char,int>m;
        for(char i='a';i<='z';i++)
        {
            m[i]=0;
            
        }
        for(char c:s)
        {
            m[c]++;
        }
        for(int i =0;i<s.size();i++)
        {
            m[s[i]]--;

            if (seen[s[i] - 'a']) {
                     continue;
                   }
            while(!st.empty() && st.top()>s[i] && m[st.top()]>0)
            {
               
                seen[st.top() - 'a'] = false;
                st.pop();
            
            }
            if(!seen[s[i]-'a'])
           { st.push(s[i]);
            seen[s[i]-'a']=true;
           }

        }
        while(!st.empty())
        {
            char x=st.top();
            st.pop();
            ans+=x;
        }
       reverse(ans.begin(),ans.end());
               return ans;
    }
};