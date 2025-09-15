#include <iostream>
#include <vector>
#include <map>
using namespace std;

int cont = 1;
int ligas = 0;

void agrupar(vector<vector<int>>& garfo, int pos, vector<bool>& vis, map<int,vector<int>>& grupos){
   grupos[cont].push_back(pos);
   vis[pos] = true;
   ligas = ligas + garfo[pos].size();
   
   for(unsigned int i = 0; i < garfo[pos].size(); i++){
      if(!vis[garfo[pos][i]]){
         agrupar(garfo, garfo[pos][i], vis, grupos);
      }
   }
}

int main(){

   int vertex, edge;
   bool churrascamento = true;
   cin>>vertex>>edge;

   map<int,vector<int>> grupos;
   vector<vector<int>> garfo(vertex);
   vector<bool> vis(vertex,false);

   for(int i = 0;i < edge;i++){
      int x, y;
      cin>>x>>y;

      garfo[x - 1].push_back(y - 1);
      garfo[y - 1].push_back(x - 1);
   }

   for(int i = 0; i < vertex; i++){
      if(!vis[i]){
         agrupar(garfo, i, vis, grupos);
         grupos[cont].push_back(ligas/2);
         cont++;
         ligas = 0;
      }
   }

   for(int i = 1; i < cont && churrascamento; i++){
      if(grupos[i].size() - 1 != grupos[i][grupos[i].size() - 1]){
         churrascamento = false;
      }
   }

   if(churrascamento){
      cout<<"Yes\n";
   }
   else{
      cout<<"No\n";
   }

   return 0;
}