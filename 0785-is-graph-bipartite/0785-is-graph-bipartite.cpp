class Solution {
public:
bool evaluate(vector<vector<int>>& graph)
{
    int n = graph.size();

    vector<bool> visi(n, false);
    vector<int> color(n, -1);

    for(int i = 0; i < n; i++)
    {
        if(!visi[i])
        {
            queue<int> q;
            q.push(i);
            visi[i] = true;
            color[i] = 0;

            while(!q.empty())
            {
                int curr = q.front();
                q.pop();

                for(int v : graph[curr])
                {
                    if(!visi[v])
                    {
                        visi[v] = true;
                        color[v] = !color[curr];
                        q.push(v);
                    }
                    else
                    {
                        if(color[curr] == color[v])
                            return false;
                    }
                }
            }
        }
    }

    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
       return evaluate(graph);
    }
};
