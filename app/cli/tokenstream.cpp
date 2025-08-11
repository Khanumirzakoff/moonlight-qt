#include "tokenstream.h"
#include "backend/sessionmanager.h"
#include <QDebug>
CliTokenStream::Launcher::Launcher(QString token, StreamingPreferences* preferences, QObject *parent)
    : QObject(parent), m_Token(token) {
    m_SessionManager = new SessionManager(this);
    connect(m_SessionManager, &SessionManager::sessionReady, this, &CliTokenStream::Launcher::sessionReady);
    connect(m_SessionManager, &SessionManager::sessionFailed, this, &CliTokenStream::Launcher::failed);
}
void CliTokenStream::Launcher::execute() {
    qDebug() << "Token Launcher ishga tushdi...";
    m_SessionManager->claimSession(m_Token);
}
