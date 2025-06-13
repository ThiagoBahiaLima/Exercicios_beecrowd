#include <bits/stdc++.h>
using namespace std;

int main(){

   int comandos;
   set<string> possivel;
   while(cin>>comandos){
      stack<int> A;
      queue<int> B;
      vector<int> C;
      bool pilha = true, fila = true, filaPriori = true;
      int ordem, item;
      while(comandos--){
         cin>>ordem>>item;
         if(ordem == 1){
            A.push(item);
            B.push(item);
            C.push_back(item);
            sort(C.begin(),C.end());
         }
         else{
            if(item == A.top() && pilha){
               A.pop();
               possivel.insert("A");
            }
            else{
               pilha = false;
               possivel.erase("A");
            }
            if(item == B.front() && fila){
               B.pop();
               possivel.insert("B");
            }
            else{
               fila = false;
               possivel.erase("B");
            }
            if(item == C[C.size() - 1] && filaPriori){
               C.pop_back();
               possivel.insert("C");
            }
            else{
               filaPriori = false;
               possivel.erase("C");
            }
         }
      }
      if(possivel.size() == 0){
         cout<<"impossible\n";
      }
      if(possivel.size() == 1){
         if(pilha){
            cout<<"stack\n";
         }
         if(fila){
            cout<<"queue\n";
         }
         if(filaPriori){
            cout<<"priority queue\n";
         }
      }
      if(possivel.size() > 1){
         cout<<"not sure\n";
      }
      possivel.clear();
   }

   return 0;
}