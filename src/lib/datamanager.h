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
    void fetchSomeSearchSuggestions(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse) override;
    void fetchManyObjects(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse) override;
    void fetchOneObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse) override;
    void addOneObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse) override;
    void editOneObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse) override;
    void deleteOneObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse) override;
    void deleteManyObjects(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse) override;
};

} // namespace DataGate

#endif // DATAGATE_DATAMANAGER_H
