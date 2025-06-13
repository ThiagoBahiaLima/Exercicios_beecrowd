#include <bits/stdc++.h>
using namespace std;

int main(){

   int N,ganhadores = 0;
   cin>>N;
   queue<char> novo,novonovo;
   stack<char> tudo,memoria;
   while(N--){
      if(tudo.empty()){
         tudo.push('F');
         tudo.push('A');
         tudo.push('C');
         tudo.push('E');
      }
      char x;
      for(int i = 0;i < 4;i++){
         cin>>x;
         novo.push(x);
         novonovo.push(x);
      }
      int val = 0;
      for(int i = 0;i < 4;i++){
         if(novo.front() == tudo.top()){
            val++;
         }
         memoria.push(tudo.top());
         novo.pop();
         tudo.pop();
      }
      if(val == 4){
         ganhadores++;
      }
      else{
         for(int i = 0;i < 4;i++){
            tudo.push(memoria.top());
            memoria.pop();
         }
         for(int i = 0;i < 4;i++){
            tudo.push(novonovo.front());
            novonovo.pop();
         }
      }
      if(!novonovo.empty()){
         for(int i = 0;i < 4;i++){
            novonovo.pop();
         }
      }
   }
   cout<<ganhadores<<"\n";

   return 0;
}