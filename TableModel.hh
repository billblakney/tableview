/*
 * TableModel.h
 *
 *  Created on: Aug 8, 2015
 *      Author: Bill
 */

#ifndef TABLEMODEL_HH_
#define TABLEMODEL_HH_

#include <QAbstractTableModel>

class TableModel: public QAbstractTableModel
{
  Q_OBJECT
public:
  TableModel(QObject *parent);
  int rowCount(const QModelIndex &parent = QModelIndex()) const;
  int columnCount(const QModelIndex &parent = QModelIndex()) const;
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
  QVariant headerData(int section, Qt::Orientation orientation, int role) const;
};
#endif /* TABLEMODEL_HH_ */
