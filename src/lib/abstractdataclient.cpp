#include "abstractdataclient.h"

#include <QtCore/qvariant.h>

namespace DataGate {

bool AbstractDataClient::hasParameter(const QString &name) const
{
    return parameter(name).isValid();
}

DataRequest AbstractDataClient::newRequest()
{
    DataRequest request;
    request.setClient(this);
    return request;
}

} // namespace DataGate
