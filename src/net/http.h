#ifndef HTTPS_H
#define HTTPS_H

#include<QString>
#include<QObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>

class http : public QObject
{

Q_OBJECT

public:
    explicit http( QNetworkAccessManager *parent = NULL);
    ~http();

    int SendHttpsRequest( QString url  , int useSSL , QByteArray postBody );

    QByteArray getReplyData()
    {
        return replyContent;
    };

    // single
    static http* GetInstance();

signals:

public slots:

    void downloadProgress(qint64 bytesSent, qint64 bytesTotal);
    void finished();

    void onError(QNetworkReply::NetworkError errorCode);

private :
    QNetworkAccessManager   *m_pManager;
    QByteArray              replyContent ;
    int                     nErro ; // 0 --OK , 1  -- ERRO

};

#endif // HTTPS_H
