#ifndef DATAGATE_DATAMANAGER_H
#define DATAGATE_DATAMANAGER_H

#include <DataGate/global.h>
#include <DataGate/abstractdatamanager.h>

namespace DataGate {

class DATAGATE_EXPORT DataManager : public AbstractDataManager
{
public:
    virtual ~DataManager() = default;

    bool hasFeature(Feature feature, AbstractDataClient *client) const override;

protected:
    void fetchSomeSearchSuggestions(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse) override;
    void fetchManyObjects(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse) override;
    void fetchOneObject(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse) override;
    void addOneObject(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse) override;
    void editOneObject(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse) override;
    void deleteOneObject(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse) override;
    void deleteManyObjects(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse) override;
};

} // namespace DataGate

#endif // DATAGATE_DATAMANAGER_H
