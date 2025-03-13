#ifndef DATAGATE_GLOBAL_H
#define DATAGATE_GLOBAL_H

#include <DataGate/config.h>

#ifdef DATAGATE_SHARED
#ifdef DATAGATE_BUILD
#define DATAGATE_EXPORT Q_DECL_EXPORT
#else
#define DATAGATE_EXPORT Q_DECL_IMPORT
#endif
#else
#define DATAGATE_EXPORT
#endif

#define DATAKIT_Q(ClassName) ClassName *q = static_cast<ClassName *>(q_ptr)
#define DATAKIT_D(ClassName) \
    ClassName##Private *d = static_cast<ClassName##Private *>(qGetPtrHelper(d_ptr))

#endif // DATAGATE_GLOBAL_H
