#pragma once
#include "GrObject.h"
#include <iostream>

class GrLine : public GrObject
{
public:
    GrLine(POINT startPoint, POINT endPoint, IDocument* parent = nullptr) : startPoint(startPoint), endPoint(endPoint)
    {
        setType(GrObjectType::Line);
        setParent(parent);
    }

    void draw() const override
    {
        std::cout << "Отрисовка линии прошла успешно" << std::endl;
    }

private:
    POINT startPoint; //Начальная точка
    POINT endPoint; //Конечная точка
};
