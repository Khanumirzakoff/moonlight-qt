#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H
#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
class SessionManager : public QObject {
    Q_OBJECT
public:
    explicit SessionManager(QObject *parent = nullptr);
    void claimSession(const QString &token);
signals:
    void sessionReady(QString vmHost, QString sessionId);
    void sessionFailed(QString errorMessage);
private:
    QNetworkAccessManager* nam;
};
#endif // SESSIONMANAGER_H
