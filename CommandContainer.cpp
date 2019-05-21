//
// Created by Alam Sánchez on 20/05/19.
//

#include "CommandContainer.h"

CommandContainer::CommandContainer() {
    Init();
}

void CommandContainer::AddCommand(Command command) {
    data.push_back(command);
}

void CommandContainer::Init() {
    std::ifstream idata_file;

    idata_file.open("./database.txt");
    unsigned int counter = 0, size = 0;
    append_index = 0;
    std::string line, alias, description;
    Command command;
    if (idata_file.is_open()) {
        while (std::getline(idata_file, line)) {
            if (counter == 0) {
                alias = line;
                counter++;
                append_index++;
            }
            else if (counter == 1) {
                description = line;
                command = Command(description, alias);
                counter++;
            }
            else if (counter == 2) {
                size = std::atoi(line.c_str());
                counter++;
            }
            else {
                command.AddLine(line);
                for (int i = 0; i < size - 1; i++) {
                    std::getline(idata_file, line);
                    command.AddLine(line);
                }
                counter = 0;
                AddCommand(command);
            }

        }
        append_index = std::max(int(append_index) - 1, 0);
    } else {
        std::cout << "Error: No se pudo abrir el archivo." << std::endl;
    }

    idata_file.close();
}

bool CommandContainer::Search(std::string key) {
    for (auto command : data) {
        if (command.GetAlias() == key) {
            command.Display();
            return true;
        }
    }
    return false;
}

void CommandContainer::Show() {
    for (auto command : data) {
        command.Display();
    }
}

void CommandContainer::Save() {
    std::ofstream odata_file;

    odata_file.open("./database.txt", std::ios::app);

    if (odata_file.is_open()) {
        for (unsigned int i = append_index; i < data.size(); i++) {
            Command &command = data[i];
            odata_file << command.GetAlias() << std::endl;
            odata_file << command.GetDescription() << std::endl;
            odata_file << command.GetSize() << std::endl;
            unsigned int index = 1;
            std::string line = command.GetLine(index++);
            while (line != "!!") {
                odata_file << line  << std::endl;
                line = command.GetLine(index++);
                if (line == "!!") break;
            }
        }
    } else {
        std::cout << "Error: No se pudo abrir el archivo." << std::endl;
    }

    odata_file.close();
}
