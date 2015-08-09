/*
 * MyModel.h
 *
 *  Created on: Aug 8, 2015
 *      Author: Bill
 */

#ifndef MYMODEL_H_
#define MYMODEL_H_

#include <QAbstractTableModel>

class MyModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    MyModel(QObject *parent);
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
};
#endif /* MYMODEL_H_ */
