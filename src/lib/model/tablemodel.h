#ifndef DATAGATE_TABLEMODEL_H
#define DATAGATE_TABLEMODEL_H

#include <DataGate/global.h>
#include <DataGate/abstractdatamanager.h>

#include <Jsoner/tablemodel.h>

namespace DataGate {

class DataRequest;

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

    QVariantMap filters() const;
    void setFilters(const QVariantMap &filters);

    QString sortField() const;
    Qt::SortOrder sortOrder() const;
    void setSort(int column, Qt::SortOrder order);
    void sort(int column, Qt::SortOrder order) override;

    int page() const;
    void setPage(int page);

    QVariant parameter(const QString &name) const;
    void setParameter(const QString &name, const QVariant &value);

    QVariantMap parameters() const;
    void setParameters(const QVariantMap &parameters);

    DataRequest request() const;

    AbstractDataManager *manager() const;
    void setManager(AbstractDataManager *controller);

public slots:
    void get();
    void get(const DataGate::DataRequest &request);

signals:
    void fetchRequested();
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void finished(const DataGate::DataResponse &response);

private:
    QScopedPointer<TableModelPrivate> d_ptr;
};

} // namespace DataGate

#endif // DATAGATE_TABLEMODEL_H
