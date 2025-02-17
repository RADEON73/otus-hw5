#pragma once
#include "Model.h"
#include "View.h"

class Controller
{
public:
    explicit Controller(View* view);
    ~Controller() = default;

    void setModel(Model* arg) { model = arg; };
    void resetModel() { model = nullptr; };

private:
    Model* model{ nullptr };
    View* view{ nullptr };
};