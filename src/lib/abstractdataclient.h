#ifndef DATAGATE_ABSTRACTDATACLIENT_H
#define DATAGATE_ABSTRACTDATACLIENT_H

#include <DataGate/global.h>
#include <DataGate/dataquery.h>

namespace DataGate {

class DATAGATE_EXPORT AbstractDataClient
{
public:
    virtual ~AbstractDataClient() = default;

    virtual bool hasProperty(const QString &name) const;
    virtual QVariant property(const QString &name) const = 0;
    virtual void setProperty(const QString &name, const QVariant &value) const = 0;

protected:
    virtual DataQuery newQuery();
};

} // namespace DataGate

#endif // DATAGATE_ABSTRACTDATACLIENT_H
