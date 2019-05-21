//
// Created by Alam Sánchez on 20/05/19.
//

#ifndef COMMANDCONTAINER_H
#define COMMANDCONTAINER_H

#include "Command.h"
#include <fstream>

class CommandContainer {
private:
    std::vector<Command> data;
    std::string file_path;
    unsigned int append_index = 0;

public:
    CommandContainer();
    CommandContainer(std::string path);
    void Init();
    void AddCommand(Command command);

    bool Search(std::string key);

    void Show();

    void Save();

};


#endif //COMMANDCONTAINER_H
