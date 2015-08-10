#include <iostream>
#include <QApplication>
#include <QTableView>
#include <QHeaderView>
#include <QSplitter>
#include <QVBoxLayout>
#include <QWidget>
#include "TableModel.hh"

QTableView *getTableView(
    QWidget *aParent,
    int aRows,
    int aCols,
    int aX,
    int aY,
    int aWidth,
    int aHeight)
{
  QTableView *tableView = new QTableView(aParent);
  TableModel *tModel = new TableModel(0,aRows,aCols);
  tableView->setModel(tModel);
//  tableView->setGeometry(aX, aY, aWidth, aHeight); // x,y,w,h
  int tRowHeight = tableView->rowHeight(0);
  int tHeaderHeight = tableView->horizontalHeader()->height();
  int tHeight = tHeaderHeight + aRows * tRowHeight;
std::cout << "table row height: " << tableView->rowHeight(0) << std::endl;
  tableView->setGeometry(aX, aY, aWidth, tHeight ); // x,y,w,h
//  tableView->setStyleSheet("QHeaderView::section { background-color: black;}");
  tableView->verticalHeader()->hide();
std::cout << "table height: " << tableView->height() << std::endl;
  return tableView;
}

#if 0
QSizePolicy::Fixed
#endif

int main(int argc, char **argv)
{
  const int kWidth = 300;

  QApplication a(argc, argv);
#if 0
  QAbstractScrollArea::setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff);
  QAbstractScrollArea::setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff);
#endif
  QWidget *tWidget = new QWidget(0);
//  tWidget->setSizePolicy(QSizePolicy::Fixed);
  tWidget->setFixedSize(kWidth,500);
  tWidget->setContentsMargins(0,0,0,0);
  tWidget->setStyleSheet("QHeaderView::section { background-color: gray;}");

  QTableView *tableView1 = getTableView(tWidget,4,3,0,0,kWidth,100);
  int tTableHeight = tableView1->height();
  int tRowHeight = tableView1->rowHeight(1);
  int aY = tTableHeight - tRowHeight + 12;
  QTableView *tableView2 = getTableView(tWidget,5,3,0,tTableHeight,kWidth,300);

  tableView1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  tableView1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  tableView2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  tableView2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
#if 0
  QVBoxLayout *tLayout = new QVBoxLayout();
  tLayout->addWidget(tableView1);
  tLayout->addWidget(tableView2);
  tWidget->setLayout(tLayout);
#endif

  tWidget->show();

#if SPLITTER
  QSplitter *splitter = new QSplitter(Qt::Vertical, 0);
  splitter->setHandleWidth(0);

  QTableView *tableView1 = getTableView();
  QTableView *tableView2 = getTableView();

  splitter->addWidget(tableView1);
  splitter->addWidget(tableView2);

  tableView1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

//  splitter->getScrollArea();

  splitter->show();
#endif
  return a.exec();
}
#if 0
QListView *listview = new QListView;
QTreeView *treeview = new QTreeView;
QTextEdit *textedit = new QTextEdit;
splitter->addWidget(listview);
splitter->addWidget(treeview);
splitter->addWidget(textedit);
#endif
