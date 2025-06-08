#ifndef DATAGATE_GLOBAL_H
#define DATAGATE_GLOBAL_H

#include <DataGate/config.h>

#include <functional>

#ifdef DATAGATE_SHARED
#   ifdef DATAGATE_BUILD
#       define DATAGATE_EXPORT Q_DECL_EXPORT
#   else
#       define DATAGATE_EXPORT Q_DECL_IMPORT
#   endif
#else
#   define DATAGATE_EXPORT
#endif

#define DATAGATE_Q(ClassName) ClassName *q = static_cast<ClassName *>(q_ptr)
#define DATAGATE_D(ClassName) \
    ClassName##Private *d = static_cast<ClassName##Private *>(qGetPtrHelper(d_ptr))

namespace DataGate {

class DataRequest;
class DataResponse;

typedef std::function<void(qint64, qint64)> DataRequestCallback;
typedef std::function<void(const DataResponse &response)> DataResponseCallback;

}

#endif // DATAGATE_GLOBAL_H
