#ifndef DATAGATE_DATATABLEMODEL_P_H
#define DATAGATE_DATATABLEMODEL_P_H

#include "datatablemodel.h"

#include <DataGate/dataquery.h>

namespace DataGate {

class DataTableModelPrivate
{
public:
    QString sortField;
    Qt::SortOrder sortOrder = Qt::DescendingOrder;

    DataQuery query;
    bool running = false;
    AbstractDataController *controller = AbstractDataController::instance();
};

} // namespace DataGate

#endif // DATAGATE_DATATABLEMODEL_P_H
