#include "tablemodel.h"
#include "tablemodel_p.h"

#include <DataGate/dataresponse.h>

namespace DataGate {

TableModel::TableModel(QObject *parent)
    : Jsoner::TableModel{parent}
    , d_ptr(new TableModelPrivate())
{
}

TableModel::~TableModel() = default;

QString TableModel::query() const
{
    return d_ptr->query.string();
}

void TableModel::setQuery(const QString &query)
{
    d_ptr->query.setString(query);
}

QVariant TableModel::filter(const QString &name) const
{
    return d_ptr->query.filter(name);
}

void TableModel::setFilter(const QString &name, const QVariant &value)
{
    d_ptr->query.setFilter(name, value);
}

QVariantHash TableModel::filters() const
{
    return d_ptr->query.filters();
}

void TableModel::setFilters(const QVariantHash &filters)
{
    d_ptr->query.setFilters(filters);
}

QString TableModel::sortField() const
{
    return d_ptr->query.sortField();
}

Qt::SortOrder TableModel::sortOrder() const
{
    return d_ptr->query.sortOrder();
}

void TableModel::setSort(int column, Qt::SortOrder order)
{
    d_ptr->query.setSort(fieldName(column), order);
}

void TableModel::sort(int column, Qt::SortOrder order)
{
    setSort(column, order);
    emit fetchRequested();
}

int TableModel::page() const
{
    return d_ptr->query.page();
}

void TableModel::setPage(int page)
{
    d_ptr->query.setPage(page);
}

QVariant TableModel::parameter(const QString &name) const
{
    return d_ptr->query.parameter(name);
}

void TableModel::setParameter(const QString &name, const QVariant &value)
{
    d_ptr->query.setParameter(name, value);
}

QVariantHash TableModel::parameters() const
{
    return d_ptr->query.parameters();
}

void TableModel::setParameters(const QVariantHash &parameters)
{
    d_ptr->query.setParameters(parameters);
}

AbstractDataController *TableModel::controller() const
{
    return d_ptr->controller;
}

void TableModel::setController(AbstractDataController *controller)
{
    d_ptr->controller = controller;
}

void TableModel::get()
{
    get(d_ptr->query);
}

void TableModel::get(const DataQuery &query)
{
    d_ptr->query = query;

    if (!d_ptr->controller || d_ptr->running)
        return;

    d_ptr->running = true;

    d_ptr->controller->fetchObjects(query, [this](qint64 current, qint64 total) {
        emit downloadProgress(current, total);
    }, [this](const DataResponse &response) {
        if (response.isSuccess())
            setArray(response.array());
        d_ptr->running = false;
        emit finished(response);
    });
}

} // namespace DataGate
