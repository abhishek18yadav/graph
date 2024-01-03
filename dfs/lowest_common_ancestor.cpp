#include<bits/stdc++.h>
using namespace std;
//always start with 0
//distance means height or level of tree
// tour is euler tour
// fst is first occurence of element
int v;
vector<list<int>>gp;
void add_edge(int src , int dst , bool bi_dir= true){
    gp[src].push_back(dst);
    if(bi_dir){
        gp[dst].push_back(src);
    }
}
int find_parent(int node,vector<int>&parent){
    if(node == parent[node])return node;
    return find_parent(parent[node],parent);
}
void f2(int v1,int v2,vector<int>&distance , vector<int>&tour , vector<int>&fst ,vector<int>&parent){
    int idx1= fst[v1];
    int idx2 = fst[v2];
    int minv=INT_MAX;
    int res=0;
    for(int i= idx1; i<=idx2; i++){
        if(minv>distance[i]){
            minv=distance[i];
            res=i;
        }
    }
    cout<<"previus ancestor is "<<tour[res]<<endl;
    cout<<"lowest common ancestor is"<<find_parent(tour[res],parent)<<endl;
}
void dfs(int node ,unordered_set<int>&visited ,unordered_map<int,int>&mp,vector<int>&distance , vector<int>&tour , vector<int>&fst, vector<int>&parent){
    fst[node]=tour.size()-1;
    visited.insert(node);
    for(auto ele: gp[node]){
        if(!visited.count(ele)){
            parent[ele]=node;
            mp[ele]= mp[node]+1;
            distance.push_back(mp[ele]);
            tour.push_back(ele);
            dfs(ele,visited,mp,distance,tour,fst, parent);
            tour.push_back(node);
            distance.push_back(mp[node]);
        }
    }
}
void f(int v1,int v2){
    unordered_set<int>visited;
    unordered_map<int,int>mp;
    for(int i=0; i<v; i++){
        mp[i]=0;
    }
    vector<int>fst(v,0);
    vector<int>parent(v,0);
    vector<int>tour;
    tour.push_back(0);
    vector<int>distance;
    distance.push_back(0);
    for(int i=0; i<v; i++){
        if(!visited.count(i)){
            dfs(i,visited,mp,distance,tour,fst , parent);
        }
    }
    f2(v1,v2,distance,tour,fst, parent);
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
    int v1,v2;
    cin>>v1>>v2;
    f(v1,v2);
}