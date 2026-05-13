#include "jsondatamanager.h"
#include "jsondatamanager_p.h"

#include <Jsoner/object.h>

#include <DataGate/datarequest.h>
#include <DataGate/dataresponse.h>

namespace DataGate {

JsonDataManager::JsonDataManager()
    : d_ptr(new JsonDataManagerPrivate())
{
    d_ptr->features.append(AbstractDataManager::ObjectFetch);
    d_ptr->features.append(AbstractDataManager::ObjectAdd);
    d_ptr->features.append(AbstractDataManager::ObjectEdit);
    d_ptr->features.append(AbstractDataManager::ObjectDelete);
}

JsonDataManager::~JsonDataManager()
{
}

bool JsonDataManager::hasFeature(Feature feature, AbstractDataClient *client) const
{
    Q_UNUSED(client);
    return d_ptr->features.contains(feature);
}

void JsonDataManager::setFeature(Feature feature, bool on)
{
    if (on && !d_ptr->features.contains(feature))
        d_ptr->features.append(feature);

    if (!on)
        d_ptr->features.removeOne(feature);
}

QString JsonDataManager::idField() const
{
    return d_ptr->idField;
}

void JsonDataManager::setIdField(const QString &field)
{
    d_ptr->idField = (field.isEmpty() ? "_id" : field);
}

Jsoner::Array JsonDataManager::data() const
{
    return d_ptr->array;
}

void JsonDataManager::setData(const Jsoner::Array &data)
{
    clear();

    for (int i(0); i < data.size(); ++i) {
        Jsoner::Object object = data.object(i);
        object.put(d_ptr->idField, generateId());
        d_ptr->array.append(object);
    }
}

void JsonDataManager::clear()
{
    d_ptr->array = Jsoner::Array();
    d_ptr->lastId = 0;
}

int JsonDataManager::objectIndex(int id) const
{
    auto it = std::find_if(d_ptr->array.constBegin(), d_ptr->array.constEnd(), [this, &id](const QJsonValue &value) {
        return value.toObject().value(d_ptr->idField).toInt() == id;
    });

    if (it == d_ptr->array.end())
        return -1;

    return std::distance(d_ptr->array.constBegin(), it);
}

int JsonDataManager::objectIndex(const Jsoner::Object &object) const
{
    return objectIndex(object.integer(d_ptr->idField));
}

void JsonDataManager::fetchSomeSearchSuggestions(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse)
{
    onResponse(DataResponse());
}

void JsonDataManager::fetchManyObjects(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse)
{
    DataResponse response;
    response.setArray(d_ptr->array);
    response.setSuccess(true);
    onResponse(response);
}

void JsonDataManager::fetchOneObject(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse)
{
    const int index = objectIndex(request);

    DataResponse response;
    if (index >= 0 && index < d_ptr->array.size()) {
        response.setObject(d_ptr->array.object(index));
        response.setSuccess(true);
    } else {
        response.setSuccess(false);
    }
    onResponse(response);
}

void JsonDataManager::addOneObject(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse)
{
    Jsoner::Object object = request.object();
    object.put(d_ptr->idField, generateId());
    d_ptr->array.append(object);

    DataResponse response;
    response.setObject(object);
    response.setSuccess(true);
    onResponse(response);
}

void JsonDataManager::editOneObject(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse)
{
    const int index = objectIndex(request);

    DataResponse response;
    if (index >= 0 && index < d_ptr->array.size()) {
        Jsoner::Object object = request.object();
        d_ptr->array.replace(index, object);
        response.setObject(object);
        response.setSuccess(true);
    } else {
        response.setSuccess(false);
    }
    onResponse(response);
}

void JsonDataManager::deleteOneObject(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse)
{
    const int index = objectIndex(request);

    DataResponse response;
    if (index >= 0 && index < d_ptr->array.size()) {
        d_ptr->array.removeAt(index);
        response.setSuccess(true);
    } else {
        response.setSuccess(false);
    }
    onResponse(response);
}

void JsonDataManager::deleteManyObjects(const DataRequest &request, const DataRequestCallback &onProgress, const DataResponseCallback &onResponse)
{
    const Jsoner::Array objects = request.array();

    for (const QJsonValue &value : objects) {
        const int index = objectIndex(value.toObject());
        if (index >= 0 && index < d_ptr->array.size())
            d_ptr->array.removeAt(index);
    }

    DataResponse response;
    response.setSuccess(true);
    onResponse(response);
}

int JsonDataManager::objectIndex(const DataRequest &request) const
{
    if (request.hasFilter(d_ptr->idField))
        request.filter(d_ptr->idField).toInt();

    return objectIndex(request.object());
}

int JsonDataManager::generateId()
{
    return ++d_ptr->lastId;
}

} // namespace DataGate
