#include <bits/stdc++.h>
using namespace std;

int main(){

   int H, P, F;
   while(cin>>H>>P>>F && H != 0 && P != 0 && F != 0){
      vector<vector<int>> pilhas(H,vector<int>(P,0));
      for(int i = 0;i < H;i++){
         for(int j = 0;j < P;j++){
            cin>>pilhas[i][j];
         }
      }
      while(F--){
         int x;
         cin>>x;
         int i = 0,j = P - 1;
         while(j >= 0 && pilhas[i][j] != 0){
            j--;
         }
         if(j >= 0){
            while(i < H - 1 && pilhas[i+1][j] == 0){
               i++;
            }
            pilhas[i][j] = x;
         }
      }
      for(int i = 0;i < H;i++){
         bool primeiro = true;
         for(int j = 0;j < P;j++){
            if(primeiro){
               cout<<pilhas[i][j];
               primeiro = false;
            }
            else{
               cout<<" "<<pilhas[i][j];
            }
         }
         cout<<"\n";
      }
      pilhas.clear();
   }

   return 0;
}