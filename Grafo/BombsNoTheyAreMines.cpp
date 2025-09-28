#include <iostream>
#include <vector>
#include <queue>

struct trio
{
   int i;
   int j;
   int dist;

   trio(int i, int j, int dist)
   {
      this->i = i;
      this->j = j;
      this->dist = dist;
   }
};

int main()
{

   int lin = 0, col = 0;

   while(std::cin >> lin >> col && lin != 0 && col != 0)
   {
      std::vector<std::vector<char>> campo(lin,std::vector<char>(col,'.'));

      int rows = 0;

      std::cin >> rows;

      while(rows--)
      {
         int row = 0;

         int bombs = 0;

         std::cin >> row >> bombs;

         while(bombs--)
         {
            int bomb = 0;

            std::cin >> bomb;

            campo[row][bomb] = '#';
         }
      }

      int x = 0, y = 0;

      std::cin >> x >> y;

      campo[x][y] = '#';

      std::queue<trio> fila;

      fila.push({x, y, 0});

      std::cin >> x >> y;

      campo[x][y] = 'B';

      int dist = -1;

      int di[] = {1, -1, 0, 0};
      int dj[] = {0, 0, 1, -1};

      while(!fila.empty() && dist == -1)
      {
         trio Q = fila.front();

         for(int i = 0; i < 4; i++)
         {
            int ii = Q.i + di[i];
            int jj = Q.j + dj[i];

            if(ii >= 0 && ii < lin && jj >= 0 && jj < col)
            {
               if(campo[ii][jj] == '.')
               {
                  fila.push({ii, jj, Q.dist + 1});
                  campo[ii][jj] = '#';
               }
               else
               {
                  if(campo[ii][jj] == 'B')
                  {
                     dist = Q.dist + 1;
                  }
               }
            }
         }
         
         fila.pop();
      }

      std::cout << dist << "\n";

   }

   return 0;
}