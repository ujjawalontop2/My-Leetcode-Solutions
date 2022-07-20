class Solution {
public:
   int vis[101];
    void dijkstra(int k,int n,vector<pair<int,int>> adj[],vector<int> &dist){
        set<pair<int,int>> st;
        st.insert({0,k});
        dist[k]=0;
        
        while(st.size()>0){
            auto node =*st.begin();
            int v=node.second;
            int v_dist=node.first;
            st.erase(st.begin());
            
            if(vis[v]) continue;
            vis[v]=1;
            
            for(auto child : adj[v]){
                int child_v=child.first;
                int child_wt=child.second;
                
                if(dist[v]+child_wt < dist[child_v]){
                   dist[child_v] =dist[v]+child_wt;
                    st.insert({dist[child_v],child_v});
                }
                
            }
        }
        
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        memset(vis,0,sizeof(vis));
       vector<int> dist(n+1,INT_MAX);
        vector<pair<int,int>> adj[n+1];
        
        for(auto x:times){
            adj[x[0]].push_back({x[1],x[2]});
        }
        
      dijkstra(k,n,adj,dist);
        int ans=-1;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            
            ans=max(ans,dist[i]);
        }
        
        return ans;
    }
};