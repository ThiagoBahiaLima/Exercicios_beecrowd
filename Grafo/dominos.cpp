#include <iostream>
#include <vector>
using namespace std;

vector<bool> vis;

void dfs(vector<vector<int>> &dominos,int pos,int* cont){
   *cont = *cont + 1;
   vis[pos] = true;
   for(int i = 0; i < dominos[pos].size();i++){
      if(!vis[dominos[pos][i]]){
         dfs(dominos,dominos[pos][i],cont);
      }
   }
}

int main(){

   int casos;
   cin>>casos;
   while(casos--){
      int n, m, l;
      cin>>n>>m>>l;
      for(int i = 0; i < n;i++){
         vis.push_back(false);
      }
      vector<vector<int>> dominos(n);
      for(int i = 0; i < m;i++){
         int x, y;
         cin>>x>>y;
         dominos[x-1].push_back(y-1);
      }
      int cont = 0;
      for(int i = 0;i < l;i++){
         int x;
         cin>>x;
         if(!vis[x-1]){
            dfs(dominos,x-1,&cont);
         }
      }
      cout<<cont<<"\n";
      vis.clear();
   }

   return 0;
}