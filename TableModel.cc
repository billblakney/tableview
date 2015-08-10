#include <iostream>
#include <QBrush>
#include <QFont>
#include "TableModel.hh"
const int TableModel::kColumns = 8;const int TableModel::kColCD  = 0;const int TableModel::kColLPI = 1;const int TableModel::kColTOE = 2;const int TableModel::kColBNG = 3;const int TableModel::kColFRQ = 4;const int TableModel::kColPRF = 5;const int TableModel::kColAMP = 6;const int TableModel::kColPW  = 7;
TableModel::TableModel(QObject *parent,int aRows)
  : QAbstractTableModel(parent),
    _rows(aRows)
{}

int TableModel::rowCount(const QModelIndex & /*parent*/) const
{
  return _rows;
}

int TableModel::columnCount(const QModelIndex & /*parent*/) const
{
  return kColumns;
}
QString TableModel::getCellValue(int aRow,int aCol) const
{  switch (aCol) {
    case kColCD:      return QString("E1");
      break;
    case kColLPI:      return QString("X");      break;    case kColTOE:      return QString("14:19:06");      break;    case kColBNG:      return QString("145");      break;    case kColFRQ:      return QString("3054.9");      break;    case kColPRF:      return QString("10039.1");      break;    case kColAMP:      return QString("-65.3");      break;    case kColPW:      return QString("6.19");      break;    default:
      return QString("Default");      break;
  }
    return QString("R%1, C%2").arg(aRow).arg(aCol);}
QVariant TableModel::data(const QModelIndex &index, int role) const
{
  int row = index.row();
  int col = index.column();

  switch (role)
  {
  case Qt::DisplayRole:    {    QString tValue = getCellValue(row,col);    return tValue;    }
    break;
  case Qt::FontRole:
    if (row == 0 && col == 0) //change font only for cell(0,0)
    {
      QFont boldFont;
      boldFont.setBold(true);
      return boldFont;
    }
    break;
  case Qt::BackgroundRole:
  {
    QBrush blackBackground(Qt::black);
    return blackBackground;
  }
    break;
  case Qt::ForegroundRole:
  {
    QBrush whiteForeground(Qt::white);
    return whiteForeground;
  }
    break;
  }
  return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation,
    int role) const
{  switch (role)
  {
  case Qt::DisplayRole:
    if (orientation == Qt::Horizontal)
    {
      switch (section)
      {
      case 0:
        return QString("CD");
      case 1:
        return QString("LPI");
      case 2:
        return QString("TOE");
      case 3:        return QString("BNG");      case 4:        return QString("FRQ");      case 5:        return QString("PRF");      case 6:        return QString("AMP");      case 7:        return QString("PW");      }
    }
    break;
  case Qt::ForegroundRole:
  {
    QBrush foreground(Qt::white);
    return foreground;
    break;
  }
  case Qt::BackgroundRole: // seems not applicable  {    QBrush foreground(Qt::gray);    return foreground;    break;  }  }
  return QVariant();
}
