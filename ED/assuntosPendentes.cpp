#include <bits/stdc++.h>
using namespace std;

int main(){

   string x;
   cin>>x;
   queue<char> parenteses;
   for(int i = 0;i < x.size();i++){
      parenteses.push(x[i]);
   }
   int E = 0;
   while(!parenteses.empty()){
      if(parenteses.front() == '('){
         E++;
      }
      if(parenteses.front() == ')' && E > 0){
         E--;
      }
      parenteses.pop();
   }
   if(E == 0){
      cout<<"Partiu RU!\n";
   }
   else{
      cout<<"Ainda temos "<<E<<" assunto(s) pendente(s)!\n";
   }

   return 0;
}