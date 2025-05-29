#include "abstractdataclient.h"

#include <QtCore/qvariant.h>

namespace DataGate {

bool AbstractDataClient::hasParameter(const QString &name) const
{
    return parameter(name).isValid();
}

DataQuery AbstractDataClient::newQuery()
{
    DataQuery query;
    query.setClient(this);
    return query;
}

} // namespace DataGate
