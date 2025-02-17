#include "Controller.h"
#include <iostream>

Controller::Controller(View* view) : view(view)
{
    if (view) {
        view->onActionHelpTriggered = []() { 
            std::cout << "Available commands:" << std::endl;
            std::cout << "  help - Show list of commands" << std::endl;
            std::cout << "  add - Add new document" << std::endl;
            std::cout << "  import - Import new document" << std::endl;
            std::cout << "  export - Export new document" << std::endl;
            std::cout << "  exit - Exit the program" << std::endl;
            };
        view->onActionAddTriggered = [this](const std::string& message) { 
            std::cout << "A request to create a document has been sent!" << std::endl;
            if (model)
                model->CreateNewDocument(message);
            };
        view->onActionImportTriggered = [this](const std::string& message) {
            std::cout << "A request to import a document has been sent!" << std::endl;
            if (model)
                model->importDocument(message);
            };
        view->onActionExportTriggered = [this](const std::string& message) {
            std::cout << "A request to export a document has been sent!" << std::endl;
            if (model)
                model->exportDocument(message);
            };
    }
}