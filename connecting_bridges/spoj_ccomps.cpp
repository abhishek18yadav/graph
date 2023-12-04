#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;

int v;
vector<list<int>>gp;

void add_edge(int src, int dst, bool bi_dir=true){
    gp[src].push_back(dst);
    if(bi_dir){
        gp[dst].push_back(src);
    }
}
void bfs(int node,unordered_set<int>&visited){
    
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int w=q.front();
        visited.insert(w);
        q.pop();
        for(auto ele: gp[w]){
            if(!visited.count(ele)){
                q.push(ele);
            }
        }
    }
}
void no_of_components(){
    int count=0;
    unordered_set<int>visited;
    for(int i=0; i<v; i++){
        if(!visited.count(i)){
            count++;
            bfs(i,visited);
        }
    }
    cout<<"no_of_connected_com"<<count<<endl;
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
    no_of_components();
}