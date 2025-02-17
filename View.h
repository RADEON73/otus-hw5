#pragma once
#include "Document.h"
#include <functional>

class View
{
public:
    void show();
    //void renderDocument(const Document& document) const;

    //Команды:
    std::function<void(const std::string&)> onActionAddTriggered; //Add document
    std::function<void(const std::string&)> onActionImportTriggered; //Import document
    std::function<void(const std::string&)> onActionExportTriggered; //Export document
    std::function<void()> onActionHelpTriggered; //Help
};