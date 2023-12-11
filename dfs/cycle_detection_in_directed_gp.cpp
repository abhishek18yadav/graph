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
int  dfs(int node ,unordered_set<int>&visited , int strt , int end,vector<int>&par, bool ans){
    visited.insert(node);
    for(auto ele : gp[node]){
        if(visited.count(ele)){
            strt= ele;
            end=node;
            ans=1;
            res(strt,end , par);
            break;
        }
        par[ele]=node;
        dfs(ele, visited,strt,end,par, ans);
    }
}
// strt_cycle end-> end cycle
void c( int strt , int end){
    bool ans =0;
    unordered_set<int>visited;
    vector<int>par(v , -1);
    for(int i=0; i<v; i++){
        dfs(i, visited,strt , end,par,ans);
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
        add_edge(s,d,false);
    }
    int strt=-1;
    int end=-1;
    c(  strt ,  end);
    return 0;
}