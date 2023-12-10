#include<iostream>
#include<vector>
#include<list>
#include<climits>
#include<unordered_map>
#include<queue>
#define pp pair<int,int>
using namespace std;

int v;
vector<list<pp>>gp;

void add_edge(int src, int dst, int wt, bool bi_dir=true){
    gp[src].push_back({dst,wt});
    if(bi_dir){
        gp[dst].push_back({src,wt});
    }
}
int f(int src,int dst){
    priority_queue<pp>pq;
    unordered_map<int,int>mp;
    for(int i=0; i<v; i++){
        mp[i]=INT_MAX;
    }
    mp[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        pp node = pq.top();
        pq.pop();
        for(auto ele: gp[node.second]){
           if(mp[ele.first]>ele.second+ mp[node.second]){
                mp[ele.first]=ele.second+ mp[node.second];
                pq.push({ele.second,ele.first});
            }
        }
    }
    cout<<mp[dst];
    cout<<" ";
}
int main(){
    cin>>v;
    gp.resize(v,list<pp>());
    int e;
    cin>>e;
    while(e--){
        int s,d,wt;
        cin>>s>>d>>wt;
        add_edge(s,d,wt, true);
    }
    for(int j=0; j<v; j++){
    for(int i=0; i<v; i++){
        if(i==j){
            cout<<0<<"";
        }
        f(j,i);
    }
    cout<<endl;
    }
    return 0;
}
