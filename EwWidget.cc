#include <iostream>
#include <QHeaderView>
#include <QSize>
#include "EwWidget.hh"

const int EwWidget::kWidth = 400;
const int EwWidget::kHeight = 500;

EwWidget::EwWidget(QWidget *aParent)
  : QWidget(aParent),
    _ContactTable(0),
    _ClirTable(0)
{
//  setFixedSize(kWidth,kHeight);
  setMinimumSize(kWidth,kHeight);
  setContentsMargins(0,0,0,0);
  setStyleSheet("QHeaderView::section { background-color: gray;}");

  _ContactTable = new TableView(this,kWidth,4);
  _ContactTable->hideColumn(2);
  _ClirTable = new TableView(this,kWidth,5);
  _ClirTable->hideColumn(0);
  _ClirTable->hideColumn(1);

  updateSize();

  moveClirTable();
}

EwWidget::~EwWidget()
{
}

void EwWidget::updateSize()
{
  int tTablesHeight = _ContactTable->height() + _ClirTable->height();
  int tHeight = (tTablesHeight < kHeight ? kHeight : tTablesHeight);
  resize(kWidth,tHeight);
}

void EwWidget::moveClirTable()
{
  int tTableHeight = _ContactTable->height();
  _ClirTable->move(0,tTableHeight);
}

void EwWidget::addContact()
{
  _ContactTable->addRow();
  updateSize();
  moveClirTable();
}

void EwWidget::removeContact()
{
  _ContactTable->removeRow();
  updateSize();
  moveClirTable();
}

void EwWidget::addClir()
{
  _ClirTable->addRow();
  updateSize();
}

void EwWidget::removeClir()
{
  _ClirTable->removeRow();
  updateSize();
}
