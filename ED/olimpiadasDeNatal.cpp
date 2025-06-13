#include <bits/stdc++.h>
using namespace std;

struct relacao{
   string nome;
   int ouro;
   int prata;
   int bronze;
};

int main(){
   
   vector<relacao> paises;
   string x;
   while(getline(cin,x)){
      for(int i = 0;i < 3;i++){
         bool val = true;
         getline(cin,x);
         for(int j = 0;j < paises.size() && val;j++){
            if(paises[j].nome == x && i == 0){
               paises[j].ouro++;
               val = false;
            }
            else{
               if(paises[j].nome == x && i == 1){
                  paises[j].prata++;
                  val = false;
               }
               else{
                  if(paises[j].nome == x && i == 2){
                     paises[j].bronze++;
                     val = false;
                  }
               }
            }
         }
         if(val && i == 0){
            paises.push_back({x,1,0,0});
         }
         else{
            if(i == 1 && val){
               paises.push_back({x,0,1,0});
            }
            else{
               if(val && i == 2){
                  paises.push_back({x,0,0,1});
               }
            }
         }
      }
   }
   sort(paises.begin(),paises.end(),[](relacao a,relacao b){
      if(a.ouro > b.ouro) return true;
      if(a.ouro < b.ouro) return false;
      if(a.prata > b.prata) return true;
      if(a.prata < b.prata) return false;
      if(a.bronze > b.bronze) return true;
      if(a.bronze < b.bronze) return false;
      return a.nome < b.nome;
   });
   cout<<"Quadro de Medalhas\n";
   for(int i = 0;i < paises.size();i++){
      cout<<paises[i].nome<<" "<<paises[i].ouro<<" "<<paises[i].prata<<" "<<paises[i].bronze<<"\n";
   }

   return 0;
}