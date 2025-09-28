#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <sstream>

struct duo
{
   std::string pal;
   int dist;
};

bool vazio(std::string palavra)
{
   for(unsigned int i = 0; i < palavra.length(); i++)
   {
      if(palavra[i] != ' ')
      {
         return false;
      }
   }
   return true;
}

int main()
{

   int casos = 0;
   bool primeiro = true;

   std::cin >> casos;

   while(casos--)
   {
      if(!primeiro)
      {
         std::cout << "\n";
      }
      
      primeiro = false;

      std::string palavras;

      std::map<std::string,std::vector<std::string>> garfo;
      std::map<std::string,bool> vis;
      std::map<std::string,bool>::iterator it;

      while(std::cin >> palavras && palavras != "*")
      {
         for(unsigned int i = 0; i < palavras.length(); i++)
         {
            std::string copia = palavras;

            copia[i] = '*';

            garfo[palavras].push_back(copia);
            garfo[copia].push_back(palavras);
         }
      }

      std::cin.ignore();

      while(getline(std::cin, palavras) && !vazio(palavras))
      {
         for(it = vis.begin(); it != vis.end(); it++)
         {
            it->second = false;
         }

         std::istringstream x(palavras);

         std::queue<duo> fila;

         std::string part, dest;

         int dist = -1;

         x >> part;
         x >> dest;

         fila.push({part, 0});

         while(!fila.empty() && dist == -1)
         {
            duo D = fila.front();

            for(unsigned int i = 0; i < garfo[D.pal].size(); i++)
            {
               if(!vis[garfo[D.pal][i]])
               {
                  vis[garfo[D.pal][i]] = true;
                  fila.push({garfo[D.pal][i], D.dist + 1});

                  if(garfo[D.pal][i] == dest)
                  {
                     dist = D.dist + 1;
                  }
               }
            }

            fila.pop();
         }

         std::cout << palavras << " " << dist/2 << "\n";
      }
   }

   return 0;
}