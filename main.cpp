#include <iostream>
#include "View.h"
#include "Model.h"
#include "Controller.h"

/// Главная функция программы
int main()
{
    View view;
    Model model;
    Controller controller(&view);
    controller.setModel(&model);
    view.show();
}

