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

  moveClirTable();

}

EwWidget::~EwWidget()
{
}

void EwWidget::moveClirTable()
{
  int tTableHeight = _ContactTable->height();
  _ClirTable->move(0,tTableHeight);
}

void EwWidget::addContact()
{
  qDebug("addContact");
  _ContactTable->addRow();
  moveClirTable();
}

void EwWidget::removeContact()
{
  qDebug("removeContact");
  _ContactTable->removeRow();
  moveClirTable();
}

void EwWidget::addClir()
{
  qDebug("addClir");
  _ClirTable->addRow();
}

void EwWidget::removeClir()
{
  qDebug("removeClir");
  _ClirTable->removeRow();
}
