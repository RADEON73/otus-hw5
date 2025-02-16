#pragma once
#include "GrObject.h"
#include <iostream>

/// Класс прямоугольника
class GrRectangle : public GrObject
{
public:
    /// Конструктор
    GrRectangle(POINT point, double width, double height, IDocument* parent = nullptr)
        : point(point), width(width), height(height)
    {
        setType(GrObjectType::Rectangle);
        setParent(parent);
    }

    /// Реализация отрисовки прямоугольника
    void draw() const override
    {
        std::cout << "Отрисовка прямоугольника прошла успешно" << std::endl;
    }

private:
    POINT point{ 0, 0 }; //Левый верхний угол
    double width{ 0 }; //Ширина
    double height{ 0 }; //Высота
};
