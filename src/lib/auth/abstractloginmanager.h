#ifndef DATAGATE_ABSTRACTLOGINMANAGER_H
#define DATAGATE_ABSTRACTLOGINMANAGER_H

#include <DataGate/global.h>
#include <DataGate/abstractdatamanager.h>
#include <DataGate/datarequest.h>
#include <DataGate/dataresponse.h>

#include <QtCore/qvariant.h>

namespace DataGate {

class DATAGATE_EXPORT LoginRequest : public DataRequest
{
public:
    LoginRequest() = default;
    LoginRequest(const LoginRequest &other) = default;

    QString identifier() const { return parameter("identifier").toString(); }
    void setIdentifier(const QString &id) { setParameter("identifier", id); }

    QString password() const { return parameter("password").toString(); }
    void setPassword(const QString &pass) { setParameter("password", pass); }
};

class DATAGATE_EXPORT AbstractLoginManager
{
public:
    virtual ~AbstractLoginManager() = default;

    void logIn(const QString &identifier, const QString &password, const DataResponseCallback &callback);
    void logIn(const LoginRequest &request, const DataResponseCallback &callback);

    void logOut(const DataResponseCallback &callback);
    void logOut(const LoginRequest &request, const DataResponseCallback &callback);

protected:
    virtual void attemptLogIn(const LoginRequest &request, const DataResponseCallback &callback) = 0;
    virtual void attemptLogOut(const LoginRequest &request, const DataResponseCallback &callback) = 0;
};

} // namespace DataGate

#endif // DATAGATE_ABSTRACTLOGINMANAGER_H
