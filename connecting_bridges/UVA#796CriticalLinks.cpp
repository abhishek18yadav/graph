<<<<<<< HEAD
#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std;

vector<list<int>>gp;
int v;
unordered_map<int , int >mp;
priority_queue<int , vector<int>, greater<int>>pq;
void add_edge(int src, int dst , bool bi_dir){
    gp[src].push_back(dst);
    if(bi_dir){
        gp[dst].push_back(src);
    }
}
void f(int node , int nei ){
    mp[node]=nei;
    pq.push(node);
}
void dfs(int node , unordered_set<int>&visited,vector<int>&ten, vector<int>&low, int parent , int time){
    visited.insert(node);
    ten[node]= low[node]= time++;
    for(auto nei : gp[node]){
        if(nei == parent)continue;
        if(visited.count(nei)){
            low[node]= min(ten[nei] , low[node]);
        }
        else{
            dfs(nei, visited, ten , low, node, time);
            low[node]= min(low[node], low[nei]);
            if(ten[node]< low[nei]){
                f(node, nei);
            }
        }
    }
}
void find(){
    vector<int>ten(v, -1);
    vector<int>low(v, -1);
    int time=-1;
    unordered_set<int>visited;
    for(int i=0; i<v; i++){
        if(!visited.count(i)){
            dfs(i, visited , ten , low, i, time);
        }
    }
}
void result(){
    while(!pq.empty()){
        cout<<pq.top()<<"-"<<mp[pq.top()]<<" ";
        pq.pop();
    }
}
int main(){
    cin>>v;
    gp.resize(v , list<int>());
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s , d, true);
    }
    find();
    result();
    return 0;
=======
#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std;

vector<list<int>>gp;
int v;
unordered_map<int , int >mp;
priority_queue<int , vector<int>, greater<int>>pq;
void add_edge(int src, int dst , bool bi_dir){
    gp[src].push_back(dst);
    if(bi_dir){
        gp[dst].push_back(src);
    }
}
void f(int node , int nei ){
    mp[node]=nei;
    pq.push(node);
}
void dfs(int node , unordered_set<int>&visited,vector<int>&ten, vector<int>&low, int parent , int time){
    visited.insert(node);
    ten[node]= low[node]= time++;
    for(auto nei : gp[node]){
        if(nei == parent)continue;
        if(visited.count(nei)){
            low[node]= min(ten[nei] , low[node]);
        }
        else{
            dfs(nei, visited, ten , low, node, time);
            low[node]= min(low[node], low[nei]);
            if(ten[node]< low[nei]){
                f(node, nei);
            }
        }
    }
}
void find(){
    vector<int>ten(v, -1);
    vector<int>low(v, -1);
    int time=-1;
    unordered_set<int>visited;
    for(int i=0; i<v; i++){
        if(!visited.count(i)){
            dfs(i, visited , ten , low, i, time);
        }
    }
}
void result(){
    while(!pq.empty()){
        cout<<pq.top()<<"-"<<mp[pq.top()]<<" ";
        pq.pop();
    }
}
int main(){
    cin>>v;
    gp.resize(v , list<int>());
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s , d, true);
    }
    find();
    result();
    return 0;
>>>>>>> 905a760eeb143bd0b8639bd79f99f6e43fa9e68b
}