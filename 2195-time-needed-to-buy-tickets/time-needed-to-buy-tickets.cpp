class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        queue<pair<int,int>>q;
        int time=0;
        int j=0;
        while(j<n)
        {
          q.push({tickets[j], j});
          j++;
        }
       while(!q.empty())
       {
            auto x = q.front();
            q.pop();
           x.first--;
           time++;
           if(x.first == 0 && x.second == k) {
                return time;
            }
           if(x.first!=0)
           {
             q.push(x);
           }
           
       }
       return time;
    }
};