#ifndef DATAGATE_AUTHENTICATOR_P_H
#define DATAGATE_AUTHENTICATOR_P_H

#include "authenticator.h"

#include <Jsoner/object.h>

#include <QtCore/qdatetime.h>

namespace DataGate {

class AuthenticatorPrivate
{
public:
    Authenticator *q_ptr;

    Jsoner::Object loggedUser;
    QDateTime lastLogTime;

    AbstractLoginController *loginController;
};

} // namespace DataGate

#endif // DATAGATE_AUTHENTICATOR_P_H
