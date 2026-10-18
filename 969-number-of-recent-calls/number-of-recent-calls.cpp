class RecentCounter {
public:
 vector<int>temp;
    RecentCounter() {
        temp.resize(2);
    }
   
    
    queue<int>q;
   
    int ping(int t) {
        q.push(t);
        temp[0]=t-3000;
        temp[1]=t;
        while(q.front()<temp[0])
        {
          q.pop();
         
        }
        return q.size();

    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */