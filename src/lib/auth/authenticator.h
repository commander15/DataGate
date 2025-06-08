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

class AbstractLoginManager;
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

    AuthenticationError(ErrorType type = NoError) : m_text(textFromType(type)), m_type(type) {}
    AuthenticationError(const QString &text, ErrorType type) : m_text(text.isEmpty() ? textFromType(type) : text), m_type(type) {}
    AuthenticationError(const AuthenticationError &other) = default;

    QString text() const { return m_text; }
    ErrorType type() const { return m_type; }
    bool isValid() const { return m_type != NoError; }

    static QString textFromType(ErrorType error)
    {
        switch (error) {
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
    QString m_text;
    ErrorType m_type;
};

class AuthenticatorPrivate;
class DATAGATE_EXPORT Authenticator : public QObject
{
    Q_OBJECT

public:
    ~Authenticator();

    template<typename LoginManager, typename... Args>
    static void init(Args&&... args)
    { setLoginManager(new LoginManager(std::forward<Args>(args)...), true); }

    static Jsoner::Object loggedUser();
    static QDateTime lastLogInTime();

    static AbstractLoginManager *loginManager();
    static void setLoginManager(AbstractLoginManager *manager, bool own = false);

    static Authenticator *global();

public slots:
    static void logIn(const QString &id, const QString &pass);
    static void logOut();

signals:
    void loggedIn(const Jsoner::Object &user);
    void logInFailed(const DataGate::AuthenticationError &error);
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
