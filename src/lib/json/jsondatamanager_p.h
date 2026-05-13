#ifndef DATAGATE_JSONDATAMANAGER_P_H
#define DATAGATE_JSONDATAMANAGER_P_H

#include "jsondatamanager.h"

#include <Jsoner/array.h>

namespace DataGate {

class JsonDataManagerPrivate
{
public:
    QList<AbstractDataManager::Feature> features;
    Jsoner::Array array;

    QString idField = "_id";
    int lastId = 0;
};

}

#endif // DATAGATE_JSONDATAMANAGER_P_H
