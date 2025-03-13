#include "datatablemodel.h"
#include "datatablemodel_p.h"

#include <DataGate/dataresponse.h>

namespace DataGate {

DataTableModel::DataTableModel(QObject *parent)
    : Jsoner::TableModel{parent}
    , d_ptr(new DataTableModelPrivate())
{
}

DataTableModel::~DataTableModel() = default;

QString DataTableModel::query() const
{
    return d_ptr->query.string();
}

void DataTableModel::setQuery(const QString &query)
{
    d_ptr->query.setString(query);
}

QVariant DataTableModel::filter(const QString &name) const
{
    return d_ptr->query.filter(name);
}

void DataTableModel::setFilter(const QString &name, const QVariant &value)
{
    d_ptr->query.setFilter(name, value);
}

QVariantHash DataTableModel::filters() const
{
    return d_ptr->query.filters();
}

void DataTableModel::setFilters(const QVariantHash &filters)
{
    d_ptr->query.setFilters(filters);
}

QString DataTableModel::sortField() const
{
    return d_ptr->query.sortField();
}

Qt::SortOrder DataTableModel::sortOrder() const
{
    return d_ptr->query.sortOrder();
}

void DataTableModel::setSort(int column, Qt::SortOrder order)
{
    d_ptr->query.setSort(fieldName(column), order);
}

void DataTableModel::sort(int column, Qt::SortOrder order)
{
    setSort(column, order);
    emit fetchRequested();
}

int DataTableModel::page() const
{
    return d_ptr->query.page();
}

void DataTableModel::setPage(int page)
{
    d_ptr->query.setPage(page);
}

QVariant DataTableModel::parameter(const QString &name) const
{
    return d_ptr->query.parameter(name);
}

void DataTableModel::setParameter(const QString &name, const QVariant &value)
{
    d_ptr->query.setParameter(name, value);
}

QVariantHash DataTableModel::parameters() const
{
    return d_ptr->query.parameters();
}

void DataTableModel::setParameters(const QVariantHash &parameters)
{
    d_ptr->query.setParameters(parameters);
}

AbstractDataController *DataTableModel::controller() const
{
    return d_ptr->controller;
}

void DataTableModel::setController(AbstractDataController *controller)
{
    d_ptr->controller = controller;
}

void DataTableModel::get()
{
    get(d_ptr->query);
}

void DataTableModel::get(const DataQuery &query)
{
    d_ptr->query = query;

    if (!d_ptr->controller || d_ptr->running)
        return;

    d_ptr->running = true;

    d_ptr->controller->fetchManyObjects(query, [this](qint64 current, qint64 total) {
        emit downloadProgress(current, total);
    }, [this](const DataResponse &response) {
        if (response.isSuccess())
            setArray(response.array());
        d_ptr->running = false;
        emit finished(response);
    });
}

} // namespace DataGate
