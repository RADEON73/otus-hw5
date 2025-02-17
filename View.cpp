#include "View.h"
#include <unordered_map>
#include <functional>
#include <iostream>
#include <string>

void View::show()
{
    bool running = true;
    std::unordered_map<std::string, std::function<void()>> commands = {
        { "help", [this]() { 
                if (onActionHelpTriggered)
                    onActionHelpTriggered();
        } },
        { "add", [this]() {
                std::string name;
                std::cout << "Enter the document name: ";
                std::cin >> name;
                if (onActionAddTriggered)
                    onActionAddTriggered(name);
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } },
        { "import", [this]() {
                std::string name;
                std::cout << "Enter the path to the file: ";
                std::cin >> name;
                
                if (onActionImportTriggered)
                    onActionImportTriggered(name);
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } },
        { "export", [this]() {
                std::string name;
                std::cout << "Enter the path to the file: ";
                std::cin >> name;
                if (onActionExportTriggered)
                    onActionExportTriggered(name);
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } },
        { "exit", [&running]() {
            std::cout << "Exit the program...";
            running = false;
        } },
    };
    while (running) {
        std::cout << "Enter command: ";
        std::string input;
        std::getline(std::cin, input);
        if (auto it = commands.find(input); it != commands.end()) {
            it->second();
        }
        else
            std::cerr << "Error! Unknown command. 'help' to observer command list\n";
    }
}

/*
void View::renderDocument(const Document& document) const
{
    for (const auto& obj : document.getGrObjects())
        obj->draw();
}
*/