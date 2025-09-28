#include <iostream>
#include <vector>
#include <queue>

int main()
{

   int casos = 0;
   std::cin >> casos;

   bool primeiro = true;

   while(casos--)
   {
      if(!primeiro)
      {
         std::cout << "\n";
      }
      primeiro = false;

      int celas = 0;
      int saida = 0;
      int tempoL = 0;
      int conexoes = 0;

      std::cin >> celas >> saida >> tempoL >> conexoes;
      saida--;

      std::vector<std::vector<std::pair<int,int>>> garfo(celas);

      for(int i = 0; i < conexoes; i++)
      {
         int x = 0;
         std::pair<int,int> PV;

         std:: cin >> x >> PV.second >> PV.first;
         x--, PV.second--;

         garfo[x].push_back(PV);
      }

      int ratosLivres = 0;

      for(unsigned int z = 0; z < garfo.size(); z++){

         std::vector<int> dists(celas, 1e9);
         
         std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> filaP;

         filaP.push({0, z});
         dists[z] = 0;

         while(!filaP.empty())
         {
            std::pair<int,int> DV = filaP.top();
            filaP.pop();

            if(DV.first <= dists[DV.second])
            {
               for(unsigned int i = 0; i < garfo[DV.second].size(); i++)
               {
                  if(DV.first + garfo[DV.second][i].first < dists[garfo[DV.second][i].second])
                  {
                     dists[garfo[DV.second][i].second] = DV.first + garfo[DV.second][i].first;
                     filaP.push({dists[garfo[DV.second][i].second], garfo[DV.second][i].second});
                  }
               }
            }
         }

         if(dists[saida] <= tempoL)
         {
            ratosLivres++;
         }

      }

      std::cout << ratosLivres << "\n";
      
   }

   return 0;
}