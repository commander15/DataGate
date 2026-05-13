#ifndef JSONDATAMANAGER_H
#define JSONDATAMANAGER_H

#include <DataGate/global.h>
#include <DataGate/abstractdatamanager.h>

#include <QtCore/qscopedpointer.h>

namespace Jsoner {
class Object;
class Array;
}

namespace DataGate {

class JsonDataManagerPrivate;
class DATAGATE_EXPORT JsonDataManager : public DataGate::AbstractDataManager
{
public:
    explicit JsonDataManager();
    virtual ~JsonDataManager();

    bool hasFeature(Feature feature, AbstractDataClient *client) const override;
    void setFeature(Feature feature, bool on = true);

    QString idField() const;
    void setIdField(const QString &field);

    Jsoner::Array data() const;
    void setData(const Jsoner::Array &data);
    void clear();

    int objectIndex(int id) const;
    int objectIndex(const Jsoner::Object &object) const;

protected:
    void fetchSomeSearchSuggestions(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse) override;
    void fetchManyObjects(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse) override;
    void fetchOneObject(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse) override;
    void addOneObject(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse) override;
    void editOneObject(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse) override;
    void deleteOneObject(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse) override;
    void deleteManyObjects(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse) override;

    int objectIndex(const DataRequest &request) const;

    int generateId();

private:
    QScopedPointer<JsonDataManagerPrivate> d_ptr;
};

} // namespace DataGate

#endif // JSONDATAMANAGER_H
