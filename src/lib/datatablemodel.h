#ifndef DATAGATE_DATATABLEMODEL_H
#define DATAGATE_DATATABLEMODEL_H

#include <DataGate/global.h>
#include <DataGate/abstractdatacontroller.h>

#include <Jsoner/tablemodel.h>

namespace DataGate {

class DataQuery;

class DataTableModelPrivate;
class DATAGATE_EXPORT DataTableModel : public Jsoner::TableModel
{
    Q_OBJECT

public:
    explicit DataTableModel(QObject *parent = nullptr);
    virtual ~DataTableModel();

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

    AbstractDataController *controller() const;
    void setController(AbstractDataController *controller);

public slots:
    void get();
    void get(const DataQuery &query);

signals:
    void fetchRequested();
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void finished(const DataResponse &response);

private:
    QScopedPointer<DataTableModelPrivate> d_ptr;
};

} // namespace DataGate

#endif // DATAGATE_DATATABLEMODEL_H
