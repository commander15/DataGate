#include "datamanager.h"

#include <DataGate/dataresponse.h>

namespace DataGate {

bool DataManager::hasFeature(Feature feature, AbstractDataClient *client) const
{
    Q_UNUSED(feature);
    Q_UNUSED(client);
    return false;
}

void DataManager::fetchSomeSearchSuggestions(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse)
{
    Q_UNUSED(request);
    Q_UNUSED(onProgress);
    onResponse(DataResponse());
}

void DataManager::fetchManyObjects(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse)
{
    Q_UNUSED(request);
    Q_UNUSED(onProgress);
    onResponse(DataResponse());
}

void DataManager::fetchOneObject(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse)
{
    Q_UNUSED(request);
    Q_UNUSED(onProgress);
    onResponse(DataResponse());
}

void DataManager::addOneObject(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse)
{
    Q_UNUSED(request);
    Q_UNUSED(onProgress);
    onResponse(DataResponse());
}

void DataManager::editOneObject(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse)
{
    Q_UNUSED(request);
    Q_UNUSED(onProgress);
    onResponse(DataResponse());
}

void DataManager::deleteOneObject(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse)
{
    Q_UNUSED(request);
    Q_UNUSED(onProgress);
    onResponse(DataResponse());
}

void DataManager::deleteManyObjects(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse)
{
    Q_UNUSED(request);
    Q_UNUSED(onProgress);
    onResponse(DataResponse());
}


} // namespace DataGate
