#include <iostream>    // Para entrada/saída padrão
#include <sstream>     // Para usar std::istringstream
#include <string>      // Para manipular strings
#include <set>         // Para armazenar palavras únicas e ordenadas

int main() {
    
    for(int i = 0;i < 5;i++){
        std::string frase;

        // Solicita ao usuário que digite uma frase
        std::cout << "Digite uma frase: ";
        std::getline(std::cin, frase); // Lê a linha inteira com espaços

        std::istringstream iss(frase); // Cria um fluxo de entrada com a string

        std::string palavra;
        std::set<std::string> palavras; // Set para armazenar palavras únicas em ordem

        // Extrai palavras separadas por espaço e insere no set
        while (iss >> frase) {
            palavras.insert(frase);
        }

        // Exibe as palavras usando um iterador explícito
        std::cout << "\nPalavras únicas e ordenadas:\n";
        for (std::set<std::string>::iterator it = palavras.begin(); it != palavras.end(); ++it) {
            std::cout << *it << std::endl;
        }
    }
    return 0;
}