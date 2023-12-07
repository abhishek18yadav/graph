#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<deque>
#include<climits>
#define pp pair<int,int>
using namespace std;

vector<list<pp>>gp;
int v;

void add_edge(int src, int dst, bool bi_dir=true){
    gp[src].push_back({dst,0});
    if(bi_dir){
        gp[dst].push_back({src,1});
    }
}
void total_brake_change(int src,int dst){
    int count=0;
    unordered_map<int,int>mp;
    for(int i=0; i<v; i++){
        mp[i]= INT_MAX;
    }
    mp[src]=0;
    deque<pp>q;
    q.push_front({0,src});
    while(!q.empty() and count<v){
        pp node= q.front();
        q.pop_front();
        for(auto ele : gp[node.second]){
            if(mp[ele.first]>mp[node.second]+ ele.second){
                mp[ele.first]=mp[node.second ]+ ele.second;
                if(ele.second==0){
                    q.push_front({ele.second, ele.first});
                }
                if(ele.second==1){
                    q.push_back({ele.second, ele.first});
                }
                count++;
            }
        }
    }
    cout<<mp[dst];
}
int main(){
    cin>>v;
    gp.resize(v, list<pp>());
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d,true);
    }
    int src,dst;
    cin>>src>>dst;
    total_brake_change(src,dst);
    return 0;
}