#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QSqlDatabase>
class DatabaseConnection
{
public:
    DatabaseConnection(const QString &server,
                       const QString &driver,
                       const QString &user,
                       const QString &password,
                       const QString &databaseName,
                       bool trustedConnection = true
                       );
    bool openDatabase(QString *error = nullptr);
private:
    QSqlDatabase mDatabase;
    QString mServer;
    QString mDriver;
    QString mUser;
    QString mPassword;
    QString mDatabaseName;
    bool mTrustedConnection;
};

#endif // DATABASECONNECTION_H
