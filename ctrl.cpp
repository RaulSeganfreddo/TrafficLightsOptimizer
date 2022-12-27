#include "ctrl.h"

Ctrl::Ctrl(Model *m)
{
    model = m;
    view = nullptr;
}

void Ctrl::setView(View *v)
{
    view = v;
}