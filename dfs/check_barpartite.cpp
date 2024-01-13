#include<bits/stdc++.h>
using namespace std;

int v;
vector<list<int>>gp;
void add_edge(int src , int dst , bool bi_dir=true){
    gp[src].push_back(dst);
    if(bi_dir){
        gp[dst].push_back(src);
    }
}
bool check_barpartite(int src){
    unordered_map<int,int>mp;
    for(int i=0; i<v; i++){
        mp[i]=-1;
    }unordered_set<int>visited;
    queue<int>q;
    q.push(src);
    visited.insert(src);
    mp[src]=0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto ele : gp[node]){
            if(!visited.count(ele)){
                visited.insert(ele);
                if(mp[node]==1)mp[ele]=0;
                if(mp[node]==0)mp[ele]=1;
                q.push(ele);
            }
            else{
                if(mp[node]==mp[ele]){
                    return 0;
                }
            }
        }
    }
    return 1;
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
    cout<<check_barpartite(0);
    return 0;
}