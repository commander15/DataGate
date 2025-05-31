#ifndef DATAGATE_TABLEMODEL_H
#define DATAGATE_TABLEMODEL_H

#include <DataGate/global.h>
#include <DataGate/abstractdatacontroller.h>

#include <Jsoner/tablemodel.h>

namespace DataGate {

class DataQuery;

class TableModelPrivate;
class DATAGATE_EXPORT TableModel : public Jsoner::TableModel
{
    Q_OBJECT

public:
    explicit TableModel(QObject *parent = nullptr);
    virtual ~TableModel();

    QString query() const;
    void setQuery(const QString &query);

    QVariant filter(const QString &name) const;
    void setFilter(const QString &name, const QVariant &value);

    QVariantHash filters() const;
    void setFilters(const QVariantHash &filters);

    QString sortField() const;
    Qt::SortOrder sortOrder() const;
    void setSort(int column, Qt::SortOrder order);
    void sort(int column, Qt::SortOrder order) override;

    int page() const;
    void setPage(int page);

    QVariant parameter(const QString &name) const;
    void setParameter(const QString &name, const QVariant &value);

    QVariantHash parameters() const;
    void setParameters(const QVariantHash &parameters);

    DataQuery dataQuery() const;

    AbstractDataController *controller() const;
    void setController(AbstractDataController *controller);

public slots:
    void get();
    void get(const DataGate::DataQuery &query);

signals:
    void fetchRequested();
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void finished(const DataGate::DataResponse &response);

private:
    QScopedPointer<TableModelPrivate> d_ptr;
};

} // namespace DataGate

#endif // DATAGATE_TABLEMODEL_H
