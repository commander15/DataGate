#include "abstractdatamanager.h"

#include <Jsoner/object.h>
#include <Jsoner/array.h>

#include <DataGate/datarequest.h>
#include <DataGate/dataresponse.h>

namespace DataGate {

void AbstractDataManager::fetchSearchSuggestions(const DataRequest &request, const DataResponseCallback &onResponse)
{
    if (onResponse)
        fetchSomeSearchSuggestions(request, [](qint64, qint64) {}, onResponse);
}

void AbstractDataManager::fetchSearchSuggestions(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse)
{
    if (onResponse)
        fetchSomeSearchSuggestions(request, onProgress ? onProgress : [](qint64, qint64) {}, onResponse);
}

void AbstractDataManager::fetchObjects(const DataRequest &request, const DataResponseCallback &onResponse)
{
    if (onResponse)
        fetchObjects(request, [](qint64, qint64) {}, onResponse);
}

void AbstractDataManager::fetchObjects(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse)
{
    if (onResponse)
        fetchManyObjects(request, onProgress ? onProgress : [](qint64, qint64) {}, onResponse);
}

void AbstractDataManager::fetchObject(const DataRequest &request, const DataResponseCallback &onResponse)
{
    if (onResponse)
        fetchOneObject(request, [](qint64, qint64) {}, onResponse);
}

void AbstractDataManager::fetchObject(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse)
{
    if (onResponse)
        fetchOneObject(request, onProgress, onResponse);
}

void AbstractDataManager::addObject(const DataRequest &request, const DataResponseCallback &onResponse)
{
    if (onResponse)
        addOneObject(request, [](qint64, qint64) {}, onResponse);
}

void AbstractDataManager::addObject(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse)
{
    if (onResponse)
        addOneObject(request, onProgress ? onProgress : [](qint64, qint64) {}, onResponse);
}

void AbstractDataManager::editObject(const DataRequest &request, const DataResponseCallback &onResponse)
{
    if (onResponse)
        editObject(request, [](qint64, qint64) {}, onResponse);
}

void AbstractDataManager::editObject(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse)
{
    if (onResponse)
        editOneObject(request, onProgress ? onProgress : [](qint64, qint64) {}, onResponse);
}

void AbstractDataManager::deleteObject(const DataRequest &request, const DataResponseCallback &onResponse)
{
    if (onResponse)
        deleteOneObject(request, [](qint64, qint64) {}, onResponse);
}

void AbstractDataManager::deleteObject(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse)
{
    if (onResponse)
        deleteOneObject(request, onProgress ? onProgress : [](qint64, qint64) {}, onResponse);
}

void AbstractDataManager::deleteObjects(const DataRequest &request, const DataResponseCallback &onResponse)
{
    if (!onResponse)
        return;

    if (request.array().count() == 1)
        deleteOneObject(request, [](qint64, qint64) {}, onResponse);
    else
        deleteManyObjects(request, [](qint64, qint64) {}, onResponse);
}

void AbstractDataManager::deleteObjects(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse)
{
    if (!onResponse)
        return;

    if (request.array().count() == 1)
        deleteOneObject(request, onProgress ? onProgress : [](qint64, qint64) {}, onResponse);
    else
        deleteManyObjects(request, onProgress ? onProgress : [](qint64, qint64) {}, onResponse);
}

} // namespace DataGate
