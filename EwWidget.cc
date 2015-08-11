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
  _ClirTable = new TableView(this,kWidth,5);

  updateSize();

  moveClirTable();
}

EwWidget::~EwWidget()
{
}

void EwWidget::updateSize()
{
  int tTablesHeight = _ContactTable->height() + _ClirTable->height();
std::cout << "_Contact,_Clir,ttl: "
          << _ContactTable->height() << ","
          << _ClirTable->height() << ","
          << tTablesHeight << std::endl;
  int tHeight = (tTablesHeight < kHeight ? kHeight : tTablesHeight);
  resize(kWidth,tHeight);
std::cout << "EW resize(w,h): " << kWidth << "," << tHeight << std::endl;
QSize tSize = size();
//qDebug("size(w,h): " << tSize.width() << "," << tSize.height());
std::cout << "EW size(w,h): " << tSize.width() << "," << tSize.height() << std::endl;
//  setFixedSize(kWidth,tHeight);
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
  updateSize();
  moveClirTable();
}

void EwWidget::removeContact()
{
  qDebug("removeContact");
  _ContactTable->removeRow();
  updateSize();
  moveClirTable();
}

void EwWidget::addClir()
{
  qDebug("addClir");
  _ClirTable->addRow();
  updateSize();//TODO
}

void EwWidget::removeClir()
{
  qDebug("removeClir");
  _ClirTable->removeRow();
  updateSize();//TODO
}
