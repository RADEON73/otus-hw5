#pragma once
#include "Document.h"
#include <memory>
#include <string>

/**
* Класс менеджера документов, хранящий список документов и управляющий им
*/
class Model
{
public:
    /// Конструктор
    Model() = default;

    /// Создание нового документа
    void CreateNewDocument(const std::string_view& name = "Новый документ") const;

    /// Импорт документа
    void importDocument(const std::string& filename);

    /// Экспорт документа
    void exportDocument(const std::string& filename) const;

    /// Получение активного документа
    //std::shared_ptr<Document> getActiveDocument() const;

    /// Установка активного документа
    //void setActiveDocument(size_t index);

    /// Закрытие документа
    //void closeDocument(size_t index);

    /// Получить список документов
    //const std::vector<std::shared_ptr<Document>>& getDocuments() const;

//private:
    //std::vector<std::shared_ptr<Document>> documents;
    //size_t activeDocumentIndex{ 0 };
};