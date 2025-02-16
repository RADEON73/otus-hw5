#pragma once
#include <atomic>
#include <utility>
#include "IDocument.h"

/// Просто чтобы не углубляться в реализацию UUID
using UUID = int;

/// Точка на плоскости (x, y)
using POINT = std::pair<double, double>;

enum class GrObjectType
{
    Unknown,
    Rectangle,
    Circle,
    Line
};

/**
* Общий класс графического объекта
* type - тип графического объекта понадобится когда придется выяснять что за объект вы создали не приводя его dynamic_cast
* parent - указатель на родителя очень понадобится когда придется искать объект в документах например 
* для фокуссировки на нем представления и во многих других случаях
*/
class GrObject
{
public:
    /// Виртуальный деструктор для наследования
    virtual ~GrObject() = default;

    /// Отрисовка графического объекта, должна быть реализована в дочерних классах
    virtual void draw() const = 0;

    /// Получение уникального идентификатора
    int getId() const { return id; }

    /// Получение типа графического объекта
    GrObjectType getType() const { return type; }

    /// Установка типа графического объекта
    void setType(GrObjectType arg) { type = arg; }

    /// Получение родителя
    IDocument* getParent() const { return parent; }

    /// Установка родителя
    void setParent(IDocument* arg) { parent = arg; }

private:
    UUID id{ generateId() }; //Int для упрощения - уникальный идентификатор объекта, всегда полезен
    GrObjectType type{ GrObjectType::Unknown }; //Тип графического объекта
    IDocument* parent{ nullptr }; /// Указатель на родителя (для контроля принадлежности объекта к документу)

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