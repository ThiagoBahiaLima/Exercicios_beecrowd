#include <iostream>
#include <vector>
using namespace std;

int ponta;
int dis = 0;
int disAt = 0;

void dfs(vector<vector<int>>& grafo,int pos,vector<bool>& vis){
   vis[pos] = true;
   disAt++;
   if(dis < disAt){
      dis = disAt;
      ponta = pos;
   }
   for(unsigned int i = 0;i < grafo[pos].size();i++){
      if(!vis[grafo[pos][i]]){
         dfs(grafo, grafo[pos][i], vis);
         disAt--;
      }
   }

}

int main(){

   int nodes;
   cin>>nodes;
   
   vector<vector<int>> grafo(nodes);
   for(int i = 0;i < nodes - 1;i++){
      int a, b;
      cin>>a>>b;
      grafo[a - 1].push_back(b - 1);
      grafo[b - 1].push_back(a - 1);
   }

   vector<bool> vis(nodes,false);
   dfs(grafo, 0, vis);
   vector<bool> vis2(nodes,false);
   dfs(grafo, ponta, vis2);

   cout<<dis - 2<<"\n";




   return 0;
}