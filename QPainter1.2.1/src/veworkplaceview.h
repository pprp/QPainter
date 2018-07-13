#ifndef VEWORKPLACEVIEW_H
#define VEWORKPLACEVIEW_H

#include <QWidget>
#include <QGraphicsView>

class VEWorkplaceView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit VEWorkplaceView(QWidget *parent = 0);

protected:
    void enterEvent(QEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

signals:

public slots:
};

#endif // VEWORKPLACEVIEW_H
