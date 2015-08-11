#include <iostream>
#include <QApplication>
#include <QHeaderView>
#include <QPushButton>
#include <QSplitter>
#include <QScrollArea>
#include <QTableView>
#include <QVBoxLayout>
#include <QWidget>
#include "EwWidget.hh"
#include "TableModel.hh"
#include "TableView.hh"

int main(int argc, char **argv)
{
  QApplication a(argc, argv);

  QWidget *tWidget = new QWidget(0);

  EwWidget *tEwWidget = new EwWidget(tWidget);

  QScrollArea *tScrollArea = new QScrollArea(tWidget);
  tScrollArea->setFixedSize(EwWidget::kWidth,EwWidget::kHeight);
  tScrollArea->setWidgetResizable(false);
  tScrollArea->setBackgroundRole(QPalette::Dark);

  tScrollArea->setWidget(tEwWidget);

//  tWidget->setStyleSheet("QAbstractScrollArea { margin: 16px; }");

  QPushButton *tAddContactButton = new QPushButton("Add Contact Entry",tWidget);
  QPushButton *tRemoveContactButton = new QPushButton("Remove Contact Entry",tWidget);
  QPushButton *tAddClirButton = new QPushButton("Add CLIR Entry",tWidget);
  QPushButton *tRemoveClirButton = new QPushButton("Remove CLIR Entry",tWidget);

  QVBoxLayout *tLayout = new QVBoxLayout();
  tLayout->addWidget(tScrollArea);
  tLayout->addWidget(tAddContactButton);
  tLayout->addWidget(tAddClirButton);
  tLayout->addWidget(tRemoveContactButton);
  tLayout->addWidget(tRemoveClirButton);

  tWidget->setLayout(tLayout);

  QObject::connect(tAddContactButton,SIGNAL(released()),tEwWidget,SLOT(addContact()));
  QObject::connect(tAddClirButton,SIGNAL(released()),tEwWidget,SLOT(addClir()));
  QObject::connect(tRemoveContactButton,SIGNAL(released()),tEwWidget,SLOT(removeContact()));
  QObject::connect(tRemoveClirButton,SIGNAL(released()),tEwWidget,SLOT(removeClir()));

  tWidget->show();

  return a.exec();
}
