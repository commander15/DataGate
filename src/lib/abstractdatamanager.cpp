#include "abstractdatamanager.h"

#include <DataGate/dataquery.h>
#include <DataGate/dataresponse.h>

#include <Jsoner/object.h>
#include <Jsoner/array.h>

namespace DataGate {

void AbstractDataManager::fetchSearchSuggestions(const DataQuery &query, const DataQueryResponseCallback &onResponse)
{
    if (onResponse)
        fetchSomeSearchSuggestions(query, [](qint64, qint64) {}, onResponse);
}

void AbstractDataManager::fetchSearchSuggestions(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse)
{
    if (onResponse)
        fetchSomeSearchSuggestions(query, onProgress ? onProgress : [](qint64, qint64) {}, onResponse);
}

void AbstractDataManager::fetchObjects(const DataQuery &query, const DataQueryResponseCallback &onResponse)
{
    if (onResponse)
        fetchObjects(query, [](qint64, qint64) {}, onResponse);
}

void AbstractDataManager::fetchObjects(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse)
{
    if (onResponse)
        fetchManyObjects(query, onProgress ? onProgress : [](qint64, qint64) {}, onResponse);
}

void AbstractDataManager::fetchObject(const DataQuery &query, const DataQueryResponseCallback &onResponse)
{
    if (onResponse)
        fetchOneObject(query, [](qint64, qint64) {}, onResponse);
}

void AbstractDataManager::fetchObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse)
{
    if (onResponse)
        fetchOneObject(query, onProgress, onResponse);
}

void AbstractDataManager::addObject(const DataQuery &query, const DataQueryResponseCallback &onResponse)
{
    if (onResponse)
        addOneObject(query, [](qint64, qint64) {}, onResponse);
}

void AbstractDataManager::addObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse)
{
    if (onResponse)
        addOneObject(query, onProgress ? onProgress : [](qint64, qint64) {}, onResponse);
}

void AbstractDataManager::editObject(const DataQuery &query, const DataQueryResponseCallback &onResponse)
{
    if (onResponse)
        editObject(query, [](qint64, qint64) {}, onResponse);
}

void AbstractDataManager::editObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse)
{
    if (onResponse)
        editOneObject(query, onProgress ? onProgress : [](qint64, qint64) {}, onResponse);
}

void AbstractDataManager::deleteObject(const DataQuery &query, const DataQueryResponseCallback &onResponse)
{
    if (onResponse)
        deleteOneObject(query, [](qint64, qint64) {}, onResponse);
}

void AbstractDataManager::deleteObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse)
{
    if (onResponse)
        deleteOneObject(query, onProgress ? onProgress : [](qint64, qint64) {}, onResponse);
}

void AbstractDataManager::deleteObjects(const DataQuery &query, const DataQueryResponseCallback &onResponse)
{
    if (!onResponse)
        return;

    if (query.array().count() == 1)
        deleteOneObject(query, [](qint64, qint64) {}, onResponse);
    else
        deleteManyObjects(query, [](qint64, qint64) {}, onResponse);
}

void AbstractDataManager::deleteObjects(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse)
{
    if (!onResponse)
        return;

    if (query.array().count() == 1)
        deleteOneObject(query, onProgress ? onProgress : [](qint64, qint64) {}, onResponse);
    else
        deleteManyObjects(query, onProgress ? onProgress : [](qint64, qint64) {}, onResponse);
}

} // namespace DataGate
