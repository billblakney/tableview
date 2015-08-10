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
  const int kWidth = 400;

  QApplication a(argc, argv);

  QWidget *tWidget = new QWidget(0);

  EwWidget *tEwWidget = new EwWidget(tWidget);

#if 0
  tWidget->setFixedSize(kWidth,500);
  tWidget->setContentsMargins(0,0,0,0);
  tWidget->setStyleSheet("QHeaderView::section { background-color: gray;}");

  TableView *tableView1 = getTableView(tWidget,4,3,0,0,kWidth,100);
  int tTableHeight = tableView1->height();
  int tRowHeight = tableView1->rowHeight(1);
  int aY = tTableHeight - tRowHeight + 12;

  TableView *tableView2 = getTableView(tWidget,5,3,0,tTableHeight,kWidth,300);
#endif

  QPushButton *tAddContactButton = new QPushButton("Add Contact Entry",tWidget);
  QPushButton *tAddClirButton = new QPushButton("Add CLIR Entry",tWidget);

  tWidget->show();

  return a.exec();
}
