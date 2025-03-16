#include "dataresponse.h"

#include <Jsoner/object.h>
#include <Jsoner/array.h>

#include <QtCore/qstring.h>
#include <QtCore/qvarianthash.h>

namespace DataGate {

class DataResponseData : public QSharedData
{
public:
    int code = 0;

    QString title;
    QString text;
    QString informativeText;
    QString detailedText;

    Jsoner::Array array;
    int page = 1;
    int pageCount = 1;
    QVariantHash dataHash;
    bool success = false;
};

DataResponse::DataResponse()
    : d_ptr(new DataResponseData)
{
}

DataResponse::DataResponse(const DataResponse &other)
    : d_ptr(other.d_ptr)  // Shared pointer, no deep copy needed
{
}

DataResponse::~DataResponse() = default;

DataResponse &DataResponse::operator=(const DataResponse &other)
{
    if (this != &other) {
        d_ptr = other.d_ptr; // Shared pointer, no deep copy needed
    }
    return *this;
}

int DataResponse::code() const
{
    return d_ptr->code;
}

void DataResponse::setCode(int code)
{
    d_ptr->code = code;
}

QString DataResponse::title() const
{
    return d_ptr->title;
}

void DataResponse::setTitle(const QString &title)
{
    d_ptr->title = title;
}

QString DataResponse::text() const
{
    return d_ptr->text;
}

void DataResponse::setText(const QString &text)
{
    d_ptr->text = text;
}

QString DataResponse::informativeText() const
{
    return d_ptr->informativeText;
}

void DataResponse::setInformativeText(const QString &text)
{
    d_ptr->informativeText = text;
}

QString DataResponse::detailedText() const
{
    return d_ptr->detailedText;
}

void DataResponse::setDetailedText(const QString &text)
{
    d_ptr->detailedText = text;
}

Jsoner::Object DataResponse::object() const
{
    return (!d_ptr->array.isEmpty() ? Jsoner::Object(d_ptr->array.first()) : Jsoner::Object());
}

void DataResponse::setObject(const Jsoner::Object &object)
{
    d_ptr->array = Jsoner::Array({object});
}

Jsoner::Array DataResponse::array() const
{
    return (d_ptr->array);
}

void DataResponse::setArray(const Jsoner::Array &array)
{
    d_ptr->array = array;
}

int DataResponse::page() const
{
    return d_ptr->page;
}

void DataResponse::setPage(int page)
{
    d_ptr->page = page;
}

int DataResponse::pageCount() const
{
    return d_ptr->pageCount;
}

void DataResponse::setPageCount(int count)
{
    d_ptr->pageCount = count;
}

bool DataResponse::hasData(const QString &name) const
{
    return d_ptr->dataHash.contains(name);
}

QVariant DataResponse::data(const QString &name) const
{
    return d_ptr->dataHash.value(name);
}

void DataResponse::setData(const QString &name, const QVariant &value)
{
    d_ptr->dataHash.insert(name, value);
}

QStringList DataResponse::dataNames() const
{
    return d_ptr->dataHash.keys();
}

bool DataResponse::isSuccess() const
{
    return d_ptr->success;
}

void DataResponse::setSuccess(bool success)
{
    d_ptr->success = success;
}

} // namespace DataGate
