class Solution {
public:
    bool dfs (int src, int desti, list<int> l[], vector<bool>&visited)
    {
        if(src==desti)
        {
            return true;
        }
        visited[src]=true;
        //list<int>neighbour=l[src];

        for(int v : l[src])
        {
            if(!visited[v])
            {
                if(dfs(v,desti,l,visited))
                {
                    return true ;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
       list<int > li[n];
       for(auto edge : edges)
       {
        int u=edge[0];
        int v=edge[1];
        li[u].push_back(v);
        li[v].push_back(u);
       }
        vector<bool> visited(n,false);
       return dfs(source,destination,li,visited);

    }
};