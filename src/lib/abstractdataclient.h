#ifndef DATAGATE_ABSTRACTDATACLIENT_H
#define DATAGATE_ABSTRACTDATACLIENT_H

#include <DataGate/global.h>
#include <DataGate/datarequest.h>

namespace DataGate {

class DATAGATE_EXPORT AbstractDataClient
{
public:
    virtual ~AbstractDataClient() = default;

    virtual bool hasParameter(const QString &name) const;
    virtual QVariant parameter(const QString &name) const = 0;
    virtual void setParameter(const QString &name, const QVariant &value) = 0;

protected:
    virtual DataRequest newRequest();
};

} // namespace DataGate

#endif // DATAGATE_ABSTRACTDATACLIENT_H
