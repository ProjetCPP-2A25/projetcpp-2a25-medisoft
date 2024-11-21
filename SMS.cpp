#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include "sms.h"

// Replace with your Twilio number
const QString twilio_number = "+15673414438";

// Constructor
sms::sms() {
}

// Method to send SMS
void sms::sendSMS(const QString &to, const QString &message) {
    // Create QNetworkAccessManager
    QNetworkAccessManager *manager = new QNetworkAccessManager();

    // Twilio API URL
    QUrl url("https://api.twilio.com/2010-04-01/Accounts/AC6d6b8f241105b94094bc22f53bbc6ef6/Messages.json");

    // Set up the request
    QNetworkRequest request(url);

    // Set the Authorization header
    QString accountSID = "AC6d6b8f241105b94094bc22f53bbc6ef6";
    QString authToken = "30ea4343847a7d05307c8f1942aad0e7";
    QString credentials = accountSID + ":" + authToken;
    QByteArray base64Credentials = credentials.toUtf8().toBase64();
    qDebug() << "Authorization Header:" << "Basic " + base64Credentials;

    request.setRawHeader("Authorization", "Basic " + base64Credentials);

    // Encode the post data
    QUrlQuery postData;
    postData.addQueryItem("From", twilio_number);
    postData.addQueryItem("To", to);
    postData.addQueryItem("Body", message);

    // Set the content type
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    // Send the POST request
    QNetworkReply *reply = manager->post(request, postData.toString(QUrl::FullyEncoded).toUtf8());

    // Handle the reply
    QObject::connect(reply, &QNetworkReply::finished, manager, [=]() {
        // Read HTTP status code
        int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        QByteArray responseBody = reply->readAll();

        // Handle response
        if (reply->error() == QNetworkReply::NoError && statusCode == 201) {
            qDebug() << "SMS sent successfully. Response:" << responseBody;
        } else {
            qDebug() << "Failed to send SMS. HTTP status:" << statusCode;
            qDebug() << "Error:" << reply->errorString();
            qDebug() << "Response:" << responseBody;
        }

        // Cleanup
        reply->deleteLater();
        manager->deleteLater();
    });
}

