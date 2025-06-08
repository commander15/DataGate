#ifndef DATAGATE_DATAREQUEST_H
#define DATAGATE_DATAREQUEST_H

#include <DataGate/global.h>

#include <QtCore/qshareddata.h>

namespace Jsoner {
class Object;
class Array;
}

namespace DataGate {

class AbstractDataClient;

class DataRequestData;
class DATAGATE_EXPORT DataRequest {
public:
    DataRequest();
    DataRequest(const Jsoner::Object &object);
    DataRequest(const Jsoner::Array &array);
    DataRequest(const DataRequest &other);
    ~DataRequest();

    DataRequest &operator=(const DataRequest &other);

    bool hasQuery() const;
    QString query() const;
    void setQuery(const QString &str);

    bool hasFilter(const QString &name) const;
    QVariant filter(const QString &name) const;
    void setFilter(const QString &name, const QVariant &value);

    bool hasFilters() const;
    QVariantMap filters() const;
    void setFilters(const QVariantMap &filters);

    bool hasSort() const;
    QString sortField() const;
    Qt::SortOrder sortOrder() const;
    void setSort(const QString &field, Qt::SortOrder order);

    int page() const;
    void setPage(int page);

    Jsoner::Object object() const;
    void setObject(const Jsoner::Object &object);

    Jsoner::Array array() const;
    void setArray(const Jsoner::Array &array);

    bool hasParameter(const QString &name) const;
    QVariant parameter(const QString &name) const;
    void setParameter(const QString &name, const QVariant &value);

    bool hasParameters() const;
    QVariantMap parameters() const;
    void setParameters(const QVariantMap &parameters);

    bool isLinkedToClient() const;
    AbstractDataClient *client() const;
    void setClient(AbstractDataClient *client);

private:
    QSharedDataPointer<DataRequestData> d_ptr;
};

} // namespace DataGate

#endif // DATAGATE_DATAREQUEST_H
