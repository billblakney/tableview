/*
 * TableView.cc
 *
 *  Created on: Aug 9, 2015
 *      Author: Bill
 */

#include "TableView.hh"
#include "TableModel.hh"

#include <QHeaderView>
#include <QLayout>

const int TableView::kColWidthCD = 43;
const int TableView::kColWidthLPI = 24;
const int TableView::kColWidthTOE = 67 + 1;
const int TableView::kColWidthBNG = 43;
const int TableView::kColWidthFRQ = 58;
const int TableView::kColWidthPRF = 60;
const int TableView::kColWidthAMP = 49;
const int TableView::kColWidthPW = 42;

TableView::TableView(QWidget *aParent,int aWidth,int aRows)
  : QTableView(aParent),
    _Width(aWidth)
{

  _TableModel = new TableModel(0,aRows);
  setModel(_TableModel);

  verticalHeader()->hide();

  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  setColumnWidths();
  updateHeight();
}

TableView::~TableView()
{
}

void TableView::updateHeight()
{
  int tHeight = getComputedHeight();
  QSize tSize(_Width,tHeight);

  setFixedSize(tSize);
}

void TableView::setColumnWidths()
{
  setColumnWidth(TableModel::kColCD,kColWidthCD);
  setColumnWidth(TableModel::kColLPI,kColWidthLPI);
  setColumnWidth(TableModel::kColTOE,kColWidthTOE);
  setColumnWidth(TableModel::kColBNG,kColWidthBNG);
  setColumnWidth(TableModel::kColFRQ,kColWidthFRQ);
  setColumnWidth(TableModel::kColPRF,kColWidthPRF);
  setColumnWidth(TableModel::kColAMP,kColWidthAMP);
  setColumnWidth(TableModel::kColPW,kColWidthPW);
}

void TableView::addRow()
{
  _TableModel->addRow();
  updateHeight();
}

int TableView::getComputedHeight()
{
  int tRowHeight = rowHeight(0);
  int tHeaderHeight = horizontalHeader()->height();
  int tHeight = tHeaderHeight + _TableModel->rowCount() * tRowHeight;

  return tHeight;
}
