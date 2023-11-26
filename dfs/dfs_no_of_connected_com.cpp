#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

vector<list<int>>grp;
int v;

void add_edge(int src, int dst, bool bi_dir=true){
    grp[src].push_back(dst);
    if(bi_dir){
        grp[dst].push_back(src);
    }
}

void dfs(int node, unordered_set<int>&visited){
    visited.insert(node);
    cout<<node<<"->";
    for(auto nei : grp[node]){
       if(!visited.count(nei)){
        dfs(nei, visited);
        } 
    }
   
    cout<<endl;
}
void con(){
    int gp=0;
    unordered_set<int>visited;
    for(int i=0; i<grp.size(); i++){
        if(!visited.count(i)){
            gp++;
            dfs(i , visited);
        }
        else continue;
    }
    cout<<"no_of_gps"<<gp<<endl;
}
int main(){
    cin>>v;
    grp.resize(v, list<int>());
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d,true);
    }
    con();
    return 0;
}