#include <iostream>
#include <vector>

int restaurantes = 0;
int limiteGatos;

void dfs(std::vector<std::vector<int>>& garfo, int pos, std::vector<int>& blocks, std::vector<bool>& vis, int gatos){
   vis[pos] = true;
   if(blocks[pos] == 1){
      gatos++;
   }
   else{
      if(gatos <= limiteGatos){
         gatos = 0;
      }
   }

   for(unsigned int i = 0; i < garfo[pos].size(); i++){
      if(!vis[garfo[pos][i]]){
         dfs(garfo, garfo[pos][i], blocks, vis, gatos);
      }
   }

   if(garfo[pos].size() == 1 && pos != 0){
      if(gatos <= limiteGatos){
         restaurantes++;
      }
   }
}

int main(){

   int vertices;
   std::cin>>vertices>>limiteGatos;

   std::vector<int> blocks(vertices);
   std::vector<std::vector<int>> garfo(vertices);
   std::vector<bool> vis(vertices,false);

   for(int i = 0;i < vertices;i++){
      std::cin>>blocks[i];
   }

   for(int i = 0;i < vertices - 1;i++){
      int x, y;
      std::cin>>x>>y;
      x--;
      y--;
      garfo[x].push_back(y);
      garfo[y].push_back(x);
   }

   dfs(garfo, 0, blocks, vis, 0);

   std::cout<<restaurantes<<"\n";

   return 0;
}