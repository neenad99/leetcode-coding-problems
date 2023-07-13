class Solution {
public:

    bool dfs(vector<int> adj[],vector<bool> &vis,vector<int> &rec,vector<int> &ans,int currNode){
        vis[currNode] = true;
        rec[currNode] = true;

        for(int &adjNode : adj[currNode]){
            if(!vis[adjNode]){
                if(!dfs(adj,vis,rec,ans,adjNode))return false;
            }
            else{
                if(rec[adjNode])return false;
            }
        }

        rec[currNode] = false;
        ans.push_back(currNode);

        return true;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        vector<bool> vis(n,false);
        vector<int> rec(n);
        vector<int> ans;

        for(vector<int> &dependencies : prerequisites){
            adj[dependencies[1]].push_back(dependencies[0]);
        }

        for(int i = 0;i < n;i++){
            if(!vis[i]){
                bool res = dfs(adj,vis,rec,ans,i);
                if(!res)return false;
            }
        }

        return true;
    }
};