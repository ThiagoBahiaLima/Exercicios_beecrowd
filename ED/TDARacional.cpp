#include <bits/stdc++.h>
using namespace std;

int main(){

   long long int casos;
   cin>>casos;
   while(casos--){
      long long int N1 = 0,N2 = 0,D1 = 0,D2 = 0,RN = 0,RD = 0;
      char a,b,c;
      cin>>N1>>a>>D1>>b>>N2>>c>>D2;
      if(b == '+'){
         RN = N1*D2 + N2*D1;
         RD = D1*D2;
      }
      if(b == '-'){
         RN = N1*D2 - N2*D1;
         RD = D1*D2;
      }
      if(b == '*'){
         RN = N1*N2;
         RD = D1*D2;
      }
      if(b == '/'){
         RN = N1*D2;
         RD = D1*N2;
      }
      N1 = RN;
      N2 = RD;
      if(N1 < 0){
         N1 = N1*(-1);
      }
      if(N1 < N2){
         long long int aux = N1;
         N1 = N2;
         N2 = aux;
      }
      while(N1%N2 != 0){
         long long int m = N2;
         N2 = N1%N2;
         N1 = m;
      }
      cout<<RN<<"/"<<RD<<" = "<<RN/N2<<"/"<<RD/N2<<"\n";
   }

   return 0;
}