class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);

        // build the graph 
        for(vector<int> &x : invocations)
        {
            graph[x[0]].push_back(x[1]);

        }

        vector<bool> visited(n,false);
        queue<int> q;

        q.push(k);
        visited[k]=true;

        while(!q.empty())
        {
            int node =q.front();
            q.pop();

            for(int next : graph[node])
            {
                if(!visited[next])
                {
                    visited[next]=true;
                    q.push(next);

                }
            }
        }

        for(vector<int > &x : invocations)
        {
            int u=x[0];
            int v=x[1];

            if(!visited[u] && visited[v])
            {
                vector<int > ans;
                for(int i=0;i<n;i++)
                {
                    ans.push_back(i);
                }
                return ans;
            }
        }

     vector<int > ans;
        for(int i=0;i<n;i++)
        {

            if(!visited[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};