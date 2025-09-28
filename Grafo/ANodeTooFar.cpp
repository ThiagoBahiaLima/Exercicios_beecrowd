#include <iostream>
#include <vector>
#include <queue>
#include <map>

struct duo{
   int pos;
   int dist;

   duo(int pos, int dist){
      this->pos = pos;
      this->dist = dist;
   }
};

int main(){

   int conexoes = 0;
   int caso = 0;
   
   while(std::cin >> conexoes && conexoes != 0)
   {

      std::map<int,bool>::iterator it;
      std::map<int,std::vector<int>> garfo;
      std::map<int,bool> vis;

      int x = -1, y = -1;

      for(int i = 0; i < conexoes; i++)
      {
         std::cin >> x >> y;
         garfo[x].push_back(y);
         garfo[y].push_back(x);
         vis[x] = false;
         vis[y] = false;
      }

      x = -1, y = -1;

      while(std::cin >> x >> y && (y != 0 || x != 0))
      {
         caso++;
         int nos = 0;
         std::queue<duo> fila;
         fila.push({x, y});
         vis[x] = true;

         while(!fila.empty())
         {
            duo temp = fila.front();
            
            fila.pop();

            if(temp.dist >= 0)
            {
               nos++;
            }

            for(unsigned int i = 0; i < garfo[temp.pos].size(); i++)
            {
               if(!vis[garfo[temp.pos][i]])
               {
                  fila.push({garfo[temp.pos][i], temp.dist - 1});
                  vis[garfo[temp.pos][i]] = true;
               }
            }
         }

         nos = garfo.size() - nos;

         std::cout << "Case " << caso << ": " << nos << " nodes not reachable from node " << x << " with TTL = " << y << ".\n";

         for(it = vis.begin(); it != vis.end(); it++)
         {
            it->second = false;
         }

         
      }

      garfo.clear();
   }

   return 0;
}