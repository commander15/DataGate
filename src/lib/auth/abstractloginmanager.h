#ifndef DATAGATE_ABSTRACTLOGINCONTROLLER_H
#define DATAGATE_ABSTRACTLOGINCONTROLLER_H

#include <DataGate/global.h>
#include <DataGate/abstractdatamanager.h>
#include <DataGate/dataquery.h>
#include <DataGate/dataresponse.h>

#include <QtCore/qvariant.h>

namespace DataGate {

class DATAGATE_EXPORT LoginQuery : public DataQuery
{
public:
    LoginQuery() = default;
    LoginQuery(const LoginQuery &other) = default;

    QString identifier() const { return parameter("identifier").toString(); }
    void setIdentifier(const QString &id) { setParameter("identifier", id); }

    QString password() const { return parameter("password").toString(); }
    void setPassword(const QString &pass) { setParameter("password", pass); }
};

class DATAGATE_EXPORT AbstractLoginManager
{
public:
    virtual ~AbstractLoginManager() = default;

    void logIn(const QString &identifier, const QString &password, const DataQueryResponseCallback &callback);
    void logIn(const LoginQuery &query, const DataQueryResponseCallback &callback);

    void logOut(const DataQueryResponseCallback &callback);
    void logOut(const LoginQuery &query, const DataQueryResponseCallback &callback);

protected:
    virtual void attemptLogIn(const LoginQuery &query, const DataQueryResponseCallback &callback) = 0;
    virtual void attemptLogOut(const LoginQuery &query, const DataQueryResponseCallback &callback) = 0;
};

} // namespace DataGate

#endif // DATAGATE_ABSTRACTLOGINCONTROLLER_H
