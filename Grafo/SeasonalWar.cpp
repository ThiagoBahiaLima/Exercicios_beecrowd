#include <iostream>
#include <vector>
using namespace std;

void filudFil(vector<vector<int>>& matriz, int grandeza, int i, int j){
   
   matriz[i][j] = 0;

   for(int x = i - 1; x < i + 2; x++)
   {
      if(x >= 0 && x < grandeza)
      {
         for(int y = j - 1; y < j + 2; y++)
         {
            if(y >= 0 && y < grandeza)
            {
               if(matriz[x][y] == 1)
               {
                  filudFil(matriz, grandeza, x, y);
               }
            }
         }
      }
   }

}

int main(){

   int grandeza = 0;
   int imagem = 0;

   while(cin>>grandeza){

      imagem++;
      
      vector<vector<int>> matriz(grandeza,vector<int>(grandeza,0));
      
      for(int i = 0; i < grandeza; i++){
         for(int j = 0; j < grandeza; j++){

            char x;

            cin>>x;
            
            matriz[i][j] = x - '0';
         }
      }

      int warEagles = 0;

      for(int i = 0; i < grandeza; i++){
         for(int j = 0; j < grandeza; j++){
            if(matriz[i][j] == 1){
               filudFil(matriz, grandeza, i, j);
               warEagles++;
            }
         }
      }

      cout<<"Image number "<<imagem<<" contains "<<warEagles<<" war eagles.\n";

   }

   return 0;
}