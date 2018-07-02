#ifndef WINDOW_H
#define WINDOW_H


#include<QWidget>
#include"renderarea.h"
#include<QtWidgets>
#include<QComboBox>

#include<QSpinBox>
#include<QLabel>
#include<QCheckBox>
#include<QGridLayout>
#include<QConicalGradient>

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = 0);
    ~Window();

signals:

private slots:


    void shapeChanged();
    void penChanged();
    void brushChanged();


private:

RenderArea *renderArea;
QComboBox *shapeComboBox;
QLabel *shapeLabel;
QSpinBox *penWidthSpinBox;
QLabel *penWidthLabel;
QComboBox *penStyleComboBox;
QLabel *penStyleLabel;
QComboBox *penCapComboBox;
QLabel *penCapLabel;
QComboBox *penJoinComboBox;
QLabel *penJoinLabel;
QComboBox *brushStyleComboBox;
QLabel *brushStyleLabel;
QLabel *otherOptionsLabel;
QCheckBox *antialiasingCheckBox;
QCheckBox *transformationsCheckBox;

};

#endif // WINDOW_H
