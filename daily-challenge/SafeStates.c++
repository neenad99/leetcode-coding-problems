class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adjList(n);
        queue<int> q;
        vector<int> outDegree(n);
        vector<int> ans,safe(n);

        for(int i = 0;i < n;i++){
            for(int &adjNode : graph[i]){
                adjList[adjNode].push_back(i);
            }
            outDegree[i] = graph[i].size();
            if(outDegree[i] == 0)q.push(i);
        }


        while(!q.empty()){
            int currNode = q.front();
            safe[currNode] = 1;
            q.pop();

            for(int &adjNode : adjList[currNode]){
                if(--outDegree[adjNode] == 0){
                    q.push(adjNode);
                }
            }
        }
        
        for(int i = 0;i < n;i++)
            if(safe[i])ans.push_back(i);

        return ans;
    }
};