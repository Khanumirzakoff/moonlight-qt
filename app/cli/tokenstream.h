#pragma once
#include <QObject>
#include "settings/streamingpreferences.h"
class SessionManager;
namespace CliTokenStream {
    class Launcher : public QObject {
        Q_OBJECT
    public:
        explicit Launcher(QString token, StreamingPreferences* preferences, QObject *parent = nullptr);
        Q_INVOKABLE void execute();
    signals:
        void sessionReady(QString vmHost, QString sessionId);
        void failed(QString error);
    private:
        SessionManager* m_SessionManager;
        QString m_Token;
    };
}
