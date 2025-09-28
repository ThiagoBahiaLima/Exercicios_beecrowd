#include <iostream>
#include <vector>
#include <queue>

int main()
{

   int N = 0;

   int skills = 0;

   std::cin >> N;
   std::vector<bool> learned(N,false);
   std::vector<std::vector<int>> garfo(N);

   std::queue<int> fila;

   for(int i = 0; i < N; i++)
   {
      int x = 0, y = 0;

      std::cin >> x >> y;

      if(x == 0 && y == 0)
      {
         learned[i] = true;
         skills++;
         fila.push(i);
      }
      else
      {
         x--, y--;
         garfo[x].push_back(i);
         garfo[y].push_back(i);

      }
   }

   while(!fila.empty())
   {
      int x = fila.front();
      for(unsigned int i = 0; i < garfo[x].size(); i++)
      {
         if(!learned[garfo[x][i]])
         {
            learned[garfo[x][i]] = true;
            fila.push(garfo[x][i]);
            skills++;
         }
      }
      fila.pop();
   }

   std::cout << skills << '\n';

   return 0;
}