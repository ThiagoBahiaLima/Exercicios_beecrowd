#include <bits/stdc++.h>
using namespace std;

int main(){

   int N;
   while(cin>>N){
      vector<vector<char>> sorobov(8,vector<char>(9,'1'));
      for(int i = 1;i <= 3;i += 2){
         for(int j = 0;j < 9;j++){
            sorobov[i][j] = '0';
         }
      }
      for(int i = 0;i < 9;i++){
         sorobov[2][i] = '-';
      }
      int digito,a = 3, b = 8;
      while(N != 0){
         digito = N%10;
         if(digito >= 5){
            sorobov[0][b] = '0';
            sorobov[1][b] = '1';
            digito = digito - 5;
         }
         for(int i = 0;i < digito;i++){
            char M = sorobov[a][b];
            sorobov[a][b] = sorobov[a+1][b];
            sorobov[a+1][b] = M;
            a++;
         }
         b--;
         a = 3;
         N = N/10;
      }
      b = 8;
      for(int i = 0;i < 8;i++){
         for(int j = 0;j < 9;j++){
            cout<<sorobov[i][j];
         }
         cout<<"\n";
      }
      cout<<"\n";
   }

   return 0;
}