#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
#define pp pair<int,int>
class edge{
    public:
    int src;
    int dst;
    int wt;
    edge(){

    }
};
bool cmp( edge a, edge b){
    return a.wt<b.wt;
}
int find(int node, vector<int>&parent){
    return (node==parent[node])?node:find(parent[node], parent);
}
 void union_p(int p_a, int p_b,vector<int>&parent, vector<int>&rank ){
    p_a= find(p_a, parent);
    p_b= find(p_b, parent);
    if(p_a==p_b)return;  // cycle
    if(rank[p_a]> rank[p_b]){
        parent[p_b]=p_a;
        rank[p_a]++;
    }else{
        parent[p_a]=p_b;
        rank[p_b]++;
    }
 }
void kr(vector<edge>&in, int v){
    sort(in.begin(), in.end(), cmp);
    vector<int>parent(v,-1);
    vector<int>rank(v,-1);
    for(int i=0; i<v; i++){
        parent[i]=i;
    }
    int ecount=0;
    int ans=0,i=0;
    while(ecount<v-1 and i<in.size()){
        edge node = in[ecount];
        int p_a= find(node.src, parent);
        int p_b = find(node.dst, parent);
        if(p_a != p_b){
            union_p(p_a,p_b,parent, rank);
            ans+=node.wt;
            ecount++;
        }
        i++;
    }
    cout<< ans<<endl;
}
int main(){
    int v;
    cin>>v;
    int e;
    cin>>e;
    vector<edge>in(e);
    for(int i=0; i<e; i++){
        cin>>in[i].src>>in[i].dst>>in[i].wt;
    }
    kr(in,v);
    return 0;
}