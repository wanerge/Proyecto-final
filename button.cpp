#include "button.h"
#include <QFont>

Button::Button(QString text)
{
    this->setText(text);
    this->resize(100,100);
    this->setFlat(true);
    this->setAutoFillBackground(true);

    QPalette pal;
    pal.setColor(QPalette::Button, QColor(79, 79, 79));
    pal.setColor(QPalette::ButtonText, QColor(111, 3, 3)); //(255, 0, 0), (0x00, 0x00, 0xff)
    this->setPalette(pal);

    QFont font;
    font.setFamily("OCR A Extended");
    font.setBold(true);
    font.setPixelSize(35);
    this->setFont(font);
}

Button::~Button()
{

}
