class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<int> res(queries.size());

        vector<pair<int,int>> q;
        for(int i = 0; i < queries.size(); i++)
            q.push_back({queries[i], i});

        sort(q.begin(), q.end());

        sort(logs.begin(), logs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        int i = 0;
        int m = queries.size();
        int left = 0, right = 0;
        int active = 0;

        vector<int> freq(n + 1, 0);

        while(i < m)
        {
            int l = q[i].first - x;
            int u = q[i].first;

            while(right < logs.size() && logs[right][1] <= u)
            {
                int id = logs[right][0];

                if(freq[id] == 0)
                    active++;

                freq[id]++;
                right++;
            }

            while(left < right && logs[left][1] < l)
            {
                int id = logs[left][0];

                freq[id]--;

                if(freq[id] == 0)
                    active--;

                left++;
            }

            res[q[i].second] = n - active;
            i++;
        }

        return res;
    }
};