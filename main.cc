#include <iostream>
#include <QApplication>
#include <QHeaderView>
#include <QPushButton>
#include <QSplitter>
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

  QPushButton *tAddContactButton = new QPushButton("Add Contact Entry",tWidget);
  QPushButton *tAddClirButton = new QPushButton("Add CLIR Entry",tWidget);

  QVBoxLayout *tLayout = new QVBoxLayout();
  tLayout->addWidget(tEwWidget);
  tLayout->addWidget(tAddContactButton);
  tLayout->addWidget(tAddClirButton);

  tWidget->setLayout(tLayout);

  QObject::connect(tAddContactButton,SIGNAL(released()),tEwWidget,SLOT(addContact()));
  QObject::connect(tAddClirButton,SIGNAL(released()),tEwWidget,SLOT(addClir()));

  tWidget->show();

  return a.exec();
}
