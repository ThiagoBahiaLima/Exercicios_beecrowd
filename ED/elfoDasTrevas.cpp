#include <bits/stdc++.h>
using namespace std;

struct renas{
   string nome;
   int peso;
   int idade;
   float altura;
};

int main(){

   int N;
   vector<renas> seila;
   cin>>N;
   for(int caso = 1;caso <= N;caso++){
      int rena, treno;
      cin>>rena>>treno;
      for(int i = 0;i < rena;i++){
         renas atual;
         cin>>atual.nome>>atual.peso>>atual.idade>>atual.altura;
         seila.push_back(atual);
      }
      sort(seila.begin(),seila.end(),[](renas a,renas b){
         if(a.peso > b.peso) return true;
         if(a.peso < b.peso) return false;
         if(a.idade < b.idade) return true;
         if(a.idade > b.idade) return false;
         if(a.altura < b.altura) return true;
         if(a.altura > b.altura) return false;
         return a.nome < b.nome;
      });
      cout<<"CENARIO {"<<caso<<"}\n";
      for(int i = 0;i < treno;i++){
         cout<<i + 1<<" - "<<seila[i].nome<<"\n";
      }
      seila.clear();
   }

   return 0;
}