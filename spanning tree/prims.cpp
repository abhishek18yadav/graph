#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<list>
#include<climits>
using namespace std;
#define pp pair<int,int>

vector<list<pp>>gp;
int v;
void add_edge(int src, int dst,int wt, bool bi_dir){
    gp[src].push_back({dst,wt});
    if(bi_dir){
        gp[dst].push_back({src, wt});
    }
}
void prims(int src){
    int res=0, total=0;
    unordered_map<int,int>mp;
    for(int i=0; i<v; i++){
        mp[i]=INT_MAX;
    }
    priority_queue<pp,vector<pp>, greater<pp>>pq;
    pq.push({0,src});
    mp[src]=0;
    unordered_set<int>visited;
    while(total<=v and !pq.empty()){
        pp node = pq.top();
        if(visited.count(node.second)){
            pq.pop();
            continue;
        }pq.pop();
        total++;
        res+=node.first;
        visited.insert(node.second);
        for(auto nei : gp[node.second]){
            if(!visited.count(nei.first) and mp[nei.first]>nei.second){
                mp[nei.first]= nei.second;
                pq.push({nei.second, nei.first});
            }
        }
    }
    cout<<res<<endl;
}
int main(){
    cin>>v;
    gp.resize(v,list<pp>());
    int e;
    cin>>e;
    while (e--)
    {
        int s, d,wt;
        cin>>s>>d>>wt;
        add_edge(s,d,wt, true);
    }
    int src;
    cin>>src;
    prims(src);
    return 0;
}
