#include <iostream>
#include <vector>
#include <queue>

struct trio
{
   int i;
   int j;
   int moves;

   trio(int i, int j, int moves)
   {
      this->i = i;
      this->j = j;
      this->moves = moves;
   }
};

int main()
{
   int caso = 0;

   int i = 0, j = 0;

   while(std::cin >> i >> j)
   {
      caso++;

      std::queue<trio> fila;

      std::vector<std::vector<char>> lab(8,std::vector<char>(8,'.'));
      
      i--,j--;
      i = 7 - i;
      lab[i][j] = 'A';

      fila.push({i, j, 0});

      std::cin >> i >> j;

      i--, j--;
      i = 7 - i;
      lab[i][j] = 'B';
      
      std::cin >> i >> j;

      i--, j--;
      i = 7 - i;
      lab[i][j] = '#';
      
      int dist = -1;

      int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
      int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};

      while(!fila.empty() && dist == -1)
      {
         trio Q = fila.front();
         fila.pop();

         for(int k = 0; k < 8; k++)
         {
            int ii = Q.i + di[k];
            int jj = Q.j + dj[k];

            if(ii >= 0 && ii < 8 && jj >= 0 && jj < 8)
            {
               if(lab[ii][jj] == '.')
               {
                  fila.push({ii, jj, Q.moves + 1});
                  lab[ii][jj] = '#';
               }
               else{
                  if(lab[ii][jj] == 'B')
                  {
                     dist = Q.moves + 1;
                  }
               }
            }
         }
      }

      std::cout << "Case " << caso << ": " << dist << "\n";
   }
}