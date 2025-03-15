#include "authenticator.h"
#include "authenticator_p.h"

#include <DataGate/abstractlogincontroller.h>

namespace DataGate {

Authenticator::Authenticator(QObject *parent)
    : QObject(parent)
    , d_ptr(new AuthenticatorPrivate())
{
}

Authenticator::~Authenticator()
{
}

Jsoner::Object Authenticator::loggedUser()
{
    return self()->loggedUser;
}

QDateTime Authenticator::lastLogInTime()
{
    return self()->lastLogTime;
}

AbstractLoginController *Authenticator::loginController()
{
    return self()->loginController;
}

void Authenticator::setLoginController(AbstractLoginController *controller)
{
    self()->loginController = controller;
}

Authenticator *Authenticator::global()
{
    return self()->q_ptr;
}

void Authenticator::logIn(const QString &id, const QString &pass)
{
    AuthenticatorPrivate *self = Authenticator::self();

    AbstractLoginController *controller = self->loginController;
    if (!controller)
        return;

    LoginQuery query;
    query.setIdentifier(id);
    query.setPassword(pass);

    controller->logIn(query, [self](const DataResponse &response) {
        self->q_ptr->processLogInResponse(response);
    });
}

void Authenticator::logOut()
{
    AuthenticatorPrivate *self = Authenticator::self();

    AbstractLoginController *controller = self->loginController;
    if (!controller)
        return;

    LoginQuery query;
    query.setObject(self->loggedUser);

    controller->logOut(query, [self](const DataResponse &response) {
        self->q_ptr->processLogOutResponse(response);
    });
}

void Authenticator::processLogInResponse(const DataResponse &response)
{
    AuthenticatorPrivate *self = Authenticator::self();

    if (response.isSuccess()) {
        self->loggedUser = response.object();
        self->lastLogTime = QDateTime::currentDateTime();
        emit loggedIn(self->loggedUser);
    } else {
        const int code = response.code();
        if (code > AuthenticationError::NoError && code < AuthenticationError::UnknownError)
            emit logInFailed(static_cast<AuthenticationError::ErrorType>(code));
        else
            emit logInFailed(AuthenticationError::UnknownError);
    }
}

void Authenticator::processLogOutResponse(const DataResponse &response)
{
    //
}

AuthenticatorPrivate *Authenticator::self()
{
    if (!s_global)
        s_global.reset(new Authenticator());
    return s_global->d_ptr.get();
}

QScopedPointer<Authenticator> Authenticator::s_global;

} // namespace DataGate
