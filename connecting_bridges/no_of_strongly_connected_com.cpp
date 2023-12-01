#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;
int v;

void add_edge(vector<int>gp[],int src, int dst, bool bi_dir=true){
    gp[src].push_back(dst);
    if(bi_dir){
        gp[dst].push_back(src);
    }
}
void rev(vector<int>gp[],vector<int>Tgp[]){
    for(int i=0; i<v; i++){
        for(auto ele: gp[i]){
            Tgp[ele].push_back(i);
        }
    }
}
void dfs(int node, vector<int>gp[],vector<bool>&visited,stack<int>&st){
    visited[node]= true;
    for(auto ele: gp[node]){
        if(!visited[ele]){
            dfs(ele, gp, visited, st);
        }
    }
    st.push(node);
}
void dfs2(int node,vector<bool>&visited,vector<int>Tgp[]){
    visited[node]= true;
    for(auto ele : Tgp[node]){
        if(!visited[ele]){
            dfs2(ele, visited,Tgp);
        }
    }
}
void ans(stack<int>&st, vector<int>Tgp[],vector<bool>&visited){
    int scc=0;
    while(!st.empty()){
        if(!visited[st.top()]){
            scc++;
            dfs2(st.top(),visited, Tgp);
        }
        st.pop();
    }
    cout<<scc<<endl;
}
void sc(vector<int>gp[],vector<int>Tgp[]){
    stack<int>st;
    vector<bool>visited(v,0);
    for(int i=0; i<v; i++){
        if(!visited[i]){
            dfs(i, gp, visited,st);
        }
    }
    rev(gp,Tgp);
    visited.clear();
    visited.resize(v,0);
    ans(st,Tgp,visited);

}

int main(){
    cin>>v;
    vector<int>gp[v];
    vector<int>Tgp[v];

    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge( gp,s, d, false);
    }
    sc(gp,Tgp);
    return 0;
}
