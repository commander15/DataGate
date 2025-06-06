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
        : q_ptr(q), loginController(nullptr), controllerOwned(false) {}

    Authenticator *q_ptr;

    Jsoner::Object loggedUser;
    QDateTime lastLogTime;

    AbstractLoginManager *loginController;
    bool controllerOwned;
};

} // namespace DataGate

#endif // DATAGATE_AUTHENTICATOR_P_H
