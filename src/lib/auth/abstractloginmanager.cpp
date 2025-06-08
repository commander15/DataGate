#include "abstractloginmanager.h"

namespace DataGate {

void AbstractLoginManager::logIn(const QString &identifier, const QString &password, const DataResponseCallback &callback)
{
    LoginRequest request;
    request.setIdentifier(identifier);
    request.setPassword(password);
    attemptLogIn(request, callback);
}

void AbstractLoginManager::logIn(const LoginRequest &request, const DataResponseCallback &callback)
{
    attemptLogIn(request, callback);
}

void AbstractLoginManager::logOut(const DataResponseCallback &callback)
{
    attemptLogOut(LoginRequest(), callback);
}

void AbstractLoginManager::logOut(const LoginRequest &request, const DataResponseCallback &callback)
{
    attemptLogOut(request, callback);
}

} // namespace DataGate
