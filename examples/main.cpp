#include <QtCore/qcoreapplication.h>

#include <DataGate/jsondatamanager.h>
#include <DataGate/datarequest.h>
#include <DataGate/dataresponse.h>

#include <Jsoner/array.h>
#include <Jsoner/object.h>

using namespace DataGate;

int main(int argc, char *argv[])
{
    Jsoner::Array messages;
    Jsoner::Object msg;

    msg.put("sender", "John");
    msg.put("text", "Hello World !");
    messages.append(msg);

    msg.put("sender", "John");
    msg.put("text", "How are you ?");
    messages.append(msg);

    JsonDataManager manager;
    manager.setData(messages);

    manager.fetchObjects(DataRequest(), [](const DataResponse &response) {
        if (response.isSuccess())
            qDebug() << response.array();
        else
            qDebug() << "Fetch error !";
    });

    Jsoner::Array all = { QJsonObject({ { "_id", 1 } }), QJsonObject({ { "_id", 2 } }) };
    manager.deleteObjects(DataRequest(all), [](const DataResponse &response) {
        qDebug() << response.isSuccess();
    });

    manager.fetchObjects(DataRequest(), [](const DataResponse &response) {
        if (response.isSuccess())
            qDebug() << response.array();
        else
            qDebug() << "Fetch error !";
    });

    return 0;
}
