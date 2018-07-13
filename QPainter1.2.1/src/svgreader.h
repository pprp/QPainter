#ifndef SVGREADER_H
#define SVGREADER_H

#include <QObject>

class VERectangle;
class VEPolyline;
class QGraphicsItem;

class SvgReader : public QObject
{
    Q_OBJECT
public:
    explicit SvgReader(QObject *parent = 0);
    ~SvgReader();
    static QList<VERectangle *> getRectangles(const QString filename);
    static QList<VEPolyline *> getPolylines(const QString filename);
    static QList<QGraphicsItem *> getElements(const QString filename);
    static QRectF getSizes(const QString filename);

signals:

public slots:
};

#endif // SVGREADER_H
