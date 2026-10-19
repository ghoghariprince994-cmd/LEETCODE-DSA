class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        queue<int>q1;
       
        vector<int>res(deck.size());
        for(int i=0;i<deck.size();i++)
        {
            q1.push(i);
        }
        int i=0;
        while(!q1.empty())
        {
            res[q1.front()]=deck[i];
            q1.pop();
            i++;
            if(!q1.empty())
           { q1.push(q1.front());
            q1.pop();}
        }
        return res;
    }
};