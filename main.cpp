#include <QCoreApplication>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QNetworkAccessManager manager;
    QNetworkRequest request(QUrl("https://postman-echo.com/get"));
    QNetworkReply* reply = manager.get(request);

    //reply->waitForReadyRead(1000);

    QEventLoop loop;
    a.connect(reply,&QNetworkReply::finished,&loop,&QEventLoop::quit);
    loop.exec();

    qInfo() << reply->readAll();

    return a.exec();
}
