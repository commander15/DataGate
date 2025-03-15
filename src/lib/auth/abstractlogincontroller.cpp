#include "abstractlogincontroller.h"

namespace DataGate {

void AbstractLoginController::logIn(const QString &identifier, const QString &password, const DataQueryResponseCallback &callback)
{
    LoginQuery query;
    query.setIdentifier(identifier);
    query.setPassword(password);
    attemptLogIn(query, callback);
}

void AbstractLoginController::logIn(const LoginQuery &query, const DataQueryResponseCallback &callback)
{
    attemptLogIn(query, callback);
}

void AbstractLoginController::logOut(const DataQueryResponseCallback &callback)
{
    attemptLogOut(LoginQuery(), callback);
}

void AbstractLoginController::logOut(const LoginQuery &query, const DataQueryResponseCallback &callback)
{
    attemptLogOut(query, callback);
}

} // namespace DataGate
