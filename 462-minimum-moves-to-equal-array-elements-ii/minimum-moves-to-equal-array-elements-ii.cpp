class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        sort(nums.begin(),nums.end());
       
        for(int i=0;i<n/2;i++)
        {
           long long temp= nums[n/2]-nums[i];
          ans+=temp;
        }
        for(int j=n-1;j>=n/2;j--)
        {
           long long temp=nums[j]-nums[n/2];
           ans+=temp;
        }
       
        return ans;
    }
};