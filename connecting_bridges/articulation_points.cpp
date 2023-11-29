#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

vector<list<int>>gp;
int v;
void add_edge(int src, int dst, bool bi_dir){
    gp[src].push_back(dst);
    if(bi_dir){
        gp[dst].push_back(src);
    }
}
void f(int node,unordered_set<int>&ans){
    ans.insert(node);
}
void dfs(int node, unordered_set<int>&visited,vector<int>&ten, vector<int>&low, vector<int>&par, int time){
    visited.insert(node);
    int child=0;
    unordered_set<int>ans;
    low[node]=ten[node]=time++;
    for(auto nei : gp[node]){
        if(nei==par[nei])continue;
        if(visited.count(nei)){
            low[node]= min(low[node], ten[nei]);
        }
        else{
            par[nei]=node;
            dfs(nei, visited, ten, low,par,time);
            low[node]= min(low[node], low[nei]);
            if(par[nei]!=-1 and low[nei]>=ten[node]){
                f(node, ans);
            }
            child++;
        }
    }
    // if(par[node]==-1 and child>1){
    //     cout<<node<<" ";
    // }
    for(auto ele= ans.begin(); ele != ans.end(); ele++){
        cout<<*ele<<" ";
    }

}
void articulation_points(){
    int time=-1;
    vector<int>ten(v,-1);
    vector<int>low(v,-1);
    vector<int>par(v,-1);
    unordered_set<int>visited;
    for(int i=0; i<v; i++){
        if(!visited.count(i)){
            dfs(i,visited,ten,low,par,time);
        }
    }
}
int main(){
    cin>>v;
    gp.resize(v, list<int>());
    int e;
    cin>>e;
    while(e--){
        int s, d;
        cin>>s>>d;
        add_edge(s,d,true);
    }
    articulation_points();
    return 0;
}