//
// Created by Alam Sánchez on 20/05/19.
//

#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <vector>

class Command {
private:
    std::string description;
    std::string alias;
    std::vector<std::string> lines;
    unsigned int id;

public:
    Command();
    Command(std::string _description, std::string _alias);

    void ReadLines(std::string end_mark);
    void AddLine(std::string line);

    std::string GetLine(unsigned int index);
    std::string GetAlias();
    std::string GetDescription();
    int GetSize();

    void Display();

};


#endif //COMMAND_H
