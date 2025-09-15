#include <iostream>
#include <vector>
#include <map>
using namespace std;

int cont = 1;

void agrupar(vector<vector<int>>& garfo, int pos, vector<bool>& vis, map<int,vector<int>>& grupos){
   grupos[cont].push_back(pos);
   vis[pos] = true;
   for(unsigned int i = 0; i < garfo[pos].size(); i++){
      if(!vis[garfo[pos][i]]){
         agrupar(garfo, garfo[pos][i], vis, grupos);
      }
   }
}

int main(){

   int vertex, edge;
   cin>>vertex>>edge;

   int loops = 0;

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
         cont++;
      }
   }

   int seila = 0;

   for(int i = 1; i < cont; i++){
      for(unsigned int j = 0; j < grupos[i].size(); j++){
         if(garfo[grupos[i][j]].size() != 2){
            seila++;
            break;
         }
      }
      if(seila == 0){
         loops++;
      }
      seila = 0;
   }

   printf("%d\n", loops);

   return 0;
}