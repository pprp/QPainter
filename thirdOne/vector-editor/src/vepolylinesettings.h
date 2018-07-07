#ifndef VELINESETTINGS_H
#define VELINESETTINGS_H

#include <QWidget>

class VEPolyline;

namespace Ui {
class VELineSettings;
}

class VEPolyLineSettings : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor lineColor READ lineColor WRITE setLineColor NOTIFY lineColorChanged)
    Q_PROPERTY(int lineWidth READ lineWidth WRITE setLineWidth NOTIFY lineWidthChanged)

public:
    explicit VEPolyLineSettings(QWidget *parent = 0);
    ~VEPolyLineSettings();

    QColor lineColor() const;
    int lineWidth() const;

public slots:
    void setLineColor(const QColor &color);
    void setLineWidth(const int &width);

signals:
    void lineColorChanged(const QColor &color);
    void lineWidthChanged(const int &width);

private:
    Ui::VELineSettings *ui;
    VEPolyline *currentPolyline;

public slots:
    void newPolyline(VEPolyline *polyline);
    void loadPolyline(VEPolyline *polyline);
    void deselect();
    void setVisible(bool visible);

private:
    QColor m_lineColor;
    int m_lineWidth;
};

#endif // VELINESETTINGS_H
