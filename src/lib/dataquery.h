#ifndef DATAGATE_DATAQUERY_H
#define DATAGATE_DATAQUERY_H

#include <DataGate/global.h>

#include <QtCore/qshareddata.h>

namespace Jsoner {
class Object;
class Array;
}

namespace DataGate {

class AbstractDataClient;

class DataQueryData;
class DATAGATE_EXPORT DataQuery {
public:
    DataQuery();
    DataQuery(const Jsoner::Object &object);
    DataQuery(const Jsoner::Array &array);
    DataQuery(const DataQuery &other);
    ~DataQuery();

    DataQuery &operator=(const DataQuery &other);

    QString string() const;
    void setString(const QString &query);

    QVariant filter(const QString &name) const;
    void setFilter(const QString &name, const QVariant &value);

    QVariantHash filters() const;
    void setFilters(const QVariantHash &filters);

    QString sortField() const;
    Qt::SortOrder sortOrder() const;
    void setSort(const QString &field, Qt::SortOrder order);

    int page() const;
    void setPage(int page);

    Jsoner::Object object() const;
    void setObject(const Jsoner::Object &object);

    Jsoner::Array array() const;
    void setArray(const Jsoner::Array &array);

    QVariant parameter(const QString &name) const;
    void setParameter(const QString &name, const QVariant &value);

    QVariantHash parameters() const;
    void setParameters(const QVariantHash &parameters);

    AbstractDataClient *client() const;
    void setClient(AbstractDataClient *client);

private:
    QSharedDataPointer<DataQueryData> d_ptr;
};

} // namespace DataGate

#endif // DATAGATE_DATAQUERY_H
