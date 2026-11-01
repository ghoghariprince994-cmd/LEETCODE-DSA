class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        long long count=0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++)
        {
           long long temp=nums[i]-nums[0];
           count+=temp;
                    
        }
        return count;
    }
};