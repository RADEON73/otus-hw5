#include "Model.h"
#include <iostream>
#include <fstream>

void Model::CreateNewDocument(const std::string_view& name) const
{
    std::cout << "A new document with the name '" << name << "' has been created" << std::endl;
}

void Model::importDocument(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open file for import: " << filename << std::endl;
        return;
    } 
    //TODO: Тут должен быть импорт
    std::cout << "Document imported from file: " << filename << std::endl;
}

void Model::exportDocument(const std::string& filename) const
{
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open file for export: " << filename << std::endl;
        return;
    }
    //TODO: Тут должен быть экспорт
    std::cout << "The document has been exported to a file: " << filename << std::endl;
}

/*
std::shared_ptr<Document> Model::getActiveDocument() const
{
    if (documents.empty())
        throw std::runtime_error("Нет активного документа");
    return documents.at(activeDocumentIndex);
}

void Model::closeDocument(size_t index)
{
    if (index >= documents.size()) {
        throw std::out_of_range("Индекс документа выходит за пределы диапазона");
    }
    std::cout << "Документ с именем: " << documents[index]->getName() << " закрыт" << std::endl;
    documents.erase(documents.begin() + index);
    if (activeDocumentIndex == index)
        activeDocumentIndex = 0;
}

void Model::setActiveDocument(size_t index)
{
    if (index >= documents.size()) {
        throw std::out_of_range("Индекс документа выходит за пределы диапазона");
    }
    activeDocumentIndex = index;
    std::cout << "Активный документ изменен на: " << documents[activeDocumentIndex]->getName() << std::endl;
}

const std::vector<std::shared_ptr<Document>>& Model::getDocuments() const
{
    return documents;
}
*/