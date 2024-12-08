#ifndef EMAIL_H
#define EMAIL_H

#include <QString>
#include <QSslSocket>

class mailerr {
public:
    mailer();
    int sendEmail(QString dist, QString obj, QString bdy);

private:
    void sendCommand(QSslSocket &socket, const QString &cmd);
    QString encodeBase64(const QString &text);
    QString wrapText(const QString &text);  // wrapText is a non-static method
};

#endif // EMAIL_H
