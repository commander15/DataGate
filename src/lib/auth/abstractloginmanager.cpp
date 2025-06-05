#include "abstractloginmanager.h"

namespace DataGate {

void AbstractLoginManager::logIn(const QString &identifier, const QString &password, const DataQueryResponseCallback &callback)
{
    LoginQuery query;
    query.setIdentifier(identifier);
    query.setPassword(password);
    attemptLogIn(query, callback);
}

void AbstractLoginManager::logIn(const LoginQuery &query, const DataQueryResponseCallback &callback)
{
    attemptLogIn(query, callback);
}

void AbstractLoginManager::logOut(const DataQueryResponseCallback &callback)
{
    attemptLogOut(LoginQuery(), callback);
}

void AbstractLoginManager::logOut(const LoginQuery &query, const DataQueryResponseCallback &callback)
{
    attemptLogOut(query, callback);
}

} // namespace DataGate
