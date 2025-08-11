#include "sessionmanager.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
SessionManager::SessionManager(QObject *parent) : QObject(parent) {
    nam = new QNetworkAccessManager(this);
}
void SessionManager::claimSession(const QString &token) {
    qDebug() << "Backendga sessiya so'rovi yuborilmoqda, token:" << token;
    QNetworkRequest request(QUrl("http://localhost:3000/session/claim"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject json;
    json["token"] = token;
    QNetworkReply* reply = nam->post(request, QJsonDocument(json).toJson());
    connect(reply, &QNetworkReply::finished, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QJsonObject response = QJsonDocument::fromJson(reply->readAll()).object();
            emit sessionReady(response["vmHost"].toString(), response["sessionId"].toString());
        } else {
            emit sessionFailed(reply->errorString());
        }
        reply->deleteLater();
    });
}
