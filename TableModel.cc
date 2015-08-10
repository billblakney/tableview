#include <iostream>
#include <QBrush>
#include <QFont>
#include "TableModel.hh"

TableModel::TableModel(QObject *parent) :
    QAbstractTableModel(parent)
{
}

int TableModel::rowCount(const QModelIndex & /*parent*/) const
{
  return 20;
}

int TableModel::columnCount(const QModelIndex & /*parent*/) const
{
  return 3;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
  int row = index.row();
  int col = index.column();

  switch (role)
  {
  case Qt::DisplayRole:
    return QString("Row%1, Column%2").arg(index.row() + 1).arg(
        index.column() + 1);
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
        return QString("first");
      case 1:
        return QString("second");
      case 2:
        return QString("third");
      }
    }
    break;
  case Qt::ForegroundRole:
  {
    QBrush foreground(Qt::white);
    return foreground;
    break;
  }
  }
  return QVariant();
}
