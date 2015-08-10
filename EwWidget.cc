#include <QHeaderView>
#include <QSize>
#include "EwWidget.hh"

const int EwWidget::kWidth = 400;

EwWidget::EwWidget(QWidget *aParent)
  : QWidget(aParent)
{
  setFixedSize(kWidth,500);
  setContentsMargins(0,0,0,0);
  setStyleSheet("QHeaderView::section { background-color: gray;}");

  TableView *tableView1 = new TableView(this,kWidth,4);
  TableView *tableView2 = new TableView(this,kWidth,5);

  int tTableHeight = tableView1->height();
  tableView2->move(0,tTableHeight);
}

EwWidget::~EwWidget()
{
}

void EwWidget::addContact()
{
  qDebug("addContact");
}

void EwWidget::addClir()
{
  qDebug("addClir");
}
