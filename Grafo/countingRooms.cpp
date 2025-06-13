#include <iostream>
#include <vector>
using namespace std;

void preencherPontos(vector<vector<char>> &mapa,int lin,int col){
   mapa[lin][col] = 'C';
   if(lin + 1 < mapa.size() && mapa[lin+1][col] == '.'){
      preencherPontos(mapa,lin + 1,col);
   } 
   if(lin - 1 >= 0 && mapa[lin-1][col] == '.'){
      preencherPontos(mapa,lin - 1,col);
   }
   if(col + 1 < mapa[lin].size() && mapa[lin][col+1] == '.'){
      preencherPontos(mapa,lin,col + 1);
   } 
   if(col - 1 >= 0 && mapa[lin][col-1] == '.'){
      preencherPontos(mapa,lin,col - 1);
   }
}

int main(){

   int n, m;
   cin>>n>>m;
   vector<vector<char>> mapa(n,vector<char>(m,'.'));
   for(int i = 0;i < n;i++){
      for(int j = 0;j < m;j++){
         cin>>mapa[i][j];
      }
   }
   int quartos = 0;
   for(int i = 0;i < n;i++){
      for(int j = 0;j < m;j++){
         if(mapa[i][j] == '.'){
            preencherPontos(mapa,i,j);
            quartos = quartos + 1;
         }
      }
   }
   cout<<quartos<<"\n";   

   return 0;
}