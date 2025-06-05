#include "datamanager.h"

#include <DataGate/dataresponse.h>

namespace DataGate {

bool DataManager::hasFeature(Feature feature, AbstractDataClient *client) const
{
    Q_UNUSED(feature);
    return client != nullptr;
}

void DataManager::fetchSomeSearchSuggestions(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse)
{
    Q_UNUSED(query);
    Q_UNUSED(onProgress);
    onResponse(DataResponse());
}

void DataManager::fetchManyObjects(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse)
{
    Q_UNUSED(query);
    Q_UNUSED(onProgress);
    onResponse(DataResponse());
}

void DataManager::fetchOneObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse)
{
    Q_UNUSED(query);
    Q_UNUSED(onProgress);
    onResponse(DataResponse());
}

void DataManager::addOneObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse)
{
    Q_UNUSED(query);
    Q_UNUSED(onProgress);
    onResponse(DataResponse());
}

void DataManager::editOneObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse)
{
    Q_UNUSED(query);
    Q_UNUSED(onProgress);
    onResponse(DataResponse());
}

void DataManager::deleteOneObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse)
{
    Q_UNUSED(query);
    Q_UNUSED(onProgress);
    onResponse(DataResponse());
}

void DataManager::deleteManyObjects(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse)
{
    Q_UNUSED(query);
    Q_UNUSED(onProgress);
    onResponse(DataResponse());
}


} // namespace DataGate
