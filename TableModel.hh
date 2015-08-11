#ifndef TABLEMODEL_HH_
#define TABLEMODEL_HH_

//#define USE_ABSTRACT

#ifdef USE_ABSTRACT
#include <QAbstractTableModel>
#endif
#include <QBrush>
#include <QStandardItemModel>

#ifdef USE_ABSTRACT
class TableModel: public QAbstractTableModel
#endif
class TableModel: public QStandardItemModel
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

  static const QColor kHeaderForegroundColor;
  static const QColor kHeaderBackgroundColor;
  static const QColor kDataBackgroundColor;
  static const QColor kDataForegroundColor;

  static QFont kHeaderFont;
  static QFont kDataFont;

  TableModel(QObject *parent,int aRows);
#ifdef USE_ABSTRACT
  int rowCount(const QModelIndex &parent = QModelIndex()) const;
  int columnCount(const QModelIndex &parent = QModelIndex()) const;
  QString getCellValue(int aRow,int aCol) const;
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
  QVariant headerData(int section, Qt::Orientation orientation, int role) const;
#endif
  void setupHorizontalHeader();

  void addRow();
  void removeRow();

private:
#ifdef USE_ABSTRACT
  static const QBrush kHeaderForegroundBrush;
  static const QBrush kHeaderBackgroundBrush;
  static const QBrush kDataBackgroundBrush;
  static const QBrush kDataForegroundBrush;

  int _rows;
#endif
};

#endif /* TABLEMODEL_HH_ */
