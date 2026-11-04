class Solution {

    private:
       void dfs(vector<vector<int>>& adj,int node, vector<bool>& vis){
        vis[node]=true;
        for(int i=0;i<adj[node].size();i++){
            int neigh=adj[node][i];
            if(vis[neigh]==false){
                dfs(adj,neigh,vis);
            }
        }
       }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n);
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1 && i!=j){
                adj[i].push_back(j);
                
            }
        }
       }  int count =0;
       vector<bool>vis(n,false);
       for(int i=0;i<n;i++){
        if(vis[i]==false){
            count++;
            dfs(adj,i,vis);
        }
       }   
       return count;   
    }
};