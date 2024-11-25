#include "email.h"
#include <QtNetwork>
#include <QDebug>
#include <QTextStream>
#include <QTextCodec>

mailer::mailer() {
    // Constructor logic if needed
}

int mailer::sendEmail(QString dist, QString obj, QString bdy) {
    qDebug() << "sslLibraryBuildVersionString: " << QSslSocket::sslLibraryBuildVersionString();
    qDebug() << "sslLibraryVersionNumber: " << QSslSocket::sslLibraryVersionNumber();
    qDebug() << "supportsSsl: " << QSslSocket::supportsSsl();
    qDebug() << QCoreApplication::libraryPaths();

    // SMTP server information
    QString smtpServer = "smtp.gmail.com";
    int smtpPort = 465;  // Gmail's SSL port
    QString username = "sourour.sethom@esprit.tn";
    QString password = "inwi xkfp suym mlpr"; // Ensure that this is stored securely

    // Sender and recipient information
    QString from = "sourour.sethom@esprit.tn";
    QString to = dist;
    QString subject = obj;

    // Create a TCP socket
    QSslSocket socket;

    // Connect to the SMTP server
    socket.connectToHostEncrypted(smtpServer, smtpPort);
    if (!socket.waitForConnected()) {
        qDebug() << "Error connecting to the server:" << socket.errorString();
        return -1;
    }

    // Wait for the greeting from the server
    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    qDebug() << "Connected to the server.";

    // Send the HELO command
    socket.write("HELO localhost\r\n");
    socket.waitForBytesWritten();
    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    // Send the authentication information
    socket.write("AUTH LOGIN\r\n");
    socket.waitForBytesWritten();
    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    // Send the username (Base64 encoded)
    socket.write(QByteArray().append(username.toUtf8()).toBase64() + "\r\n");
    socket.waitForBytesWritten();
    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    // Send the password (Base64 encoded)
    socket.write(QByteArray().append(password.toUtf8()).toBase64() + "\r\n");
    socket.waitForBytesWritten();
    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    // Send the MAIL FROM command
    socket.write("MAIL FROM:<" + from.toUtf8() + ">\r\n");
    socket.waitForBytesWritten();
    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    // Send the RCPT TO command
    socket.write("RCPT TO:<" + to.toUtf8() + ">\r\n");
    socket.waitForBytesWritten();
    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    // Send the DATA command to start the email body
    socket.write("DATA\r\n");
    socket.waitForBytesWritten();
    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    // Start composing the email content
    QString body = wrapText(bdy); // Wrap the body text to fit within 78 characters per line
    QString mimeType = "text/plain; charset=UTF-8";  // MIME type for plain text email

    // Send the email headers and body
    socket.write("From: " + from.toUtf8() + "\r\n");
    socket.write("To: " + to.toUtf8() + "\r\n");
    socket.write("Subject: " + subject.toUtf8() + "\r\n");
    socket.write("Content-Type: " + mimeType.toUtf8() + "\r\n");
    socket.write("\r\n");  // Empty line before the body
    socket.write(body.toUtf8() + "\r\n");
    socket.write(".\r\n");  // End of email content
    socket.waitForBytesWritten();

    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    // Send the QUIT command
    socket.write("QUIT\r\n");
    socket.waitForBytesWritten();
    if (!socket.waitForReadyRead()) {
        qDebug() << "Error reading from server:" << socket.errorString();
        return -1;
    }

    qDebug() << "Email sent successfully.";

    // Close the socket
    socket.close();

    return 0;
}

QString mailer::wrapText(const QString &text) {
    QString textCopy = text;  // Create a copy of the original string
    QTextStream stream(&textCopy);  // Use a mutable string for QTextStream
    stream.setCodec(QTextCodec::codecForName("UTF-8"));
    QString wrappedText;

    while (!stream.atEnd()) {
        wrappedText.append(stream.readLine(78) + "\r\n");
    }
    return wrappedText;
}
