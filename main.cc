#include <QApplication.h>
#include <Qtableview.h>
#include <Qheaderview.h>
#include <QApplication>
#include "TableModel.hh"

int main(int argc,char **argv)
{
#if 0
   QApplication a(argc,argv);

   MyWidget w(0);
   //a.setMainWidget(w);
   w.show();

   return a.exec();
#endif

   QApplication a(argc, argv);
   QTableView tableView;
   TableModel myModel(0);
   tableView.setModel( &myModel );
//   tableView.setFixedsize(500,300);
   tableView.setGeometry(600,200,500,800); // x,y,w,h
   tableView.verticalHeader()->hide();
   tableView.show();
   return a.exec();
}
