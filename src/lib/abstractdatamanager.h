#ifndef DATAGATE_ABSTRACTDATAMANAGER_H
#define DATAGATE_ABSTRACTDATAMANAGER_H

#include <DataGate/global.h>

#include <functional>

namespace DataGate {

class AbstractDataClient;
class DataQuery;
class DataResponse;

typedef std::function<void(qint64, qint64)> DataQueryProgressCallback;
typedef std::function<void(const DataResponse &response)> DataQueryResponseCallback;

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

    void fetchSearchSuggestions(const DataQuery &query, const DataQueryResponseCallback &onResponse);
    void fetchSearchSuggestions(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse);

    void fetchObjects(const DataQuery &query, const DataQueryResponseCallback &onResponse);
    void fetchObjects(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse);

    void fetchObject(const DataQuery &query, const DataQueryResponseCallback &onResponse);
    void fetchObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse);

    void addObject(const DataQuery &query, const DataQueryResponseCallback &onResponse);
    void addObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse);

    void editObject(const DataQuery &query, const DataQueryResponseCallback &onResponse);
    void editObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse);

    void deleteObject(const DataQuery &query, const DataQueryResponseCallback &onResponse);
    void deleteObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse);

    void deleteObjects(const DataQuery &query, const DataQueryResponseCallback &onResponse);
    void deleteObjects(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse);

protected:
    virtual void fetchSomeSearchSuggestions(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse) = 0;
    virtual void fetchManyObjects(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse) = 0;
    virtual void fetchOneObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse) = 0;
    virtual void addOneObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse) = 0;
    virtual void editOneObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse) = 0;
    virtual void deleteOneObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse) = 0;
    virtual void deleteManyObjects(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse) = 0;
};

} // namespace DataGate

#endif // DATAGATE_ABSTRACTDATAMANAGER_H
