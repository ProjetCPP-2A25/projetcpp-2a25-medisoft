#include "mailer.h"
#include <QtNetwork>
#include <QDebug>
#include <QSslSocket>
#include <QFile>
#include <QTextStream>

mailer::mailer() {}



int mailer::sendEmail(const QString& recipientEmail, const QString& subject, const QString& body) {
    qDebug() << "Starting email sending process...";

    // SMTP server information
    QString smtpServer = "smtp.gmail.com";
    int smtpPort = 465;  // SMTP over SSL
    QString username = "labidiyassine1920@gmail.com";  // Replace with your Gmail username
    QString password = "uisq vgdw lagj wcgx";         // Replace with your app-specific password

    // Sender information (could be dynamic based on the input)
    QString from = username;  // From: Use your Gmail address or you can pass a custom sender email from the UI

    // Create a TCP socket for secure communication
    QSslSocket socket;

    // Connect to the SMTP server securely
    socket.connectToHostEncrypted(smtpServer, smtpPort);
    if (!socket.waitForConnected()) {
        qDebug() << "Error: Failed to connect to the server -" << socket.errorString();
        return -1;
    }
    qDebug() << "Connected to SMTP server.";

    // Wait for server's greeting
    if (!socket.waitForReadyRead()) {
        qDebug() << "Error: No response after connecting -" << socket.errorString();
        return -1;
    }
    qDebug() << "Server Response (Greeting):" << socket.readAll();

    // Send the HELO command (hello to the server)
    socket.write("HELO localhost\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Error: Failed during HELO command -" << socket.errorString();
        return -1;
    }
    qDebug() << "Server Response (HELO):" << socket.readAll();

    // Authenticate using LOGIN
    socket.write("AUTH LOGIN\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Error: Failed during AUTH LOGIN -" << socket.errorString();
        return -1;
    }
    qDebug() << "Server Response (AUTH LOGIN):" << socket.readAll();

    // Send the base64 encoded username
    socket.write(QByteArray().append(username.toUtf8()).toBase64() + "\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Error: Failed during username transmission -" << socket.errorString();
        return -1;
    }
    qDebug() << "Server Response (Username):" << socket.readAll();

    // Send the base64 encoded password
    socket.write(QByteArray().append(password.toUtf8()).toBase64() + "\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Error: Failed during password transmission -" << socket.errorString();
        return -1;
    }
    qDebug() << "Server Response (Password):" << socket.readAll();

    // Send the MAIL FROM command (sender's email)
    socket.write("MAIL FROM:<" + from.toUtf8() + ">\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Error: Failed during MAIL FROM -" << socket.errorString();
        return -1;
    }
    qDebug() << "Server Response (MAIL FROM):" << socket.readAll();

    // Send the RCPT TO command (recipient's email)
    socket.write("RCPT TO:<" + recipientEmail.toUtf8() + ">\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Error: Failed during RCPT TO -" << socket.errorString();
        return -1;
    }
    qDebug() << "Server Response (RCPT TO):" << socket.readAll();

    // Send the DATA command (to begin the email body)
    socket.write("DATA\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Error: Failed during DATA -" << socket.errorString();
        return -1;
    }
    qDebug() << "Server Response (DATA):" << socket.readAll();

    // Send the email headers and body
    //socket.write("From: <" + from.toUtf8() + ">\r\n");
    socket.write("From: SmartPharm <smartpharm@gmail.com>\r\n");

    socket.write("To: <" + recipientEmail.toUtf8() + ">\r\n");
    socket.write("Subject: " + subject.toUtf8() + "\r\n");
    socket.write("MIME-Version: 1.0\r\n");
    socket.write("Content-Type: text/plain; charset=\"UTF-8\"\r\n");
    socket.write("\r\n");  // Empty line to separate headers from the body
    socket.write(body.toUtf8() + "\r\n.\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Error: Failed during email content transmission -" << socket.errorString();
        return -1;
    }
    qDebug() << "Server Response (Email Content):" << socket.readAll();

    // Send the QUIT command to close the session
    socket.write("QUIT\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Error: Failed during QUIT -" << socket.errorString();
        return -1;
    }
    qDebug() << "Server Response (QUIT):" << socket.readAll();

    // Close the socket
    socket.close();
    qDebug() << "Email sent successfully. Connection closed.";
    return 0;
}




