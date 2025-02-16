#include "Document.h"
#include <iostream>

Document::Document(const std::string& name) : name(name)
{
}

std::string Document::getName() const
{
    return name;
}

void Document::setName(const std::string& arg)
{
    name = arg;
}
void Document::addGrObject(std::shared_ptr<GrObject> grObject)
{
    if (!grObject) {
        std::cerr << "Нельзя добавить nullptr в документ" << std::endl;
        return;
    }
    if (auto it = std::find(grObjects.begin(), grObjects.end(), grObject); it != grObjects.end()) {
        std::cerr << "Объект с ID: " << grObject->getId() << " уже есть в документе " << id << std::endl;
        return;
    }
    grObjects.push_back(grObject);
}

void Document::removeGrObject(std::shared_ptr<GrObject> grObject)
{
    if (auto it = std::find(grObjects.begin(), grObjects.end(), grObject); it != grObjects.end())
        grObjects.erase(it);
    else
        std::cerr << "Объект с ID: " << grObject->getId() << " отсутствует в документе " << id << std::endl;
}

const std::vector<std::shared_ptr<GrObject>>& Document::getGrObjects() const
{
    return grObjects;
}
