#include <QFont>
#include <QBrush>
#include "TableModel.hh"

TableModel::TableModel(QObject *parent)    :QAbstractTableModel(parent){}int TableModel::rowCount(const QModelIndex & /*parent*/) const{   return 20;}int TableModel::columnCount(const QModelIndex & /*parent*/) const{    return 3;}QVariant TableModel::data(const QModelIndex &index, int role) const{
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

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const{   if (role == Qt::DisplayRole)   {      if (orientation == Qt::Horizontal) {         switch (section)         {         case 0:            return QString("first");         case 1:            return QString("second");         case 2:            return QString("third");         }      }   }   return QVariant();}