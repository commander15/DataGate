#include "abstractdatacontroller.h"

#include <DataGate/dataresponse.h>

namespace DataGate {

AbstractDataController::AbstractDataController()
{
    if (!s_instance)
        s_instance = this;
}

AbstractDataController::~AbstractDataController()
{
    if (s_instance == this)
        s_instance = nullptr;
}

void AbstractDataController::fetchSearchSuggestions(const DataQuery &query, const DataQueryResponseCallback &onResponse)
{
    fetchSearchSuggestions(query, [](qint64, qint64) {}, onResponse);  // Pass a no-op progress callback
}

void AbstractDataController::fetchSearchSuggestions(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse)
{
    if (onResponse)
    {
        fetchSomeSearchSuggestions(query, onProgress, onResponse);  // Call the virtual method with the given callbacks
    }
}

void AbstractDataController::fetchObjects(const DataQuery &query, const DataQueryResponseCallback &onResponse)
{
    fetchObjects(query, [](qint64, qint64) {}, onResponse);  // Pass a no-op progress callback
}

void AbstractDataController::fetchObjects(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse)
{
    if (onResponse)
    {
        fetchManyObjects(query, onProgress, onResponse);  // Call the virtual method with the given callbacks
    }
}

void AbstractDataController::fetchObject(const DataQuery &query, int targetRequestType, const DataQueryResponseCallback &onResponse)
{
    fetchObject(query, [](qint64, qint64) {}, onResponse);  // Pass a no-op progress callback
}

void AbstractDataController::fetchObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse)
{
    if (onResponse)
    {
        fetchOneObject(query, onProgress, onResponse);  // Call the virtual method with the given callbacks
    }
}

void AbstractDataController::addObject(const DataQuery &query, const DataQueryResponseCallback &onResponse)
{
    addObject(query, [](qint64, qint64) {}, onResponse);  // Pass a no-op progress callback
}

void AbstractDataController::addObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse)
{
    if (onResponse)
    {
        addOneObject(query, onProgress, onResponse);  // Call the virtual method with the given callbacks
    }
}

void AbstractDataController::editObject(const DataQuery &query, const DataQueryResponseCallback &onResponse)
{
    editObject(query, [](qint64, qint64) {}, onResponse);  // Pass a no-op progress callback
}

void AbstractDataController::editObject(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse)
{
    if (onResponse)
    {
        editOneObject(query, onProgress, onResponse);  // Call the virtual method with the given callbacks
    }
}

void AbstractDataController::deleteObjects(const DataQuery &query, const DataQueryResponseCallback &onResponse)
{
    deleteObjects(query, [](qint64, qint64) {}, onResponse);  // Pass a no-op progress callback
}

void AbstractDataController::deleteObjects(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse)
{
    if (onResponse)
    {
        deleteManyObjects(query, onProgress, onResponse);  // Call the virtual method with the given callbacks
    }
}

void AbstractDataController::fetchSomeSearchSuggestions(const DataQuery &query, const DataQueryProgressCallback &onProgress, const DataQueryResponseCallback &onResponse)
{
    onResponse(DataResponse());
}

AbstractDataController *AbstractDataController::instance()
{
    return s_instance;
}

AbstractDataController *AbstractDataController::s_instance = nullptr;

} // namespace DataGate
