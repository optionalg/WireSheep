#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkDiskCache>
#include "fireflock.h"

Fireflock::Fireflock(QNetworkDiskCache* netcache, QObject* parent)
    : QObject(parent), m_cache(netcache)
{
    /*  We want to share a cache with the web browser,
        in case it has some images we want: */
    m_network = new QNetworkAccessManager(this);
    m_network->setCache(m_cache);
}

Fireflock::~Fireflock()
{
}

void Fireflock::startCapture()
{
	QString data = QString("my packet");
	onPacket(data);
}

void Fireflock::stopCapture()
{
}

void Fireflock::onPacket(QString data)
{
    emit handlePacket(data);
}