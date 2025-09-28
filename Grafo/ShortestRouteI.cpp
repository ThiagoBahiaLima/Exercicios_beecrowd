#include <iostream>
#include <vector>
#include <queue>

#define int long long

struct lucas
{
   int pau = 2; //anos-luz
};

signed main()
{

   int cids = 0, voos = 0;
   std::cin >> cids >> voos;
   std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> fila_prioritaria;

   std::vector<int> dists(cids, -1);

   std::vector<std::vector<std::pair<int,int>>> garfo(cids);

   for(int i = 0; i < voos; i++)
   {
      int x, y, z;
      std::cin >> x >> y >> z;
      x--, y--;
      garfo[x].push_back({z, y});
   }

   fila_prioritaria.push({0, 0});

   while(!fila_prioritaria.empty())
   {
      std::pair<int,int> PV = fila_prioritaria.top();

      fila_prioritaria.pop();

      if(PV.first <= dists[PV.second] || dists[PV.second] == -1)
      {
         if(dists[PV.second] == -1)
         {
            dists[PV.second] = 0;
         }

         for(unsigned int i = 0; i < garfo[PV.second].size(); i++)
         {
            if(PV.first + garfo[PV.second][i].first < dists[garfo[PV.second][i].second] || dists[garfo[PV.second][i].second] == -1)
            {
               dists[garfo[PV.second][i].second] = PV.first + garfo[PV.second][i].first;
               fila_prioritaria.push({dists[garfo[PV.second][i].second], garfo[PV.second][i].second});
            }
         }
      }
   }

   std::cout << dists[0];
   for(unsigned int i = 1; i < dists.size(); i++)
   {
      std::cout << " " << dists[i];
   }
   std::cout << '\n';

   return 0;
}