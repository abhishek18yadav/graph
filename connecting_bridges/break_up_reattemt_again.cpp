#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<climits>
#include<unordered_set>
using namespace std;
#define pp pair<int,int>

vector<list<pp>>gp;
int v;
// vector<list<pp>>gp;

void add_edge(int src, int dst, int wt,bool bi_dir=true){
    gp[src].push_back({dst,wt});
    if(bi_dir){
        gp[dst].push_back({src,wt});
    }
}
void dfs(int node, vector<int>&ten, vector<int>&low, int time, unordered_set<int>&visited, int parent,vector<int>&ans){
    ten[node]= low[node]= time++;
    visited.insert(node);
    for(auto ele : gp[node]){
        if(ele.first == parent)continue;
        if(visited.count(ele.first)){
            low[node]= min(low[node], ten[ele.first]);
        }
        else{
            dfs(ele.first, ten,low,time,visited,node,ans);
            low[node]= min(low[node], low[ele.first]);
            if(ten[node]<low[ele.first]){
                ans.push_back(node);
            }
        }
    }
}
vector<int> f(){
    vector<int>ten(v, -1);
    vector<int>low(v, -1);
    vector<int>ans;
    int time=-1;
    unordered_set<int>visited;
    for(int i=0; i<v; i++){
        if(!visited.count(i)){
            dfs(i, ten , low, time, visited , i,ans);
        }
    }
    return ans;
}
// void dfs1(int node, unordered_set<int>&s, unordered_set<int>&visited,int dst,int point,int p){
//     visited.count(node);
//     cout<<node<<" ";
//     if(node==dst){
//         cout<<"dst"<<node<<endl;
//         return;
//     }
//     for(auto ele : gp[node]){
//         if(ele.first==p)continue;
//         if(!visited.count(ele.first)){
//             dfs1(ele.first,s,visited,dst,point, node);
//            if(s.count(node)and (node==dst)){
//             point=node;
//             cout<<node<<"point";
//            }
//         }
//     }
// }
// void f1(unordered_set<int>&s,int dst){
//     int point=0;
//     unordered_set<int>visited;
//      for(int i=0; i<v; i++){
//         if(!visited.count(i)){
//             dfs1(i,s, visited ,dst,point,i);
//         }
//     }
//     // cout<<"point"<<point<<endl;
// }

int main(){
    cin>>v;
    gp.resize(v, list<pp>());
    int e;
    cin>>e;
    int min_c= INT_MAX;
    int ans=0;
    while(e--){
        int s, d,wt;
        cin>>s>>d>>wt;
        add_edge(s,d,wt,true);
    }
    vector<int>ar=f();
    unordered_set<int>s;
    for(auto ele: ar){
        s.insert(ele);
    }
    int dst;
    cin>>dst;
    for(auto ele: ar){
        ans=0;
        for(auto nei : gp[ele]){
            if(s.count(nei.first)){
                min_c= min(min_c, nei.second);
            }
            else if(nei.first==dst){
                min_c= min(min_c, nei.second);
            }
            ans+=nei.first;
        }
        min_c= min(ans, min_c);
    }
    return 0;
}