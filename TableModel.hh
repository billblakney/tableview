/*
 * TableModel.h
 *
 *  Created on: Aug 8, 2015
 *      Author: Bill
 */

#ifndef TABLEMODEL_HH_
#define TABLEMODEL_HH_

#define USE_ABSTRACT

#ifdef USE_ABSTRACT
#include <QAbstractTableModel>
#else
#include <QStandardItemModel>
#endif

#ifdef USE_ABSTRACT
class TableModel: public QAbstractTableModel
#else
class TableModel: public QStandardItemModel
#endif
{
  Q_OBJECT
public:
  static const int kColumns;

  static const int kColCD;
  static const int kColLPI;
  static const int kColTOE;
  static const int kColBNG;
  static const int kColFRQ;
  static const int kColPRF;
  static const int kColAMP;
  static const int kColPW;

  TableModel(QObject *parent,int aRows);
#ifdef USE_ABSTRACT
  int rowCount(const QModelIndex &parent = QModelIndex()) const;
  int columnCount(const QModelIndex &parent = QModelIndex()) const;
  QString getCellValue(int aRow,int aCol) const;
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
  QVariant headerData(int section, Qt::Orientation orientation, int role) const;
#else
#endif

private:
#ifdef USE_ABSTRACT
  int _rows;
#else
#endif
};

#endif /* TABLEMODEL_HH_ */
