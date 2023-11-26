#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;
vector<list<int>>gp;
int v;

void add_edge(int src, int dst, bool bi_dir=true){
    gp[src].push_back(dst);
    if(bi_dir){
        gp[dst].push_back(src);
    }
}
unordered_set<int>visited;
void lexographical_printing(int strt){
    cout<<strt<<"->";
    visited.insert(strt);
    for(auto nei : gp[strt]){
        if(!visited.count(nei)){
            lexographical_printing(nei);
        }
    }
}
int main(){
    cin>>v;
    gp.resize(v, list<int>());
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d,true);
    }
    int strt;
    cin>>strt;
    lexographical_printing(strt);
    return 0;
}