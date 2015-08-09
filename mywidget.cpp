#include <QtWidgets/qlcdnumber.h>
#include <QtWidgets/qslider.h>
#include <QtWidgets/qboxlayout.h>

#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
   QLCDNumber *lcd = new QLCDNumber(this);
   QSlider *s = new QSlider(Qt::Horizontal,this);

   QVBoxLayout *layout = new QVBoxLayout;
   layout->addWidget(lcd);
   layout->addWidget(s);
   this->setLayout(layout);

   connect(s,SIGNAL(valueChanged(int)),
                         lcd,SLOT(display(int)));
}
