#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<climits>
#include<unordered_map>
#define pp pair<int,int>
using namespace std;

int v;
vector<list<pp>>gp;

void add_edge(int src, int dst,int wt, bool bi_dir=true){
    gp[src].push_back({dst,wt});
    if(bi_dir){
        gp[dst].push_back({src,wt});
    }
}
void zero_one_bfs(int src){
    int total =0, count_wt=0;
    unordered_map<int,int>mp;
    for(int i=0; i<v; i++){
        mp[i]=INT_MAX;
    }
    mp[src]=0;
    deque<pp>q;
    q.push_front({0,src});
    while(!q.empty() and total<v){                       // q.fir = wt   q.sec= vertex
        pp node = q.front();
        q.pop_front();
        for(auto ele:gp[node.second]){
            if(mp[ele.first]>ele.second+mp[node.second]){ // ele.sec =wt   ele.fist = vertex
                total++;
                mp[ele.first]=ele.second+mp[node.second];
                if(ele.second==0){
                    q.push_front({ele.first,ele.second});
                }else{
                    q.push_back({ele.first,ele.second});
                }
                total+=node.first;
            }
        }
    }
    cout<<total<<endl;
}
int main(){
    cin>>v;
    gp.resize(v, list<pp>());
    int e;
    cin>>e;
    while(e--){
        int s,d,wt;
        cin>>s>>d>>wt;
        add_edge(s,d,wt,true);
    }int src;
    cin>>src;
    zero_one_bfs(src);
    return 0;
}