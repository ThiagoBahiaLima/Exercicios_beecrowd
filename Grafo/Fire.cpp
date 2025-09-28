#include <iostream>
#include <vector>
#include <queue>

struct trinca
{
   int i;
   int j;
   int dist;

   trinca(int i, int j, int dist)
   {
      this->i = i;
      this->j = j;
      this->dist = dist;
   }
};

int main()
{

   int casos = 0;

   std::cin >> casos;

   while(casos--)
   {
      int lin = 0, col = 0;

      std::cin >> lin >> col;

      std::vector<std::vector<char>> maze(lin,std::vector<char>(col));

      std::queue<trinca> fogo;
      std::queue<trinca> passos;

      for(int i = 0; i < lin; i++)
      {
         for(int j = 0; j < col; j++)
         {
            std::cin >> maze[i][j];
            
            if(maze[i][j] == 'F')
            {
               fogo.push({i, j, 0});
            }
            else
            {
               if(maze[i][j] == 'J')
               {
                  passos.push({i, j, 0});
               }
            }
         }
      }

      int dist = -1;
      int di[] = {1, -1, 0, 0};
      int dj[] = {0, 0, 1, -1};

      while(!passos.empty() && dist == -1)
      {
         int passoAt = passos.size();

         while(passoAt--)
         {

            trinca T = passos.front();

            if(maze[T.i][T.j] != 'F')
            {
               for(int k = 0; k < 4; k++)
               {
                  int i = T.i + di[k];
                  int j = T.j + dj[k];

                  if(i >= 0 && i < lin && j >= 0 && j < col)
                  {
                     if(maze[i][j] == '.')
                     {
                        passos.push({i, j, T.dist + 1});
                        maze[i][j] = 'J';
                     }
                  }
                  else
                  {
                     dist = T.dist + 1;
                  }
               }
            }

            passos.pop();
         }
         
         int fogoAt = fogo.size();

         while(fogoAt--)
         {
            trinca F = fogo.front();

            for(int k = 0; k < 4; k++)
            {
               int i = F.i + di[k];
               int j = F.j + dj[k];

               if(i >= 0 && i < lin && j >= 0 && j < col)
               {
                  if(maze[i][j] == '.' || maze[i][j] == 'J')
                  {
                     fogo.push({i, j, 0});
                     maze[i][j] = 'F';
                  }
               }
            }

            fogo.pop();
         }
      }

      if(dist == -1)
      {
         std::cout << "IMPOSSIBLE\n";
      }
      else
      {
         std::cout << dist << '\n';
      }
   }

   return 0;
}