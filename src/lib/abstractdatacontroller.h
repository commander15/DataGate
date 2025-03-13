#ifndef DATAGATE_ABSTRACTDATACONTROLLER_H
#define DATAGATE_ABSTRACTDATACONTROLLER_H

#include <DataGate/global.h>

#include <functional>

namespace DataGate {

class DataQuery;
class DataResponse;

typedef std::function<void(qint64, qint64)> DataQueryProgressCallback;
typedef std::function<void(const DataResponse &response)> DataQueryResponseCallback;

class DATAGATE_EXPORT AbstractDataController
{
public:
    explicit AbstractDataController();
    virtual ~AbstractDataController();

    void fetchSearchSuggestions(const DataQuery &query, const DataQueryResponseCallback &onResponse);
    void fetchSearchSuggestions(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse);

    void fetchObjects(const DataQuery &query, const DataQueryResponseCallback &onResponse);
    void fetchObjects(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse);

    void fetchObject(const DataQuery &query, int targetRequestType, const DataQueryResponseCallback &onResponse);
    void fetchObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse);

    void addObject(const DataQuery &query, const DataQueryResponseCallback &onResponse);
    void addObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse);

    void editObject(const DataQuery &query, const DataQueryResponseCallback &onResponse);
    void editObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse);

    void deleteObjects(const DataQuery &query, const DataQueryResponseCallback &onResponse);
    void deleteObjects(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse);

    virtual void fetchSomeSearchSuggestions(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse);
    virtual void fetchManyObjects(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse) = 0;
    virtual void fetchOneObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse) = 0;
    virtual void addOneObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse) = 0;
    virtual void editOneObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse) = 0;
    virtual void deleteManyObjects(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse) = 0;

    static AbstractDataController *instance();

private:
    static AbstractDataController *s_instance;
};

} // namespace DataGate

#endif // DATAGATE_ABSTRACTDATACONTROLLER_H
