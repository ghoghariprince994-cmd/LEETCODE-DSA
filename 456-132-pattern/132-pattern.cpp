class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int>s;
        int n=nums.size();
        int i=n-2;
       
        if(n<3)
        {
            return false;
        }
          s.push(nums[n-1]);
          int x=INT_MIN;
        while(i>=0)
        {
           if(nums[i]<x)
                {
                    return true;
                }
           
                while(!s.empty() && nums[i]>s.top())
              {
                
                x=s.top();
                s.pop();
              }
              
               
                    s.push(nums[i]);
                
            

        i--;
        }
       
        return false;
    }
};