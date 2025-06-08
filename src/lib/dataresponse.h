#ifndef DATAGATE_DATARESPONSE_H
#define DATAGATE_DATARESPONSE_H

#include <DataGate/global.h>

#include <QtCore/qshareddata.h>

namespace Jsoner {
class Object;
class Array;
}

namespace DataGate {

class DataResponseData;
class DATAGATE_EXPORT DataResponse
{
public:
    DataResponse();
    DataResponse(const DataResponse &other);
    ~DataResponse();

    DataResponse &operator=(const DataResponse &other);

    bool hasCode() const;
    int code() const;
    void setCode(int code);

    QString title() const;
    void setTitle(const QString &title);

    QString text() const;
    void setText(const QString &text);

    QString informativeText() const;
    void setInformativeText(const QString &text);

    QString detailedText() const;
    void setDetailedText(const QString &text);

    bool hasMessage() const;

    bool hasObject() const;
    Jsoner::Object object() const;
    void setObject(const Jsoner::Object &object);

    bool hasArray() const;
    Jsoner::Array array() const;
    void setArray(const Jsoner::Array &array);

    int page() const;
    void setPage(int page);

    int pageCount() const;
    void setPageCount(int count);

    bool hasPaginationData() const;

    bool hasData(const QString &name) const;
    QVariant data(const QString &name) const;
    void setData(const QString &name, const QVariant &value);
    QStringList dataNames() const;

    bool isSuccess() const;
    void setSuccess(bool success);

private:
    QSharedDataPointer<DataResponseData> d_ptr;
};

} // namespace DataGate

#endif // DATAGATE_DATARESPONSE_H
