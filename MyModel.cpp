#include "mymodel.h"
#include <QFont>
#include <QBrush>
#if 0
#include <QtWidget/qfont.h>#include <QtWidget/qbrush.h>
#endif

MyModel::MyModel(QObject *parent)    :QAbstractTableModel(parent){}int MyModel::rowCount(const QModelIndex & /*parent*/) const{   return 20;}int MyModel::columnCount(const QModelIndex & /*parent*/) const{    return 3;}QVariant MyModel::data(const QModelIndex &index, int role) const{
   int row = index.row();   int col = index.column();
   QVariant v;

   switch( role ){
   case Qt::DisplayRole:      return QString("Row%1, Column%2")            .arg(index.row() + 1)            .arg(index.column() +1);      break;
   case Qt::FontRole:      if (row == 0 && col == 0) //change font only for cell(0,0)      {         QFont boldFont;         boldFont.setBold(true);         return boldFont;      }      break;   case Qt::BackgroundRole:      if (row == 1 && col == 2)  //change background only for cell(1,2)      {         QBrush redBackground(Qt::red);         return redBackground;      }      break;
   default:
     return v;
     break;
   }
   return QVariant();
//   return v;
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const{   if (role == Qt::DisplayRole)   {      if (orientation == Qt::Horizontal) {         switch (section)         {         case 0:            return QString("first");         case 1:            return QString("second");         case 2:            return QString("third");         }      }   }   return QVariant();}