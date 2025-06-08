#ifndef DATAGATE_AUTHENTICATOR_P_H
#define DATAGATE_AUTHENTICATOR_P_H

#include "authenticator.h"

#include <Jsoner/object.h>

#include <QtCore/qdatetime.h>

namespace DataGate {

class AuthenticatorPrivate
{
public:
    AuthenticatorPrivate(Authenticator *q)
        : q_ptr(q), loginManager(nullptr), managerOwned(false) {}

    Authenticator *q_ptr;

    Jsoner::Object loggedUser;
    QDateTime lastLogTime;

    AbstractLoginManager *loginManager;
    bool managerOwned;
};

} // namespace DataGate

#endif // DATAGATE_AUTHENTICATOR_P_H
