#include "abstractdataclient.h"

#include <QtCore/qvariant.h>

namespace DataGate {

bool AbstractDataClient::hasParameter(const QString &name) const
{
    return parameter(name).isValid();
}

void AbstractDataClient::setParameter(const QString &name, const QVariant &value)
{
    Q_UNUSED(name)
    Q_UNUSED(value)
}

DataRequest AbstractDataClient::newRequest()
{
    DataRequest request;
    request.setClient(this);
    return request;
}

} // namespace DataGate
