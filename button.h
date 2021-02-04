#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>

class Button : public QPushButton
{
public:
    //constructor se crea un boton con caracteristicas ya predefinidas
    Button(QString text);
    ~Button();
};

#endif // BUTTON_H
