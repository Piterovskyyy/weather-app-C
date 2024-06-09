#include "../headerFiles/mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(1000,667);
    w.show();

    // Tworzymy menedżera dostępu do sieci
    QNetworkAccessManager manager;

    // Tworzymy żądanie do wykonania
    QNetworkRequest request(QUrl("http://example.com"));

    // Wykonujemy żądanie i otrzymujemy odpowiedź
    QNetworkReply *reply = manager.get(request);

    // Obsługujemy odpowiedź
    QObject::connect(reply, &QNetworkReply::finished, [&]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Odczytujemy odpowiedź
            QByteArray responseData = reply->readAll();
            qDebug() << "Response:" << responseData;
        } else {
            // Obsługujemy błąd odpowiedzi
            qDebug() << "Error:" << reply->errorString();
        }

        // Usuwamy obiekt odpowiedzi
        reply->deleteLater();
    });

    return a.exec();
}
