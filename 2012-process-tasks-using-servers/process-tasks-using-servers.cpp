class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q1;
        priority_queue<pair<long long, pair<int, int>>,
                       vector<pair<long long, pair<int, int>>>,
                       greater<pair<long long, pair<int, int>>>>
            q2;
        vector<int> res(tasks.size());

        for (int i = 0; i < servers.size(); i++) {
            q1.push({servers[i], i});
        }

        long long time = 0;

        for (int i = 0; i < tasks.size(); i++) {
            time = max(time, (long long)i);
            while (!q2.empty() && q2.top().first <= time) {
                auto x = q2.top();
                q2.pop();
                q1.push({x.second.first, x.second.second});
            }

            if (q1.empty())

            {
                time = q2.top().first;

                while (!q2.empty() && q2.top().first <= time) {
                    auto x = q2.top();
                    q2.pop();
                    q1.push({x.second.first, x.second.second});
                }
            }

            auto c = q1.top();
            q1.pop();
            res[i] = c.second;
            q2.push({time + tasks[i], {c.first, c.second}});
        }
        return res;
    }
};