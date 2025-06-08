#ifndef DATAGATE_TABLEMODEL_P_H
#define DATAGATE_TABLEMODEL_P_H

#include "tablemodel.h"

#include <DataGate/datarequest.h>

namespace DataGate {

class TableModelPrivate
{
public:
    DataRequest request;
    bool running = false;
    AbstractDataManager *manager = nullptr;
};

} // namespace DataGate

#endif // DATAGATE_TABLEMODEL_P_H
