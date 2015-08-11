#ifndef EWWIDGET_HH_
#define EWWIDGET_HH_

#include <QWidget>
#include <QTableView>
#include "TableView.hh"

class EwWidget : public QWidget
{
  Q_OBJECT
public:
  static const int kWidth;
  static const int kHeight;

  EwWidget(QWidget *aParent);
  virtual ~EwWidget();
  void updateSize();
  void moveClirTable();

public slots:
  void addContact();
  void removeContact();
  void addClir();
  void removeClir();

private:
  TableView *_ContactTable;
  TableView *_ClirTable;
};

#endif /* EWWIDGET_HH_ */
