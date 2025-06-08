#include "datarequest.h"

#include <Jsoner/object.h>
#include <Jsoner/array.h>

#include <QtCore/qstring.h>
#include <QtCore/qvariantmap.h>

namespace DataGate {

class DataRequestData : public QSharedData
{
public:
    QString query;
    QVariantMap filters;
    QString sortField;
    Qt::SortOrder sortOrder = Qt::DescendingOrder;
    int page = 1;
    Jsoner::Array array;
    QVariantMap parameters;
    AbstractDataClient *client = nullptr;
};

DataRequest::DataRequest()
    : d_ptr(new DataRequestData())
{
}

DataRequest::DataRequest(const Jsoner::Object &object)
    : d_ptr(new DataRequestData())
{
    d_ptr->array.append(object);
}

DataRequest::DataRequest(const Jsoner::Array &array)
    : d_ptr(new DataRequestData())
{
    d_ptr->array = array;
}

DataRequest::DataRequest(const DataRequest &other) = default;

DataRequest::~DataRequest() = default;

DataRequest &DataRequest::operator=(const DataRequest &other) = default;

bool DataRequest::hasQuery() const
{
    return !d_ptr->query.isEmpty();
}

QString DataRequest::query() const
{
    return d_ptr->query;
}

void DataRequest::setQuery(const QString &str)
{
    d_ptr->query = str;
}

bool DataRequest::hasFilter(const QString &name) const
{
    return d_ptr->filters.contains(name);
}

QVariant DataRequest::filter(const QString &name) const
{
    return d_ptr->filters.value(name);
}

void DataRequest::setFilter(const QString &name, const QVariant &value)
{
    if (value.isValid())
        d_ptr->filters.insert(name, value);
    else if (d_ptr->filters.contains(name))
        d_ptr->filters.remove(name);
}

bool DataRequest::hasFilters() const
{
    return !d_ptr->filters.isEmpty();
}

QVariantMap DataRequest::filters() const
{
    return d_ptr->filters;
}

void DataRequest::setFilters(const QVariantMap &filters)
{
    d_ptr->filters = filters;
}

bool DataRequest::hasSort() const
{
    return !d_ptr->sortField.isEmpty();
}

QString DataRequest::sortField() const
{
    return d_ptr->sortField;
}

Qt::SortOrder DataRequest::sortOrder() const
{
    return d_ptr->sortOrder;
}

void DataRequest::setSort(const QString &field, Qt::SortOrder order)
{
    d_ptr->sortField = field;
    d_ptr->sortOrder = order;
}

int DataRequest::page() const
{
    return d_ptr->page;
}

void DataRequest::setPage(int page)
{
    d_ptr->page = (page > 0 ? page : 1);
}

Jsoner::Object DataRequest::object() const
{
    return (d_ptr->array.isEmpty() ? Jsoner::Object() : Jsoner::Object(d_ptr->array.first()));
}

void DataRequest::setObject(const Jsoner::Object &object)
{
    d_ptr->array = Jsoner::Array({object});
}

Jsoner::Array DataRequest::array() const
{
    return d_ptr->array;
}

void DataRequest::setArray(const Jsoner::Array &array)
{
    d_ptr->array = array;
}

bool DataRequest::hasParameter(const QString &name) const
{
    return d_ptr->parameters.contains(name);
}

QVariant DataRequest::parameter(const QString &name) const
{
    return d_ptr->parameters.value(name);
}

void DataRequest::setParameter(const QString &name, const QVariant &value)
{
    if (value.isValid())
        d_ptr->parameters.insert(name, value);
    else if (d_ptr->parameters.contains(name))
        d_ptr->parameters.remove(name);
}

bool DataRequest::hasParameters() const
{
    return !d_ptr->parameters.isEmpty();
}

QVariantMap DataRequest::parameters() const
{
    return d_ptr->parameters;
}

void DataRequest::setParameters(const QVariantMap &parameters)
{
    d_ptr->parameters = parameters;
}

bool DataRequest::isLinkedToClient() const
{
    return d_ptr->client != nullptr;
}

AbstractDataClient *DataRequest::client() const
{
    return d_ptr->client;
}

void DataRequest::setClient(AbstractDataClient *client)
{
    d_ptr->client = client;
}

} // namespace DataGate
