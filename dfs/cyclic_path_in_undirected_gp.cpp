#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<unordered_set>
using namespace std;

int v;
vector<list<int>>gp;

void add_edge(int src, int dst , bool bi_dir=true){
    gp[src].push_back(dst);
    if(bi_dir){
        gp[dst].push_back(src);
    }
}
void res(int strt, int end,vector<int>&par){
    // cout<<strt<<end;
    vector<int>path;
    for(int i=end;i!= strt; i=par[i]){
        path.push_back(i);
    }
    path.push_back(strt);
    reverse(path.begin(), path.end());
    for(auto ele : path){
        cout<<ele<<"->";
    }
}
int  dfs(int node ,unordered_set<int>&visited , int strt , int end,vector<int>&par, int p){
    visited.insert(node);

    for(auto ele : gp[node]){
        if(ele==p)continue;
        if(visited.count(ele)){
            strt= ele;
            // cout<<strt;
            end=node;
            res(strt,end , par);
            break;
        }
        par[ele]=node;
        dfs(ele, visited,strt,end,par, node);
    }
}
// strt_cycle end-> end cycle
void cycle_detection( int strt , int end){
    int p =-1;
    unordered_set<int>visited;
    vector<int>par(v , -1);
    for(int i=0; i<v; i++){
        dfs(i, visited,strt , end,par,p);
        break;
    }
  
    cout<<endl;
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
    int strt=-1;
    int end=-1;
    cycle_detection(  strt ,  end);
    return 0;
}