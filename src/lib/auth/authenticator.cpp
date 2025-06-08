#include "authenticator.h"
#include "authenticator_p.h"

#include <DataGate/abstractloginmanager.h>

namespace DataGate {

Authenticator::Authenticator(QObject *parent)
    : QObject(parent)
    , d_ptr(new AuthenticatorPrivate(this))
{
}

Authenticator::~Authenticator()
{
    AuthenticatorPrivate *d = self();
    if (d->managerOwned)
        delete d->loginManager;
}

Jsoner::Object Authenticator::loggedUser()
{
    return self()->loggedUser;
}

QDateTime Authenticator::lastLogInTime()
{
    return self()->lastLogTime;
}

AbstractLoginManager *Authenticator::loginManager()
{
    return self()->loginManager;
}

void Authenticator::setLoginManager(AbstractLoginManager *manager, bool own)
{
    AuthenticatorPrivate *d = self();
    d->loginManager = manager;
    d->managerOwned = own;
}

Authenticator *Authenticator::global()
{
    return self()->q_ptr;
}

void Authenticator::logIn(const QString &id, const QString &pass)
{
    AuthenticatorPrivate *self = Authenticator::self();

    AbstractLoginManager *manager = self->loginManager;
    if (!manager)
        return;

    LoginRequest request;
    request.setIdentifier(id);
    request.setPassword(pass);

    manager->logIn(request, [self](const DataResponse &response) {
        self->q_ptr->processLogInResponse(response);
    });
}

void Authenticator::logOut()
{
    AuthenticatorPrivate *self = Authenticator::self();

    AbstractLoginManager *manager = self->loginManager;
    if (!manager)
        return;

    LoginRequest request;
    request.setObject(self->loggedUser);

    manager->logOut(request, [self](const DataResponse &response) {
        self->q_ptr->processLogOutResponse(response);
    });
}

void Authenticator::processLogInResponse(const DataResponse &response)
{
    if (response.isSuccess()) {
        AuthenticatorPrivate *self = Authenticator::self();
        self->loggedUser = response.object();
        self->lastLogTime = QDateTime::currentDateTime();
        emit loggedIn(self->loggedUser);
    } else {
        int code = response.code();
        if (code < AuthenticationError::NoError || code > AuthenticationError::UnknownError)
            code = AuthenticationError::UnknownError;
        emit logInFailed(AuthenticationError(response.text(), static_cast<AuthenticationError::ErrorType>(code)));
    }
}

void Authenticator::processLogOutResponse(const DataResponse &response)
{
    if (!response.isSuccess()) {
        qDebug("Something gone wrong during logout !");
    }

    AuthenticatorPrivate *self = Authenticator::self();
    self->loggedUser = Jsoner::Object();
    self->lastLogTime = QDateTime();
    emit loggedOut();
}

AuthenticatorPrivate *Authenticator::self()
{
    if (!s_global)
        s_global.reset(new Authenticator());
    return s_global->d_ptr.get();
}

QScopedPointer<Authenticator> Authenticator::s_global;

} // namespace DataGate
