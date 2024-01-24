#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,int>

int v;
vector<list<pp>>gp;

void add_edge(int src, int dst,int wt, bool bi_dir=true){
    gp[src].push_back({dst,wt});
    if(bi_dir){
        gp[dst].push_back({src,wt});
    }
}
//no need of via , so may be not present
void dijkstra(int src, int dst, int targetsum){
    int updatedsrc=0,updateddst=0;
    unordered_set<int>visited;
    unordered_map<int,int>mp;
    for(int i=0; i<v; i++){
        mp[i]=INT_MAX;
    }mp[src]=0;
    priority_queue<pp>pq;
    pq.push({0,src});
    int totalvert=0,totalsum=0;
    while(!pq.empty() and totalvert<=v){
        pp node= pq.top();
        if(visited.count(node.second)){
            pq.pop();
            continue;
        }
        visited.insert(node.second);
        totalsum+=node.first;
        totalvert++;
        for(auto nei : gp[node.second]){
            if(!visited.count(nei.first) and mp[nei.first]>nei.second+mp[node.second]){
                if(nei.first==dst){
                    updatedsrc= node.second;
                    updateddst= nei.first;
                    break;
                }
                mp[nei.first]=nei.second+mp[node.second];
                pq.push({nei.second,nei.first});
            }
        }
        if(updateddst!=0 and updatedsrc!=0){
            cout<<targetsum-totalsum<<" ";
            gp[updatedsrc].push_back({updateddst,targetsum-totalsum});
            gp[updateddst].push_back({updatedsrc,targetsum-totalsum});
            break;
        }
    }
}
int main(){
    cin>>v;
    gp.resize(v,list<pp>());
    int e;
    cin>>e;
    while(e--){
        int s,d,wt;
        cin>>s>>d>>wt;
        add_edge(s,d,wt,true);
    }
    int src,dst,targetsum;
    cin>>src>>dst>>targetsum;
    dijkstra(src,dst,targetsum);
    return 0;
}