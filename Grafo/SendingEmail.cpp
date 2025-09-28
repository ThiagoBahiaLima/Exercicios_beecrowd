#include <iostream>
#include <vector>
#include <queue>

int main()
{

   int casos = 0;

   std::cin >> casos;

   for(int caso = 1; caso <= casos; caso++)
   {
      int servers = 0;
      int conexoes = 0;
      int part = 0;
      int dest = 0;

      std::cin >> servers >> conexoes >> part >> dest;

      std::vector<std::vector<std::pair<int,int>>> garfo(servers);

      for(int i = 0; i < conexoes; i++)
      {
         int x;
         std::pair<int,int> VP;

         std::cin >> x >> VP.first >> VP.second;

         garfo[x].push_back(VP);
         garfo[VP.first].push_back({x, VP.second});
      }

      std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> filaP;
      std::vector<int> dists(servers, 1e9);
      filaP.push({0, part});

      while(!filaP.empty())
      {
         std::pair<int,int> DV = filaP.top();
         filaP.pop();

         if(DV.first <= dists[DV.second])
         {
            for(unsigned int i = 0; i < garfo[DV.second].size(); i++)
            {
               if(DV.first + garfo[DV.second][i].second < dists[garfo[DV.second][i].first])
               {
                  dists[garfo[DV.second][i].first] = DV.first + garfo[DV.second][i].second;
                  filaP.push({dists[garfo[DV.second][i].first], garfo[DV.second][i].first});
               }
            }
         }
      }

      if(dists[dest] == 1e9)
      {
         std::cout << "Case #" << caso << ": unreachable\n";
      }
      else
      {
         std::cout << "Case #" << caso << ": " << dists[dest] << '\n';
      }
   }

   return 0;
}