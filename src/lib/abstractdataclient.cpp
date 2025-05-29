#include "abstractdataclient.h"

#include <QtCore/qvariant.h>

namespace DataGate {

bool AbstractDataClient::hasProperty(const QString &name) const
{
    return property(name).isValid();
}

DataQuery AbstractDataClient::newQuery()
{
    DataQuery query;
    query.setClient(this);
    return query;
}

} // namespace DataGate
