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
    return d_ptr->request.query();
}

void TableModel::setQuery(const QString &query)
{
    d_ptr->request.setQuery(query);
}

QVariant TableModel::filter(const QString &name) const
{
    return d_ptr->request.filter(name);
}

void TableModel::setFilter(const QString &name, const QVariant &value)
{
    d_ptr->request.setFilter(name, value);
}

QVariantMap TableModel::filters() const
{
    return d_ptr->request.filters();
}

void TableModel::setFilters(const QVariantMap &filters)
{
    d_ptr->request.setFilters(filters);
}

QString TableModel::sortField() const
{
    return d_ptr->request.sortField();
}

Qt::SortOrder TableModel::sortOrder() const
{
    return d_ptr->request.sortOrder();
}

void TableModel::setSort(int column, Qt::SortOrder order)
{
    d_ptr->request.setSort(fieldName(column), order);
}

void TableModel::sort(int column, Qt::SortOrder order)
{
    setSort(column, order);
    emit fetchRequested();
}

int TableModel::page() const
{
    return d_ptr->request.page();
}

void TableModel::setPage(int page)
{
    d_ptr->request.setPage(page);
}

QVariant TableModel::parameter(const QString &name) const
{
    return d_ptr->request.parameter(name);
}

void TableModel::setParameter(const QString &name, const QVariant &value)
{
    d_ptr->request.setParameter(name, value);
}

QVariantMap TableModel::parameters() const
{
    return d_ptr->request.parameters();
}

void TableModel::setParameters(const QVariantMap &parameters)
{
    d_ptr->request.setParameters(parameters);
}

DataRequest TableModel::request() const
{
    return d_ptr->request;
}

AbstractDataManager *TableModel::manager() const
{
    return d_ptr->manager;
}

void TableModel::setManager(AbstractDataManager *controller)
{
    d_ptr->manager = controller;
}

void TableModel::get()
{
    get(d_ptr->request);
}

void TableModel::get(const DataRequest &request)
{
    d_ptr->request = request;

    if (!d_ptr->manager || d_ptr->running)
        return;

    d_ptr->running = true;

    d_ptr->manager->fetchObjects(request, [this](qint64 current, qint64 total) {
        emit downloadProgress(current, total);
    }, [this](const DataResponse &response) {
        if (response.isSuccess())
            setArray(response.array());
        d_ptr->running = false;
        emit finished(response);
    });
}

} // namespace DataGate
