#ifndef DATAGATE_ABSTRACTDATAMANAGER_H
#define DATAGATE_ABSTRACTDATAMANAGER_H

#include <DataGate/global.h>

namespace DataGate {

class AbstractDataClient;
class DataRequest;
class DataResponse;

class DATAGATE_EXPORT AbstractDataManager
{
public:
    enum Feature {
        SearchByKeywords,
        SearchByFilters,
        SearchSuggestions,
        ResultsSorting,
        ResultsPagination,
        ObjectFetch,
        ObjectAdd,
        ObjectEdit,
        ObjectDelete,
    };

    virtual ~AbstractDataManager() = default;

    virtual bool hasFeature(Feature feature, AbstractDataClient *client) const = 0;

    void fetchSearchSuggestions(const DataRequest &request, const DataResponseCallback &onResponse);
    void fetchSearchSuggestions(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse);

    void fetchObjects(const DataRequest &request, const DataResponseCallback &onResponse);
    void fetchObjects(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse);

    void fetchObject(const DataRequest &request, const DataResponseCallback &onResponse);
    void fetchObject(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse);

    void addObject(const DataRequest &request, const DataResponseCallback &onResponse);
    void addObject(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse);

    void editObject(const DataRequest &request, const DataResponseCallback &onResponse);
    void editObject(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse);

    void deleteObject(const DataRequest &request, const DataResponseCallback &onResponse);
    void deleteObject(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse);

    void deleteObjects(const DataRequest &request, const DataResponseCallback &onResponse);
    void deleteObjects(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse);

protected:
    virtual void fetchSomeSearchSuggestions(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse) = 0;
    virtual void fetchManyObjects(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse) = 0;
    virtual void fetchOneObject(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse) = 0;
    virtual void addOneObject(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse) = 0;
    virtual void editOneObject(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse) = 0;
    virtual void deleteOneObject(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse) = 0;
    virtual void deleteManyObjects(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse) = 0;
};

} // namespace DataGate

#endif // DATAGATE_ABSTRACTDATAMANAGER_H
