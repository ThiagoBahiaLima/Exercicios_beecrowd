#include <iostream>
#include <vector>
#include <queue>

void dfs(std::vector<std::vector<int>>& garfo, int pos, std::vector<bool>& vis){
   vis[pos] = true;
   for(unsigned int i = 0; i < garfo[pos].size(); i++){
      if(!vis[garfo[pos][i]]){
         dfs(garfo, garfo[pos][i], vis);
      }
   }
}

int main(){

   int pessoas = 0, amizades = 0;
   std::cin >> pessoas >> amizades;

   std::vector<std::vector<int>> garfo(pessoas);

   for(int i = 0; i < amizades; i++){
      int A1 = 0, A2 = 0;
      std::cin >> A1 >> A2;
      A1--, A2--;
      garfo[A1].push_back(A2);
      garfo[A2].push_back(A1);
   }

   std::queue<int> fila;
   std::vector<int> time(pessoas, 0);
   std::vector<bool> vis(pessoas,false);

   for(int i = 0; i < pessoas; i++){
      if(!vis[i]){
         dfs(garfo, i, vis);
         fila.push(i);
         time[i] = 1;
      }
   }
   
   std::vector<bool> vis2(pessoas,false);
   bool possivel = true;

   while(!fila.empty() && possivel){
      int atual = fila.front();
      fila.pop();
      vis2[atual] = true;
      for(unsigned int i = 0; i < garfo[atual].size(); i++){
         if(!vis2[garfo[atual][i]]){
            fila.push(garfo[atual][i]);
            if(time[atual] == 1){
               if(time[garfo[atual][i]] == 1){
                  possivel = false;
               }
               else{
                  time[garfo[atual][i]] = 2;
               }
            }
            else{
               if(time[garfo[atual][i]] == 2){
                  possivel = false;
               }
               else{
                  time[garfo[atual][i]] = 1;
               }
            }
         }
      }
   }

   if(possivel){
      std::cout << time[0];
      for(unsigned int i = 1; i < time.size(); i++){
         std::cout << " " << time[i];
      }
      std::cout << "\n";
   }
   else{
      std::cout << "IMPOSSIBLE\n";
   }


   return 0;
}