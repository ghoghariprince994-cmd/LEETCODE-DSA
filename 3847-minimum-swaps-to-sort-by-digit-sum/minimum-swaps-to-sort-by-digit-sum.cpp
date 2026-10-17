class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
      vector<pair<pair<int,int>,int>> m;
      vector<bool>vis(n,false);
        for (int i=0;i<n;i++)
        {
                   long long  temp=0;
                   int l=nums[i];
           while(l!=0)
           {
            int x=l%10;
            temp=temp+x;
            l/=10;
           }
          
        m.push_back({{temp, nums[i]},i});
        }
       sort(m.begin(), m.end());
        int count = 0;

for (int i = 0; i < n; i++)
{
    if (vis[i] || m[i].second == i)
        continue;

    int j = i;
    int c = 0;

    while (!vis[j])
    {
        vis[j] = true;
        j = m[j].second;
        c++;
    }

    if (c > 1)
        count += c - 1;
}

return count;
    }
};