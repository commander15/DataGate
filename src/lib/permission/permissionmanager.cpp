#include "permissionmanager.h"

#include <QtCore/qstringlist.h>

#include <Jsoner/array.h>
#include <Jsoner/object.h>

namespace DataGate {

bool PermissionManager::hasPermission(const QString &permission)
{
    if (s_permissions.isEmpty())
        return false;

    if (s_permissions.size() == 1 && s_permissions.constFirst() == '*')
        return true;

    const QStringList target = permission.split('.');
    auto i = std::find_if(s_permissions.begin(), s_permissions.end(), [&target](const QString &name) {
        const QStringList current = name.split('.', Qt::SkipEmptyParts);

        if (current == target)
            return true; // Exact match

        if (current.size() != target.size())
            return false; // size mismatch

        if (!current.contains('*'))
            return false; // We skip non wildcarded permissions

        for (int i(0); i < current.size(); ++i)
            if (current.at(i) != target.at(i) && current.at(i) != '*')
                return false; // Part not match the target at this point

        return true;
    });

    if (i != s_permissions.end())
        return true;
    else
        return false;
}

QStringList PermissionManager::availablePermissions()
{
    return s_permissions;
}

void PermissionManager::updatePermissions(const QStringList &permissions)
{
    s_permissions = permissions;
    //s_permissions.removeDuplicates();
}

void PermissionManager::load(const Jsoner::Array &permissions)
{
    reset(false);

    for (const QJsonValue &value : permissions) {
        if (value.isString())
            s_permissions.append(value.toString());

        if (value.isObject()) {
            const Jsoner::Object object = value.toObject();
            if (object.contains("name"))
                s_permissions.append(object.value("name").toString());
        }
    }
}

void PermissionManager::reset(bool allowAll)
{
    if (allowAll)
        s_permissions = { "*" };
    else
        s_permissions.clear();
}

QStringList PermissionManager::s_permissions = { "*" };

} // namespace DataGate
