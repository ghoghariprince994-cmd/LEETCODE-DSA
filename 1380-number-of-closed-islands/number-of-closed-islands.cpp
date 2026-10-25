class Solution {
public:
bool help(vector<vector<int>>& grid,int i,int j, vector<vector<bool>>&vis)
{
          
    int n = grid.size();
    int m = grid[0].size();

    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;

    if (grid[i][j] == 1 || vis[i][j])
        return true;

    vis[i][j] = true;

    bool a = help(grid, i, j + 1, vis);
    bool b = help(grid, i + 1, j, vis);
    bool c = help(grid, i, j - 1, vis);
    bool d = help(grid, i - 1, j, vis);

    return a && b && c && d;
      

}
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               if(grid[i][j] == 0 && !vis[i][j] && help(grid,i,j,vis))
{
    count++;
}
            }
        }
        return count;
    }
};