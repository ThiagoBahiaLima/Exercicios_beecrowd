#include <iostream>
#include <queue>
#include <vector>

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

      std::vector<std::vector<char>> floresta(lin,std::vector<char>(col));

      std::queue<trinca> fila;

      for(int i = 0; i < lin; i++)
      {
         for(int j = 0; j < col; j++)
         {
            std::cin >> floresta[i][j];

            if(floresta[i][j] == 'A')
            {
               fila.push({i, j, 0});
            }
         }
      }

      {
         int di[] = {-1, -2, -2, -1, 1, 2, 2, 1};
         int dj[] = {-2, -1, 1, 2, 2, 1, -1, -2};

         for(int i = 0; i < lin; i++)
         {
            for(int j = 0; j < col; j++)
            {
               if(floresta[i][j] == 'Z')
               {
                  for(int k = 0; k < 8; k++)
                  {
                     int ii = i + di[k];
                     int jj = j + dj[k];

                     if(ii >= 0 && ii < lin && jj >= 0 && jj < col)
                     {
                        if(floresta[ii][jj] == '.')
                        {
                           floresta[ii][jj] = '#';
                        }
                     }
                  }
               }
            }
         }
      }

      int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
      int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};

      int dist = 0;
      bool chegou = false;

      while(!fila.empty() && !chegou)
      {
         trinca T = fila.front();

         for(int k = 0; k < 8; k++)
         {
            int i = T.i + di[k];
            int j = T.j + dj[k];

            if(i >= 0 && i < lin && j >= 0 && j < col)
            {
               if(floresta[i][j] == '.')
               {
                  floresta[i][j] = 'A';
                  fila.push({i, j, T.dist + 1});
               }
               else
               {
                  if(floresta[i][j] == 'B')
                  {
                     dist = T.dist + 1;
                     chegou = true;
                  }
               }
            }
         }

         fila.pop();
      }

      if(chegou)
      {
         std::cout << "Minimal possible length of a trip is " << dist << '\n';
      }
      else
      {
         std::cout << "King Peter, you can't go now!\n";
      }
   }

   return 0;
}