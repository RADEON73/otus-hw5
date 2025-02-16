#pragma once
#include "IDocument.h"
#include "GrObject.h"
#include <memory>
#include <vector>
#include <string>

/**
* Класс документа для хранения графических объектов
* Не учитывается координаты расположения объектов, хотя куда без них в графике
* Объекты хранятся списком в векторе просто для примера
*/
class Document : public IDocument
{
public:
    explicit Document(const std::string& name);
    /// Название документа
    std::string getName() const;

    /// Установка названия документа
    void setName(const std::string& arg);

    /// Добавление объекта в документ
    void addGrObject(std::shared_ptr<GrObject> grObject);

    /// Удаление объекта из документа
    void removeGrObject(std::shared_ptr<GrObject> grObject);

    /// Получение списка объектов
    const std::vector<std::shared_ptr<GrObject>>& getGrObjects() const;

private:
    std::string name; //Название документа
    UUID id{ generateId() }; //Int для упрощения, уникальный идентификатор объекта, всегда полезен
    std::vector<std::shared_ptr<GrObject>> grObjects; //Cписок объектов в документе

    /**
    * Генерация уникального ID при создании объекта в пределах сессии, как пример [очень тупая :)
    * В реальности надо что-то типа UUID например из boost и сериализацию/десериализацию с
    * сохранением ID в файл при закрытии программы (которую я тоже не сделал)
    */
    static UUID generateId()
    {
        static std::atomic<UUID> counter{ 0 };
        return ++counter;
    }
};