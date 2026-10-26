class Solution {
public:
long long  help(vector<vector<int>>& grid,int i,int j, int k,vector<vector<bool>>&vis)
{
    int n=grid.size();
    int m=grid[0].size();
    if(i<0 || i>=n || j<0 ||j>=m ||vis[i][j] || grid[i][j]==0)
    {
        return 0;
    }
    
    vis[i][j]=true;
  long long a= help(grid,i,j+1,k,vis);
   long long b= help(grid,i+1,j,k,vis);
   long long c= help(grid,i,j-1,k,vis);
   long long d= help(grid,i-1,j,k,vis);
  

  return a+b+c+d+grid[i][j];
}
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
    int m=grid[0].size();
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    int a=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j] && grid[i][j]!=0)
            {
              long long l=  help(grid,i,j,k,vis);
              if(l%k==0)
              {
                a++;
              }
            }
          
        }
    }
    return a;

    }
};