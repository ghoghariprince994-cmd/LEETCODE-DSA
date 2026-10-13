class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>r(n);
        vector<int>l(n);
        stack<int>s;
        long long ans=0;
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && arr[s.top()]>=arr[i])
            {
                s.pop();
            }
            r[i]=s.empty()?n:s.top();
            s.push(i);

        }
        while(!s.empty())s.pop();
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && arr[s.top()]>arr[i])
            {
                s.pop();
            }
            l[i]=s.empty()?-1:s.top();
            s.push(i);
        }
        for(int i=0;i<n;i++)
        {
         ans+=(1ll *(i-l[i])*(r[i]-i)*arr[i])%1000000007;
        }
        return ans%1000000007;
    }
};