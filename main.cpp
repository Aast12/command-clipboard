#include <iostream>

#include "Command.h"

#include "CommandContainer.h"

//const std::string FILEPATH = "/home/aast/CLionProjects/untitled1/database.txt";

int main() {


    unsigned int option;

    std::string ans = "s";

    
    CommandContainer cont;

    std::cout << "Introduce una opción:" << std::endl;
    std::cout << "1. Guardar" << std::endl;
    std::cout << "2. Buscar" << std::endl;

    while(ans == "s") {
        std::cin >> option;
        switch (option) {
            case 1: {
                    std::string alias, description;
                    std::cout << "Alias: " ;
                    std::cin >> alias;
                    std::cout << "Descripción: ";
                    std::cin.ignore();
                    std::getline(std::cin, description);
                    Command comm(description, alias);
                    comm.ReadLines("!!");
                    cont.AddCommand(comm);
                }
                break;
            case 2: {
                    std::string alias;
                    std::cout << "Introduce un alias: ";
                    std::cin >> alias;
                    if (!cont.Search(alias)) {
                        std::cout << "No se encontraron resultados." << std::endl;
                    }
                }
                break;
        }
        std::cout << "Desea hacer otra acción? (s/n) ";
        std::cin >> ans;
    }

    cont.Save();
    
    return 0;
}