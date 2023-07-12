class Solution {
public:

    bool dfs(vector<vector<int>> &graph,vector<int> &color,int currNode){
        if(color[currNode] != 0)return color[currNode] == 1;

        color[currNode] = 2;

        for(int &adjNode : graph[currNode]){
            if(!dfs(graph,color,adjNode))return false;
        }

        color[currNode] = 1;

        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<int> color(n);

        for(int i = 0;i < n;i++){
            if(dfs(graph,color,i))
                ans.push_back(i);
        }

        return ans;
    }
};

// question is similar to topological sorting logic we use in graph
// if there exist a cyclic path from a node then all nodes present
// in the cyclic path are unsafe nodes
// and all nodes from which all path leads to a terminal node or that path
// is noncyclic then all such nodes are safe
// the above logic is considered while solving the question using dfs
// the above logic is similar to topological sort logic in graph
// so topoplogical sorting is only possible for a acyclic graph
// question can be solved using bfs too we need to consider outdegree for 
// each node and then for zero outdegree nodes traverse to other nodes in 
// graph simultaneously reducing outdgree for each currnode as we traverse
// if for currNode the outdegree is zero it is marked as safe node