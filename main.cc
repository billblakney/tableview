#include <QApplication>
#include <QTableView>
#include <QHeaderview>
#include <QSplitter>
#include "TableModel.hh"

QTableView *getTableView()
{
  QTableView *tableView = new QTableView(0);
   TableModel *myModel = new TableModel(0);
   tableView->setModel( myModel );
   tableView->setGeometry(600,200,500,400); // x,y,w,h
   tableView->setStyleSheet("QHeaderView::section { background-color:gray }");
   tableView->verticalHeader()->hide();
   return tableView;
}

int main(int argc,char **argv)
{
   QApplication a(argc, argv);
#define NEW
#ifdef NEW
  QSplitter *splitter = new QSplitter(Qt::Vertical,0);
  splitter->setHandleWidth(0);

   QTableView *tableView1 = getTableView();
   QTableView *tableView2 = getTableView();

splitter->addWidget(tableView1);
splitter->addWidget(tableView2);

   splitter->show();
#else
   QTableView tableView(0);
   TableModel myModel(0);
   tableView.setModel( &myModel );
   tableView.setGeometry(600,200,500,800); // x,y,w,h
   tableView.setStyleSheet("QHeaderView::section { background-color:gray }");
   tableView.verticalHeader()->hide();
   tableView.show();
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
