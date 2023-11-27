#include<iostream>
#include<vector>
#include<unordered_set>
#include<list>

/**
 * ten - first time node visited;
 * low - shortest time in visiting node
 * // targans algo
 * 
*/
using namespace std;

vector<list<int>>gp;
int v;
void add_edge(int src, int dst, bool bi_dir= true){
    gp[src].push_back(dst);
    if(bi_dir){
        gp[dst].push_back(src);
    }
}
void dfs(int node , unordered_set<int>&visited,vector<int>&ten,vector<int>&low, int time , int parent){
    visited.insert(node);
    low[node]=ten[node]=time++;
    for(auto nei : gp[node]){
        if(nei==parent)continue;
        if(visited.count(nei)){
            low[node]= min(low[node], ten[nei]);
        }
        else{   
            dfs(nei,visited, ten,low,time, node);
            low[node]=min(low[node], low[nei]);
            if(ten[node]< low[nei]){
                cout<<node<<nei<<" ";
            }
        }
    }
}
void find_edges(){
    int time=-1;
    unordered_set<int>visited;
    vector<int>ten(v,-1);
    vector<int>low(v,-1);
    for(int i=0; i<v; i++){
        if(!visited.count(i)){
            dfs(i , visited , ten, low, time, i);
        }
    }
}
int main(){
    cin>>v;
    gp.resize(v, list<int>());
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d, true);
    }
    find_edges();
    return 0;
}