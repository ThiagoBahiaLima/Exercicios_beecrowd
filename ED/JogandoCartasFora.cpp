#include <bits/stdc++.h>
using namespace std;

int main(){

   int cartas = 1;
   while(cin>>cartas && cartas != 0){
      queue<int> carta;
      for(int i = 0;i < cartas;i++){
         carta.push(i + 1);
      }
      int memoria = 0;
      for(int i = 0;memoria != carta.front();i++){
         if(i == 0){
            cout<<"Discarded cards: "<<carta.front();
            carta.pop();
         }
         if(i%2 != 0){
            carta.push(carta.front());
            memoria = carta.front();
            carta.pop();
         }
         if(i%2 == 0 && i != 0){
            cout<<", "<<carta.front();
            carta.pop();
         }
      }
      cout<<"\n"<<"Remaining card: "<<memoria<<"\n";
   }

   return 0;
}