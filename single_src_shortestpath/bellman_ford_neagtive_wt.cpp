#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#define INF INT_MAX
using namespace std;

class edge{
    public:
    int src;
    int dst;
    int wt;
    edge(){

    }
};
void s(vector<edge>&input, int e){
    vector<int>p(e,-1);
    vector<int>path1;
    vector<int>d(e,INF);
    d[0]=0;
    int x=-1;
    for(int i=0; i<e; i++){
         x=-1;
        for(edge ele : input){
            if(d[ele.src]<INF){
                if(d[ele.dst]>d[ele.src] + ele.wt){
                    d[ele.dst]= d[ele.src]+ ele.wt;
                    p[ele.dst]= ele.src;
                    cout<<ele.src<<"->";
                }
                x=ele.dst;

            }
            
        }
        cout<<endl;
        
    }

    if(x!=-1){
        vector<int>path;
        int y=x;
        for(int curr = y; ; curr= p[curr]){
            if(curr==y and path.size()>1){//for second meeting with y as in 1st path size will be 1
                break;
            }   
            path.push_back(curr);
        }
        reverse(path.begin(), path.end());
        for(auto ele : path){
            cout<<" cyclic path is "<<ele<<"->";
        }

        }
}


int main(){
    int v,e;
    cin>>v>>e;
    vector<edge>input(e);
    for(int i=0; i<e; i++){
        cin>>input[i].src>>input[i].dst>>input[i].wt;
    }
    s(input,e);
    return 0;
}