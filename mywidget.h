#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QtWidgets/qwidget.h>

class MyWidget : public QWidget{
   Q_OBJECT

public:
   MyWidget(QWidget *parent = 0);
};

#endif
