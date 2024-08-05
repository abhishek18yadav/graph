#include<bits/stdc++.h>
using namespace std;


    #define pp pair<int,int>

    vector<vector<int>>dir{{-1,0}, {0,-1}, {1,0}, {0,1}};
    
    vector<vector<char>>g;


    int bfs(int i, int j){
        queue<pp>qu;
        qu.push({i,j});
        g[i][j]='0';
        while(!qu.empty()){
            pp node = qu.front();
            qu.pop();
            
            for(auto ele : dir){
                int x=ele[0]+ node.first;
                int y = ele[1] + node.second;
                if(x<0 or y<0 or x>=g.size() or y>= g[i].size()  or g[x][y]== '0')continue;
                if(g[x][y]=='1'){
                    g[x][y]='0';
                    qu.push({x,y});
                }
            }
        }
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        g = grid;
        int count=0;
        for(int i=0; i<g.size(); i++){
            for(int j=0; j<g[i].size(); j++){
                if(g[i][j]=='1'){
                    count+=bfs(i,j);
                }
                else continue;
            }
        }
        return count;
    }


    int main(){
        vector<vector<char>>grid{{'1','1','1','1','0'},
                                 {'1','1','0','1','1'},
                                 {'1','1','0','0','0'},
                                 {'0','0','1','1','0'}};


        cout<<numIslands(grid);
        return 0;
    }