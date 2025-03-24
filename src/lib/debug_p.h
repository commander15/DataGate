#ifndef DATAGATE_DEBUG_P_H
#define DATAGATE_DEBUG_P_H

#include <QtCore/qloggingcategory.h>

#define datagateDebug()    qCDebug(datagate).noquote().nospace()
#define datagateInfo()     qCInfo(datagate).noquote().nospace()
#define datagateWarning()  qCWarning(datagate).noquote().nospace()
#define datagateCritical() qCCritical(datagate).noquote().nospace()

Q_DECLARE_LOGGING_CATEGORY(datagate)

#endif // DATAGATE_DEBUG_P_H
