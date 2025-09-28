#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct trio{
   int i;
   int j;
   char dir;
   
   trio(int i, int j, char dir){
      this->i = i;
      this->j = j;
      this->dir = dir;
   }
};

struct trinca{
   int i;
   int j;
   int dist;

   trinca(int i, int j, int dist){
      this->i = i;
      this->j = j;
      this->dist = dist;
   }
};

int main(){


   int lin = 0;
   int col = 0;

   cin >> lin >> col;

   vector<vector<char>> lab(lin,vector<char>(col));
   vector<vector<trio>> caminho(lin,vector<trio>(col,{0, 0, '\0'}));
   queue<trinca> fila;

   for(int i = 0; i < lin; i++){
      for(int j = 0; j < col; j++){
         cin >> lab[i][j];
         if(lab[i][j] == 'A'){
            fila.push({i, j, 0});
            caminho[i][j] = {-1, -1, '\0'};
         }
      }
   }

   int dist = -1;
   pair<int,int> local;

   vector<vector<bool>> vis(lin,vector<bool>(col,false));
   int ci[] = {0, 0, -1, 1};
   int cj[] = {-1, 1, 0, 0};
   char dir[] = {'L', 'R', 'U', 'D'};

   while(!fila.empty() && dist == -1){
      trinca Q = fila.front();
      fila.pop();
      for(int i = 0; i < 4; i++){
         int ii = Q.i + ci[i];
         int jj = Q.j + cj[i];
         if(ii > -1 && ii < lin && jj > -1 && jj < col){
            if(lab[ii][jj] == '.'){
               fila.push({ii, jj, Q.dist + 1});
               caminho[ii][jj] = {Q.i, Q.j, dir[i]};
               lab[ii][jj] = '#';
            }
            else{
               if(lab[ii][jj] == 'B'){
                  dist = Q.dist + 1;
                  caminho[ii][jj] = {Q.i, Q.j, dir[i]};
                  local = {ii, jj};
               }
            }
         }
      }
   }

   if(dist == -1){
      cout << "NO\n";
   }
   else{
      cout << "YES\n";
      cout << dist << "\n";
      string c;
      while(local.first != -1){
         c += caminho[local.first][local.second].dir;
         local = {caminho[local.first][local.second].i, caminho[local.first][local.second].j};
      }
      reverse(c.begin(), c.end() - 1);
      cout << c.substr(0,c.size() - 1) << "\n";
   }

   return 0;
}