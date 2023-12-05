#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<climits>
#define pp pair<int,int>
using namespace std;

int v;
vector<list<pp>>gp;
void add_edge(int src, int dst, int wt, bool bi_dir){
    gp[src].push_back({dst, wt});
    if(bi_dir){
        gp[dst].push_back({src,wt});
    }
}
void prims(int src){
    int total=0,res=0;
    priority_queue<pp>pq;
    vector<int>via(v,0);
    unordered_map<int, int>mp;
    for(int i=0; i<v; i++){
        mp[i]=INT_MAX;
    }
    unordered_set<int>visited;
    mp[src]=0;
    pq.push({0,src});
    while(total<=v and !pq.empty()){
        pp node = pq.top();
        if(visited.count(node.second)){
            pq.pop();
            continue;
        }
        pq.pop();
        res+=node.first;
        total++;
        visited.insert(node.second);
        for(auto ele : gp[node.second]){
            if(!visited.count(ele.first) and mp[ele.first]> mp[node.second]+ ele.second){
                pq.push({ele.second, ele.first});
                mp[ele.first]= ele.second + mp[node.second];
                via[ele.first]= node.second;
            }
        }
    }
    cout<<res<<endl;
    for(int i=0; i<v; i++){
        cout<<via[i]<<"->";
    }
}
int main(){
    cin>>v;
    gp.resize(v, list<pp>());
    int e;
    cin>>e;
    while(e--){
        int s,d,wt;
        cin>>s>>d>>wt;
        add_edge(s,d,wt, true);
    }
    int src;
    cin>>src;
    prims(src);
    return 0;
}
