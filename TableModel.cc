#include <iostream>
#include <QBrush>
#include <QFont>
#include <QVariant>
#include "TableModel.hh"

#ifdef USE_ABSTRACT
#else
#include <QList>
#include <QStandardItem>
#endif


const int TableModel::kColumns = 8;

const int TableModel::kColCD  = 0;
const int TableModel::kColLPI = 1;
const int TableModel::kColTOE = 2;
const int TableModel::kColBNG = 3;
const int TableModel::kColFRQ = 4;
const int TableModel::kColPRF = 5;
const int TableModel::kColAMP = 6;
const int TableModel::kColPW  = 7;

static QBrush tBlackBrush;
#ifdef USE_ABSTRACT
TableModel::TableModel(QObject *parent,int aRows)
  : QAbstractTableModel(parent),
    _rows(aRows)
{
}
#else
TableModel::TableModel(QObject *parent,int aRows)
  : QStandardItemModel(parent)
{
  for( int i = 0; i < aRows; i++ )
  {
    addRow();
  }
}
#endif

#ifdef USE_ABSTRACT
#else
void TableModel::removeRow()
{
  removeRows(0,1);
}

void TableModel::addRow()
{
tBlackBrush.setColor(Qt::red);

    QList<QStandardItem*> tList;

    QStandardItem *tItem0 = new QStandardItem(QString("A0"));
    QStandardItem *tItem1 = new QStandardItem(QString("A1"));
    QStandardItem *tItem2 = new QStandardItem(QString("A2"));
    QStandardItem *tItem3 = new QStandardItem(QString("A3"));
    QStandardItem *tItem4 = new QStandardItem(QString("A4"));
    QStandardItem *tItem5 = new QStandardItem(QString("A5"));
    QStandardItem *tItem6 = new QStandardItem(QString("A6"));
    QStandardItem *tItem7 = new QStandardItem(QString("A7"));
    tList.push_back(tItem0);
    tList.push_back(tItem1);
    tList.push_back(tItem2);
    tList.push_back(tItem3);
    tList.push_back(tItem4);
    tList.push_back(tItem5);
    tList.push_back(tItem6);
    tList.push_back(tItem7);

    appendRow(tList);

    for( int i = 0; i < kColumns; i++ )
    {
      int tRow = rowCount() - 1;
      setData(index(tRow,i),QColor(Qt::blue),Qt::BackgroundRole);
      setData(index(tRow,i),QColor(Qt::white),Qt::ForegroundRole);
    }
}
#endif

#ifdef USE_ABSTRACT
int TableModel::rowCount(const QModelIndex & /*parent*/) const
{
  return _rows;
}

int TableModel::columnCount(const QModelIndex & /*parent*/) const
{
  return kColumns;
}

QString TableModel::getCellValue(int aRow,int aCol) const
{
  switch (aCol) {
    case kColCD:
      return QString("E1");
      break;
    case kColLPI:
      return QString("X");
      break;
    case kColTOE:
      return QString("14:19:06");
      break;
    case kColBNG:
      return QString("145");
      break;
    case kColFRQ:
      return QString("3054.9");
      break;
    case kColPRF:
      return QString("10039.1");
      break;
    case kColAMP:
      return QString("-65.3");
      break;
    case kColPW:
      return QString("6.19");
      break;
    default:
      return QString("Default");
      break;
  }
    return QString("R%1, C%2").arg(aRow).arg(aCol);
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
  int row = index.row();
  int col = index.column();

  switch (role)
  {
  case Qt::DisplayRole:
    {
    QString tValue = getCellValue(row,col);
    return tValue;
    }
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
{
  switch (role)
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
      case 3:
        return QString("BNG");
      case 4:
        return QString("FRQ");
      case 5:
        return QString("PRF");
      case 6:
        return QString("AMP");
      case 7:
        return QString("PW");
      }
    }
    break;
  case Qt::ForegroundRole:
  {
    QBrush foreground(Qt::white);
    return foreground;
    break;
  }
  case Qt::BackgroundRole: // seems not applicable
  {
    QBrush foreground(Qt::gray);
    return foreground;
    break;
  }
  }
  return QVariant();
}
#else
#endif
