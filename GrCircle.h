#pragma once
#include "GrObject.h"
#include <iostream>

/// Класс круга
class GrCircle : public GrObject
{
public:
    /// Конструктор
    GrCircle(POINT center, double radius, IDocument* parent = nullptr ) : center(center), radius(radius)
    {
        setType(GrObjectType::Circle);
        setParent(parent);
    }

    /// Реализация отрисовки круга
    void draw() const override
    {
        std::cout << "Отрисовка круга прошла успешно" << std::endl;
    }

private:
    POINT center{ 0, 0 }; //Центр
    double radius{ 0 }; //Радиус
};