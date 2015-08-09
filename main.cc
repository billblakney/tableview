#include <QApplication>
#include <QTableview>
#include <QHeaderview>
#include "TableModel.hh"

int main(int argc,char **argv)
{
   QApplication a(argc, argv);
   QTableView tableView;
   TableModel myModel(0);
   tableView.setModel( &myModel );
   tableView.setGeometry(600,200,500,800); // x,y,w,h
   tableView.setStyleSheet("QHeaderView::section { background-color:gray }");
   tableView.verticalHeader()->hide();
   tableView.show();
   return a.exec();
}
