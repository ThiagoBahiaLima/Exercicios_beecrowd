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

   std::string posi, posf;

   while(std::cin >> posi >> posf)
   {
      std::vector<std::vector<char>> tab(8,std::vector<char>(8,'.'));

      int x = posi[0] - 'a';
      int y = posi[1] - '1';

      tab[x][y] = 'A';

      std::queue<trio> fila;

      fila.push({x, y, 0});

      x = posf[0] - 'a';
      y = posf[1] - '1';

      tab[x][y] = 'B';

      int dist = 0;

      int di[] = {-1, -2, -2, -1, 1, 2, 2, 1};
      int dj[] = {-2, -1, 1, 2, 2, 1, -1, -2};

      if(tab[fila.front().i][fila.front().j] != 'B')
      {
         while(!fila.empty() && dist == 0)
         {
            trio Q = fila.front();
            fila.pop();

            for(int i = 0; i < 8; i++)
            {
               int ii = Q.i + di[i];
               int jj = Q.j + dj[i];
               
               if(ii >= 0 && ii < 8 && jj >= 0 && jj < 8)
               {
                  if(tab[ii][jj] == '.')
                  {
                     fila.push({ii, jj, Q.dist + 1});
                     tab[ii][jj] = 'A';
                  }
                  else
                  {
                     if(tab[ii][jj] == 'B')
                     {
                        dist = Q.dist + 1;
                     }
                  }
               }
            }
         }
      }

      std::cout << "To get from " << posi << " to " << posf << " takes " << dist << " knight moves.\n";
   }
   
   return 0;
}