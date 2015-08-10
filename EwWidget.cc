#include <QHeaderView>
#include <QSize>
#include "EwWidget.hh"

const int EwWidget::kWidth = 400;

EwWidget::EwWidget(QWidget *aParent)
  : QWidget(aParent),
    _ContactTable(0),
    _ClirTable(0)
{
  setFixedSize(kWidth,500);
  setContentsMargins(0,0,0,0);
  setStyleSheet("QHeaderView::section { background-color: gray;}");

  _ContactTable = new TableView(this,kWidth,4);
  _ClirTable = new TableView(this,kWidth,5);

  int tTableHeight = _ContactTable->height();
  _ClirTable->move(0,tTableHeight);
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
