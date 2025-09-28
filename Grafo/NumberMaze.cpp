#include <iostream>
#include <vector>
#include <queue>

int main()
{

   int casos = 0;
   std::cin >> casos;

   while(casos--)
   {
      int lin = 0;
      int col = 0;

      std::cin >> lin >> col;

      std::vector<std::vector<int>> maze(lin,std::vector<int>(col));

      for(int i = 0; i < lin; i++)
      {
         for(int j = 0; j < col; j++)
         {
            std::cin >> maze[i][j];
         }
      }
      std::vector<std::vector<int>> dists(lin, std::vector<int>(col, -1));
      dists[0][0] = maze[0][0];

      std::priority_queue<std::pair<int,std::pair<int,int>>, std::vector<std::pair<int,std::pair<int,int>>>, std::greater<std::pair<int,std::pair<int,int>>>> filaP;
      filaP.push({maze[0][0],{0,0}});

      int di[] = {0, 0, 1, -1};
      int dj[] = {1, -1, 0, 0};

      while(!filaP.empty())
      {
         std::pair<int,std::pair<int,int>> trinca = filaP.top();
         filaP.pop();

         if(dists[trinca.second.first][trinca.second.second] >= trinca.first)
         {
            for(int x = 0; x < 4; x++)
            {
               int i = trinca.second.first + di[x];
               int j = trinca.second.second + dj[x];

               if(i >= 0 && i < lin && j >= 0 && j < col)
               { 
                  if(dists[trinca.second.first][trinca.second.second] + maze[i][j] < dists[i][j] || dists[i][j] == -1)
                  {
                     dists[i][j] = dists[trinca.second.first][trinca.second.second] + maze[i][j];
                     filaP.push({dists[i][j], {i, j}});
                  }
               }
            }
         }
      }

      std::cout << dists[lin - 1][col - 1] << "\n";
   }

   return 0;
}