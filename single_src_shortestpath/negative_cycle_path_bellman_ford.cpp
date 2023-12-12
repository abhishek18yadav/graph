#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<climits>
#include<queue>
#include<algorithm>
#include<unordered_set>
#define pp pair<int,int>
using namespace std;
int v;
vector<list<pp>>gp;
void add_edge(int src, int dst, int wt, bool bi_dir=true){
    gp[src].push_back({dst, wt});
    if(bi_dir){
        gp[dst].push_back({src, wt});
    }
}
void path_is(int x, vector<int>&par){
    vector<int>path;
    cout<<x<<endl;
    if(x!=-1){
        for(int i= x; ; i= par[i]){
            if(i==-1 and path.size()>1){
                break;
            }
            path.push_back(i);
        }
        reverse(path.begin(), path.end());
        cout<<"path is";
    for(auto ele : path){
        cout<<ele<<"->";
    }
    }
    
}
void cycle_detect(int src,int x){
    int total=0;
   unordered_map<int,int>mp;
   vector<int>par(v,-1);
   for(int i=0; i<v; i++){
    mp[i]= INT_MAX;
   }
   mp[src]=0;
   x=-1;
   for(int i=0; i<v; i++){
    for(auto ele: gp[i]){
        if(mp[ele.first]>ele.second+mp[i]){
            mp[ele.first]=ele.second+mp[i];
            par[ele.first]=i;
            x=ele.first;
        }
    }
   }
   path_is(x,par);
}
int main(){
    cin>>v;
    gp.resize(v, list<pp>());
    int e;
    cin>>e;
    while(e--){
        int s,d,wt;
        cin>>s>>d>>wt;
        add_edge(s,d,wt,false);
    }int src;
    cin>>src;
    int x=-1;
    cycle_detect(src ,x);
}