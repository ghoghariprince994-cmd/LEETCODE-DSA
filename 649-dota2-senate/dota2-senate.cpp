class Solution {
public:
    string predictPartyVictory(string senate) {
        int n=senate.size();
        queue<int>q1;
        queue<int>q2;
        for(int i=0;i<n;i++)
        {
          if(senate[i]=='R')
          {
            q1.push(i);
          }else{
            q2.push(i);
        }
        }
        while(!q1.empty() && !q2.empty())
        {
            int a=q1.front();
            q1.pop();
            int b=q2.front();
            q2.pop();
            if(a<b)
            {
                q1.push(n+a);
            }else{
                q2.push(n+b);
            }
        }
        if(q1.empty())return "Dire";
        return "Radiant";
    
    }
};