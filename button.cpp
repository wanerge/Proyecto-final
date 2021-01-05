#include "button.h"
#include <QFont>

Button::Button(QString text)
{
    this->setText(text);
    this->resize(100,100);
    QFont font;
    font.setBold(true);
    font.setPixelSize(29);
    setFont(font);
}

Button::~Button()
{

}
