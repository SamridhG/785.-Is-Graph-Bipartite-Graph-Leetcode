class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>colorvisit(graph.size(),-1);
        for(int i=0;i<graph.size();i++)
        {
            if(colorvisit[i]==-1)
            {
                queue<int>q;
                q.push(i);
                colorvisit[i]=1;
                while(!q.empty())
                {
                    int node=q.front();
                    q.pop();
                    for(auto s:graph[node])
                    {
                        if(colorvisit[s]==-1)
                        {
                            colorvisit[s]=1-colorvisit[node];
                            q.push(s);
                        }
                        else
                        {
                            if(colorvisit[s]==colorvisit[node])
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
