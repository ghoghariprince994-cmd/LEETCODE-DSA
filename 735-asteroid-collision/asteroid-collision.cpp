class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        int n=asteroids.size();
        int i=0;
        vector<int>res;
        
        while(i<n)
        {
            bool is=false;
            while(!s.empty() &&  asteroids[i]<0 && s.top()>0 && s.top()<abs(asteroids[i]))
            {
                s.pop();
            }
            if(!s.empty()  &&asteroids[i]<0 && s.top()>0 &&s.top()==abs(asteroids[i]) ) {s.pop();is=true;}
            if(!s.empty()  && asteroids[i]<0 && s.top()>0 &&s.top()>abs(asteroids[i]))
            {
                is=true;
            }
            if(!is)
             { 
                s.push(asteroids[i]);
              }
            
            
            i++;
        }
        i=0;
        while(!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};