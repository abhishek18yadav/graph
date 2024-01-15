#include<bits/stdc++.h>
using namespace std;

int v;
vector<list<int>>gp;

void add_edge(int src , int dst , bool bi_dir){
    gp[src].push_back(dst);
    if(bi_dir){
        gp[dst].push_back(src);
    }
}
void dsu(int src,vector<int>&par,vector<int>&rank){
    for(auto nei : gp[src]){
        if(par[nei]==par[src])continue;
        if(rank[nei]>rank[src]){
            par[src]=nei;
            rank[nei]++;
        }
        else{
            par[nei]=src;
            rank[src]++;
        }
    }
}
bool dfs(int node , unordered_set<int>&visited , vector<int>&par){
    visited.insert(node);
    for(auto ele : gp[node]){
        if(ele== par[node])continue;
        if(!visited.count(ele)){
            par[ele]=node;
            dfs(ele,visited,par);
        }
        else{
            return 1;
        }
    }
    return 0;
}
void f(){
    vector<int>par(v,-1);
    vector<int>rank(v,0);
    for(int i=0; i<v; i++){
        par[i]=i;

    }
    for(int i=0; i<v; i++){
        dsu(i, par,rank);
    }
    vector<int>com;
    com.push_back(par[0]);  
    // as believed that it will always start from 0;
    for(int i=0; i<v; i++){
        if(com[com.size()-1] != par[i]){
            com.push_back(par[i]);
        }
    }
    int noOfConnectedCom = com.size();
    for(int i=0;i<v; i++){
        //renewing par for reuse in dfs
        par[i]=-1;
    }
    int count=0;
    // this will count no of cyclic com
    unordered_set<int>visited;
    for(int i=0; i<com.size(); i++){
        if(!visited.count(com[i])){
            // dfs for checking cyclic 
            count+=dfs(i,visited,par);
        }
    }
    if(noOfConnectedCom>0){
        if(count>=noOfConnectedCom-1){
            cout<<"min no of days required to finish the road work is "<<count;
        }
    }
}
int main(){
    cin>>v;
    gp.resize(v,list<int>());
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d,true);
    }
    f();
    return 0;
}