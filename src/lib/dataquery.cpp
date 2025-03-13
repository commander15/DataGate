#include "dataquery.h"

#include <Jsoner/object.h>
#include <Jsoner/array.h>

#include <QtCore/qstring.h>
#include <QtCore/qvarianthash.h>

namespace DataGate {

class DataQueryData : public QSharedData
{
public:
    QString query;
    QVariantHash filters;
    QString sortField;
    Qt::SortOrder sortOrder = Qt::DescendingOrder;
    int page = 1;
    Jsoner::Array array;
    QVariantHash parameters;
};

DataQuery::DataQuery()
    : d_ptr(new DataQueryData)
{
}

DataQuery::DataQuery(const Jsoner::Object &object)
    : d_ptr(new DataQueryData)
{
    d_ptr->array.append(object);
}

DataQuery::DataQuery(const Jsoner::Array &objects)
    : d_ptr(new DataQueryData)
{
    d_ptr->array = objects;
}

DataQuery::DataQuery(const DataQuery &other) = default;

DataQuery::~DataQuery() = default;

DataQuery &DataQuery::operator=(const DataQuery &other) = default;

QString DataQuery::string() const {
    return d_ptr->query;
}

void DataQuery::setString(const QString &query)
{
    d_ptr->query = query;
}

QVariant DataQuery::filter(const QString &name) const
{
    return d_ptr->filters.value(name);
}

void DataQuery::setFilter(const QString &name, const QVariant &value)
{
    d_ptr->filters.insert(name, value);
}

QVariantHash DataQuery::filters() const {
    return d_ptr->filters;
}

void DataQuery::setFilters(const QVariantHash &filters)
{
    d_ptr->filters = filters;
}

QString DataQuery::sortField() const
{
    return d_ptr->sortField;
}

Qt::SortOrder DataQuery::sortOrder() const
{
    return d_ptr->sortOrder;
}

void DataQuery::setSort(const QString &field, Qt::SortOrder order)
{
    d_ptr->sortField = field;
    d_ptr->sortOrder = order;
}

QVariantHash DataQuery::parameters() const
{
    return d_ptr->parameters;
}

void DataQuery::setParameters(const QVariantHash &parameters)
{
    d_ptr->parameters = parameters;
}

int DataQuery::page() const
{
    return d_ptr->page;
}

void DataQuery::setPage(int page)
{
    d_ptr->page = page;
}

Jsoner::Object DataQuery::object() const
{
    return (!d_ptr->array.isEmpty() ? Jsoner::Object(d_ptr->array.first()) : Jsoner::Object());
}

void DataQuery::setObject(const Jsoner::Object &object)
{
    d_ptr->array = Jsoner::Array({object});
}

Jsoner::Array DataQuery::array() const
{
    return d_ptr->array;
}

void DataQuery::setArray(const Jsoner::Array &array)
{
    d_ptr->array = array;
}

QVariant DataQuery::parameter(const QString &name) const
{
    return d_ptr->parameters.value(name);
}

void DataQuery::setParameter(const QString &name, const QVariant &value)
{
    d_ptr->parameters.insert(name, value);
}

} // namespace DataGate
