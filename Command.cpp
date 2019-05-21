//
// Created by Alam Sánchez on 20/05/19.
//

#include "Command.h"

Command::Command() { }

Command::Command(std::string _description, std::string _alias) {
    description = _description;
    alias = _alias;
}

void Command::ReadLines(std::string end_mark = "!!") {
    std::string line;
    int line_count = 1;
    std::cout << "1: ";
    while (std::getline(std::cin, line)) {
        if (line == end_mark) break;

        lines.push_back(line);
        std::cout << ++line_count << ": ";
    }
}

void Command::AddLine(std::string line) {
    lines.push_back(line);
}

std::string Command::GetLine(unsigned int index) {

    if (index > lines.size()) {
        return "!!";
    } else {
        return lines[index - 1];
    }
}

std::string Command::GetAlias() {
    return alias;
}

std::string Command::GetDescription() {
    return description;
}

int Command::GetSize() {
    return lines.size();
}

void Command::Display() {
    for (auto line : lines) {
        std::cout << line << std::endl;
    }
}
