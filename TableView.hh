#ifndef TABLEVIEW_HH_
#define TABLEVIEW_HH_

#include "TableModel.hh"
#include <QTableView>

class TableView : public QTableView
{
  Q_OBJECT
public:
  static const int kColWidthCD;
  static const int kColWidthLPI;
  static const int kColWidthTOE;
  static const int kColWidthBNG;
  static const int kColWidthFRQ;
  static const int kColWidthPRF;
  static const int kColWidthAMP;
  static const int kColWidthPW;

  TableView(QWidget *aParent,int width,int aRows);
  virtual ~TableView();
  void setColumnWidths();
  int getComputedHeight();
private:
  TableModel *_TableModel;
  int        _Width;
};

#endif /* TABLEVIEW_HH_ */
