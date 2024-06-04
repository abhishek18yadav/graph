#include<bits/stdc++.h>
using namespace std;

/**
 * There are n cities and m one-directional roads connecting the city A[i] to city B[i]. We are in the panner-making business. Each city has set its own price of paneer. You can buy or sell paneer in the city i for vali rupees. You have to buy paneer from some city u and sell the paneer in another city v. The profit that you make is calculated as the selling price minus buying price. Return an integer denoting the maximum profit you can make. NOTE: In all, it is mandatory to buy only 1 paneer and it is mandatory to sell that paneer in some other city that can be travelled from it.

Input Format

The first line contains n the number of cities.
The next n lines contain the elements of the array val.
The next line contains an integer m.
The next m lines contain the array of elements A.
The next line again contains the integer m.
The next m lines contain the array of elements B.
Constraints

2 <= n <= 105
1 <= m <= 105
1 <= Ai < Bi <= n
Output Format

Return an integer denoting the maximum profit possible.
Evaluation Parameters

Sample Input
4
2
3
1
5
3
1
1
2
3
2
3
4
Sample Output
3
*/
vector<list<int>>graph;
int v;

void addedge(int s, int dst , bool bi_dir){
    graph[s].push_back(dst);
    if(bi_dir){
        graph[dst].push_back(s);
    }
}
void Maxi(vector<int>&pa){
    unordered_set<int>st;
    vector<int>pr;
    for(int i=1; i<=v; i++){
        int cp = pa[i-1];
        queue<int>qu;
        qu.push(i);
        st.insert(i);
        while(!qu.empty()){
            int s= qu.front();
            qu.pop();
            for(auto ele : graph[s]){
                if(!st.count(ele)){
                 qu.push(ele);
                pr.push_back(pa[ele-1] - cp); 
                }
                else break;
            }
            
        }
        
    }
    cout<<pr.size();
};
int main(){
    cin>>v;
    graph.resize(v,list<int>());
    int e;
    cin>>e;
    for(int i=1; i<=e; i++){
        int s,d;
        cin>>s>>d;
        addedge(s,d,false);
    }
    vector<int>pa{2,3,1,5};
    Maxi(pa);
    return 0;
}