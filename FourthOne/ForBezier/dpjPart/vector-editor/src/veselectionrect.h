#ifndef SELECTIONRECT_H
#define SELECTIONRECT_H

#include <QObject>
#include <QGraphicsRectItem>

class VESelectionRect : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit VESelectionRect(QObject *parent = 0);
    ~VESelectionRect();

    enum {
        Type = UserType + 1
    };
    int type() const override;

signals:

public slots:
};

#endif // SELECTIONRECT_H
