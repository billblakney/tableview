#include <iostream>
#include <QBrush>
#include <QFont>
#include <QVariant>
#include "TableModel.hh"

#include <QList>
#include <QStandardItem>


const int TableModel::kColumns = 8;

const int TableModel::kColCD  = 0;
const int TableModel::kColLPI = 1;
const int TableModel::kColTOE = 2;
const int TableModel::kColBNG = 3;
const int TableModel::kColFRQ = 4;
const int TableModel::kColPRF = 5;
const int TableModel::kColAMP = 6;
const int TableModel::kColPW  = 7;

const QColor TableModel::kHeaderForegroundColor(QColor(Qt::white));
const QColor TableModel::kHeaderBackgroundColor(QColor(Qt::darkGray));
const QColor TableModel::kDataBackgroundColor(QColor(Qt::black));
const QColor TableModel::kDataForegroundColor(QColor(Qt::green));

QFont TableModel::kHeaderFont;
QFont TableModel::kDataFont;

//-----------------------------------------------------------------------------
// Constructor.
//-----------------------------------------------------------------------------
TableModel::TableModel(QObject *parent,int aRows)
  : QStandardItemModel(parent)
{
  kHeaderFont.setBold(true);
  kDataFont.setBold(true);

  for( int i = 0; i < aRows; i++ )
  {
    addRow();
  }
}

//-----------------------------------------------------------------------------
// Setup horizontal header labels, including color and font.
//-----------------------------------------------------------------------------
void TableModel::setupHorizontalHeader()
{
  QStringList tHeaderLabels;

  QString tCDLabel("CD");
  QString tLPILabel("LPI");
  QString tTOELabel("TOE");
  QString tBNGLabel("BNG");
  QString tFRQLabel("FRQ");
  QString tPRFLabel("PRF");
  QString tAMPLabel("AMP");
  QString tPWLabel("PW");

  tHeaderLabels.push_back(tCDLabel);
  tHeaderLabels.push_back(tLPILabel);
  tHeaderLabels.push_back(tTOELabel);
  tHeaderLabels.push_back(tBNGLabel);
  tHeaderLabels.push_back(tFRQLabel);
  tHeaderLabels.push_back(tPRFLabel);
  tHeaderLabels.push_back(tAMPLabel);
  tHeaderLabels.push_back(tPWLabel);

  setHorizontalHeaderLabels(tHeaderLabels);

  for( int i = 0; i < kColumns; i++)
  {
    setHeaderData(i,Qt::Horizontal,kHeaderBackgroundColor,Qt::BackgroundRole);
    setHeaderData(i,Qt::Horizontal,kHeaderForegroundColor,Qt::ForegroundRole);
    setHeaderData(i,Qt::Horizontal,kHeaderFont,Qt::FontRole);
  }
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void TableModel::removeRow()
{
  removeRows(0,1);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void TableModel::addRow()
{
    QList<QStandardItem*> tList;

    QStandardItem *tItem0 = new QStandardItem(QString("E1"));
    QStandardItem *tItem1 = new QStandardItem(QString("X"));
    QStandardItem *tItem2 = new QStandardItem(QString("14:19:06"));
    QStandardItem *tItem3 = new QStandardItem(QString("145"));
    QStandardItem *tItem4 = new QStandardItem(QString("3054.9"));
    QStandardItem *tItem5 = new QStandardItem(QString("10039.1"));
    QStandardItem *tItem6 = new QStandardItem(QString("-65.2"));
    QStandardItem *tItem7 = new QStandardItem(QString("6.19"));
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
      setData(index(tRow,i),kDataBackgroundColor,Qt::BackgroundRole);
      setData(index(tRow,i),kDataBackgroundColor,Qt::BackgroundRole);
      setData(index(tRow,i),kDataForegroundColor,Qt::ForegroundRole);
      setData(index(tRow,i),kDataFont,Qt::FontRole);
    }
}

#ifdef USE_ABSTRACT
const QBrush TableModel::kHeaderForegroundBrush(kHeaderForegroundColor);
const QBrush TableModel::kHeaderBackgroundBrush(kHeaderBackgroundColor);
const QBrush TableModel::kDataBackgroundBrush(kDataBackgroundColor);

TableModel::TableModel(QObject *parent,int aRows)
  : QAbstractTableModel(parent),
    _rows(aRows)
{
}
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
#endif
