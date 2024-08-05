#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/rotting-oranges/submissions/1345840723/?envType=study-plan-v2&envId=leetcode-75
#define pp pair<int,int>

vector<vector<int>>g;
vector<pp>dir{{1,0},{0,-1},{0,1},{-1,0}};


    int count_time(int i, int j, queue<pp>&qu, int count,int &fresh_oranges){
        while(!qu.empty()){
            
            pp p1= qu.front();
            qu.pop();
            
            if(p1.first==-1 and p1.second==-1){
                
                if(!qu.empty()){
                    
                    qu.push({-1,-1});
                    count++;
                }
                continue;
            }


            for( auto ele : dir){
                int new_x= ele.first+p1.first;
                int new_y = ele.second+p1.second;
                if(new_x <0 or new_y<0 or new_x>= g.size() or new_y>= g[i].size() or g[new_x][new_y]==2 or g[new_x][new_y]==0 )continue;

                if(g[new_x][new_y] == 1){
                    qu.push({new_x,new_y});
                    fresh_oranges--;
                    g[new_x][new_y]=2;
                }
            }    
        }
        
        return count;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        g= grid;
        int fresh_oranges=0;
        int ans;
        queue<pp>qu;
        for(int i=0; i<g.size(); i++){
            for(int j=0; j<g[i].size(); j++){
                if(g[i][j]==1)fresh_oranges++;
                if(g[i][j]==2){
                    qu.push({i,j});    ///   multi src bfs step
                }
            }
        }
        qu.push({-1,-1});
       
        ans = count_time(0,0,qu,0,fresh_oranges);
        return {(fresh_oranges==0) ? ans : -1} ;
    }


    int main(){

        vector<vector<int>>grid{{0,1}};
        cout<<orangesRotting(grid);

        return 0;
    }
