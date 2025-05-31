#ifndef DATAGATE_TABLEMODEL_P_H
#define DATAGATE_TABLEMODEL_P_H

#include "tablemodel.h"

#include <DataGate/dataquery.h>

namespace DataGate {

class TableModelPrivate
{
public:
    DataQuery query;
    bool running = false;
    AbstractDataController *controller = AbstractDataController::instance();
};

} // namespace DataGate

#endif // DATAGATE_TABLEMODEL_P_H
