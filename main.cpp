#include <QtWidgets/qapplication.h>
#include <QtWidgets/qtableview.h>
#include <QtWidgets/qheaderview.h>
#include <QApplication>

#include "mywidget.h"
#include "MyModel.h"

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
   MyModel myModel(0);
   tableView.setModel( &myModel );
//   tableView.setFixedsize(500,300);
   tableView.setGeometry(600,200,500,800); // x,y,w,h
   tableView.verticalHeader()->hide();
   tableView.show();
   return a.exec();
}
