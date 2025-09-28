#include <iostream>
#include <vector>
#include <queue>

struct quarteto
{
   int i;
   int j;
   int k;
   int dist;

   quarteto(int i, int j, int k, int dist)
   {
      this->i = i;
      this->j = j;
      this->k = k;
      this->dist = dist;
   }
};

int main()
{

   int cam = 0, lin = 0, col = 0;

   while(std::cin >> cam >> lin >> col && cam != 0)
   {
      std::vector<std::vector<std::vector<char>>> maze(cam,std::vector<std::vector<char>>(lin,std::vector<char>(col)));

      std::queue<quarteto> fila;

      for(int i = 0; i < cam; i++)
      {
         for(int j = 0; j < lin; j++)
         {
            for(int k = 0; k < col; k++)
            {
               std::cin >> maze[i][j][k];

               if(maze[i][j][k] == 'S')
               {
                  fila.push({i, j, k, 0});
               }
            }
         }
      }

      int di[] = {1, -1, 0, 0, 0, 0};
      int dj[] = {0, 0, 1, -1, 0, 0};
      int dk[] = {0, 0, 0, 0, 1, -1};
      int dist = -1;

      while(!fila.empty() && dist == -1)
      {
         quarteto Q = fila.front();

         for(int x = 0; x < 6; x++)
         {
            int i = Q.i + di[x];
            int j = Q.j + dj[x];
            int k = Q.k + dk[x];

            if(i >= 0 && j >= 0 && k >= 0 && i < cam && j < lin && k < col)
            {
               if(maze[i][j][k] == '.')
               {
                  fila.push({i, j, k, Q.dist + 1});
                  maze[i][j][k] = '#';
               }
               else
               {
                  if(maze[i][j][k] == 'E')
                  {
                     dist = Q.dist + 1;
                  }
               }
            }
         }

         fila.pop();
      }

      if(dist == -1)
      {
         std::cout << "Trapped!\n";
      }
      else
      {
         std::cout << "Escaped in " << dist << " minute(s).\n";

      }
   }

   return 0;
}