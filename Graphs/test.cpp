// //{ Driver Code Starts
// #include <bits/stdc++.h>
// using namespace std;

// // } Driver Code Ends
// class Solution {
//   public:
//     // Function to return a list containing the DFS traversal of the graph.
//     void dfs(vector<int>&ans,map<int,bool>&visited,vector<int>adj[],int node){
//         ans.push_back(node);
//         visited[node]=true;
//         for (auto neighbour:adj[node]){
//             if(!visited[neighbour]){
//                 ans.push_back(neighbour);
//             }
//         }
        
//     }
//     vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
//         vector<int >ans;
//         map<int,bool>visited;
//         for(int i=0;i<V;i++){
//            dfs(ans,visited,adj,i);
//         }
//     }
// };

// //{ Driver Code Starts.
// int main() {
//     int tc;
//     cin >> tc;
//     while (tc--) {
//         int V, E;
//         cin >> V >> E;

//         vector<int> adj[V];

//         for (int i = 0; i < E; i++) {
//             int u, v;
//             cin >> u >> v;
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         // string s1;
//         // cin>>s1;
//         Solution obj;
//         vector<int> ans = obj.dfsOfGraph(V, adj);
//         for (int i = 0; i < ans.size(); i++) {
//             cout << ans[i] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }
// // } Driver Code Ends

#include<bits/stdc++.h>
using namespace std;


int main(){


    cout<<"जय श्री हनुमान ने सीना फारा सीता राम मेरे भीतर है बोलो जय श्री राम"<<endl;
    return 0;
}