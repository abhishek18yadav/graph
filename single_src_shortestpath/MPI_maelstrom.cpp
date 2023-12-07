#include<iostream>
#include<unordered_map>
#include<queue>
#include<unordered_set>
#include<vector>
#include<list>
#include<algorithm>
#include<climits>
using namespace std;

#define pp pair<int,int>

int v;
bool cmp(int x,int y){
    return x>y;
}

vector<list<pp>>gp;

void add_edge(int src, int dst, int wt, bool bi_dir= true){
    gp[src].push_back({dst, wt});
    if(bi_dir){
        gp[dst].push_back({src,wt});
    }
}

void f(int src, vector<int>&ans){
    int total=2,count=0;
    priority_queue<pp>q;
    q.push({0,src});
    unordered_set<int>visited;
    unordered_map<int,int>mp;
    for(int i=2; i<=v; i++){
        mp[i]=INT_MAX;
    }
    mp[src]=0;
    while(!q.empty() and total<=v){
        pp node = q.top();
        if(visited.count(node.second)){
            q.pop();
            continue;
        }
        count+=node.first;
        total++;
        visited.count(node.second);
        for(auto ele : gp[node.second]){
            if(!visited.count(ele.first) and mp[ele.first]>mp[node.second]+ele.second){
                 mp[ele.first] = mp[node.second]+ele.second;
                 q.push({ele.second, ele.first});
            }
        }
        q.pop();
    }
    ans.push_back(count);
}

int main(){
    cin>>v;
    gp.resize(v+1, list<pp>());
        int z=1;
        for(int i=2 ; i<= v; i++){
            for(int j=1; j<=z; j++){
                int wt;
                cout<<"enter wt";
                cin>>wt;
                if(wt!=-1){
                add_edge(i,j,wt,true);
                }
            }
            z++;
        }
        vector<int>ans;
        for(int i=2; i<=v; i++){
        f(i,ans);
        }
        
        sort(ans.begin(), ans.end(),cmp);
        cout<<"minimun time is"<<ans[0];
    return 0;
}