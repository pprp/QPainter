#ifndef VERECTANGLESETTINGS_H
#define VERECTANGLESETTINGS_H

#include <QWidget>

class VERectangle;

namespace Ui {
class VERectangleSettings;
}

class VERectangleSettings : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor color_1 READ color_1 WRITE setColor_1 NOTIFY color_1Changed)
    Q_PROPERTY(QColor color_2 READ color_2 WRITE setColor_2 NOTIFY color_2Changed)
    Q_PROPERTY(QColor borderColor READ borderColor WRITE setBorderColor NOTIFY borderColorChanged)
    Q_PROPERTY(int borderWidth READ borderWidth WRITE setBorderWidth NOTIFY borderWidthChanged)

public:
    explicit VERectangleSettings(QWidget *parent = 0);
    ~VERectangleSettings();

    QColor color_1() const;
    QColor color_2() const;
    QColor borderColor() const;
    int borderWidth() const;

public slots:
    void setColor_1(const QColor &color);
    void setColor_2(const QColor &color);
    void setBorderColor(const QColor &color);
    void setBorderWidth(const int &width);

signals:
    void color_1Changed(const QColor &color);
    void color_2Changed(const QColor &color);
    void borderColorChanged(const QColor &color);
    void borderWidthChanged(const int &width);

private:
    Ui::VERectangleSettings *ui;
    VERectangle *currentRectangle;

public slots:
    void newRectangle(VERectangle *rect);
    void loadRectangle(VERectangle *rect);
    void deselect();
    void setVisible(bool visible) override;

private slots:
    void comboBoxIndexChanged(int index);

private:
    void setGradient(VERectangle *rectangle);

private:
    QColor m_color_1;
    QColor m_color_2;
    QColor m_borderColor;
    int m_borderWidth;
};

#endif // VERECTANGLESETTINGS_H
