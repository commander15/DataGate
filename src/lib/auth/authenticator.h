#ifndef DATAGATE_AUTHENTICATOR_H
#define DATAGATE_AUTHENTICATOR_H

#include <DataGate/global.h>

#include <QtCore/qobject.h>
#include <QtCore/qcoreapplication.h>

namespace Jsoner {
class Object;
}

class QDateTime;

namespace DataGate {

class AbstractLoginController;
class DataResponse;

class DATAGATE_EXPORT AuthenticationError
{
    Q_DECLARE_TR_FUNCTIONS(Authenticator)

public:
    enum ErrorType {
        NoError,
        BadCredentials,
        UserNotFound,
        DisabledAccount,

        UnknownError
    };

    AuthenticationError(ErrorType error = NoError) : m_error(error) {}

    ErrorType error() const { return m_error; }

    QString errorString() const
    {
        switch (m_error) {
        case NoError:
            return QString();

        case BadCredentials:
            return tr("Incorrect user login / password");

        case UserNotFound:
            return tr("User not found");

        case DisabledAccount:
            return tr("User disabled");

        case UnknownError:
        default:
            return tr("Unknown error");
        }
    }

private:
    ErrorType m_error;
};

class AuthenticatorPrivate;
class DATAGATE_EXPORT Authenticator : public QObject
{
    Q_OBJECT

public:
    ~Authenticator();

    template<typename LoginController, typename... Args>
    static void init(Args&&... args)
    { global()->setLoginController(new LoginController(std::forward<Args>(args)...)); }

    static Jsoner::Object loggedUser();
    static QDateTime lastLogInTime();

    static AbstractLoginController *loginController();
    static void setLoginController(AbstractLoginController *controller);

    static Authenticator *global();

public slots:
    static void logIn(const QString &id, const QString &pass);
    static void logOut();

signals:
    void loggedIn(const Jsoner::Object &user);
    void logInFailed(const AuthenticationError &error);
    void loggedOut();

private:
    explicit Authenticator(QObject *parent = nullptr);

    void processLogInResponse(const DataResponse &response);
    void processLogOutResponse(const DataResponse &response);

    static AuthenticatorPrivate *self();

    QScopedPointer<AuthenticatorPrivate> d_ptr;
    static QScopedPointer<Authenticator> s_global;
};

} // namespace DataGate

#endif // DATAGATE_AUTHENTICATOR_H
