#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>

class QMouseEvent;

class ColorLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ColorLabel(QWidget *parent = 0);
    ~ColorLabel();

protected:
    void mousePressEvent(QMouseEvent *event);

signals:
    void clicked();

public slots:
    void setColor(const QColor &color);
};

#endif // CLICKABLELABEL_H
