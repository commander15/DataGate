#ifndef DATAGATE_PERMISSIONMANAGER_H
#define DATAGATE_PERMISSIONMANAGER_H

#include <DataGate/global.h>

namespace Jsoner {
class Array;
}

namespace DataGate {

class DATAGATE_EXPORT PermissionManager
{
public:
    static bool hasPermission(const QString &permission);
    static QStringList availablePermissions();
    static void updatePermissions(const QStringList &permissions);

    static void load(const Jsoner::Array &permissions);
    static void reset(bool allowAll = false);

private:
    static QStringList s_permissions;
};

} // namespace DataGate

#endif // DATAGATE_PERMISSIONMANAGER_H
