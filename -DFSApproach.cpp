class Solution {
public:
    bool  bp(int node,vector<vector<int>>& graph,vector<int>&visit)
    {
        for(auto child:graph[node])
        {
            if(visit[child]==-1)
            {
                visit[child]=1-visit[node];
                if(bp(child,graph,visit))return true;
            }
            else
            {
                if(visit[child]==visit[node])
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>visit(graph.size(),-1);
        for(int i=0;i<graph.size();i++)
        {
            if(visit[i]==-1)
            {
                visit[i]=1;
                if(bp(i,graph,visit)){return false;}
            }
        }
        return true;
    }
};
