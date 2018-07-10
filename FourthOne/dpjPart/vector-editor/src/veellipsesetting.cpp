#include "veellipsesetting.h"
#include "ui_veellipsesettings.h"
#include <QColorDialog>
#include <QBrush>
#include <QPen>
#include <QDebug>
#include "veellipse.h"

VEEllipseSettings::VEEllipseSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VEEllipseSettings),
    currentEllipse(nullptr)
{
    ui->setupUi(this);
    ui->color_2->setVisible(false);
    ui->labelColor_2->setVisible(false);

    setColor_1(Qt::white);
    setColor_2(Qt::white);
    setBorderColor(Qt::black);
    setBorderWidth(1);

    connect(ui->color_1, &ColorLabel::clicked,
            [=](){
        QColorDialog dialog;
        connect(&dialog, &QColorDialog::colorSelected, this, &VEEllipseSettings::setColor_1);
        dialog.exec();
    });
    connect(ui->color_2, &ColorLabel::clicked,
            [=](){
        QColorDialog dialog;
        connect(&dialog, &QColorDialog::colorSelected, this, &VEEllipseSettings::setColor_2);
        dialog.exec();
    });
    connect(ui->borderColor, &ColorLabel::clicked,
            [=](){
        QColorDialog dialog;
        connect(&dialog, &QColorDialog::colorSelected, this, &VEEllipseSettings::setBorderColor);
        dialog.exec();
    });

    connect(ui->comboBox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &VEEllipseSettings::comboBoxIndexChanged);
    connect(ui->borderWidth, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            this, &VEEllipseSettings::setBorderWidth);
}

VEEllipseSettings::~VEEllipseSettings()
{
    delete ui;
    delete currentEllipse;
}

QColor VEEllipseSettings::color_1() const
{
    return m_color_1;
}

QColor VEEllipseSettings::color_2() const
{
    return m_color_2;
}

QColor VEEllipseSettings::borderColor() const
{
    return m_borderColor;
}

int VEEllipseSettings::borderWidth() const
{
    return m_borderWidth;
}

void VEEllipseSettings::setColor_1(const QColor &color)
{
    m_color_1 = color;
    ui->color_1->setColor(color);
    if(currentEllipse != nullptr){
        if(ui->comboBox->currentIndex() == 0){
            currentEllipse->setBrush(QBrush(m_color_1));
        } else {
             setGradient(currentEllipse);
        }
    }
    emit color_1Changed(m_color_1);
}

void VEEllipseSettings::setColor_2(const QColor &color)
{
    m_color_2 = color;
    ui->color_2->setColor(color);
    if(currentEllipse != nullptr){
         setGradient(currentEllipse);
    }
    emit color_2Changed(m_color_2);
}

void VEEllipseSettings::setBorderColor(const QColor &color)
{
    m_borderColor = color;
    ui->borderColor->setColor(color);
    if(currentEllipse != nullptr){
        QPen pen(color,currentEllipse->pen().width());
        currentEllipse->setPen(pen);
    }
    emit borderColorChanged(m_borderColor);
}

void VEEllipseSettings::setBorderWidth(const int &width)
{
    m_borderWidth = width;
    if(currentEllipse != nullptr){
        if(width == 0){
            currentEllipse->setPen(Qt::NoPen);
        } else {
            QPen pen(currentEllipse->pen().color(), width);
            currentEllipse->setPen(pen);
        }
    }
    emit borderWidthChanged(m_borderWidth);
}

void VEEllipseSettings::newEllipse(VEEllipse *elli)
{
    if(ui->comboBox->currentIndex() == 0){
        elli->setBrush(QBrush(m_color_1));
    } else {
        setGradient(elli);
    }
    if(m_borderWidth == 0){
        elli->setPen(Qt::NoPen);
    } else {
        elli->setPen(QPen(m_borderColor, m_borderWidth));
    }
}

void VEEllipseSettings::loadEllipse(VEEllipse *elli)
{
    currentEllipse = elli;

    m_color_1 = currentEllipse->brush().color();
    m_borderColor = currentEllipse->pen().color();
    if(currentEllipse->pen().style() == Qt::NoPen){
        m_borderWidth = 0;
    } else {
        m_borderWidth = currentEllipse->pen().width();
    }
    ui->color_1->setColor(m_color_1);
    ui->borderColor->setColor(m_borderColor);
    ui->borderWidth->setValue(m_borderWidth);
}

void VEEllipseSettings::deselect()
{
    currentEllipse = nullptr;
}

void VEEllipseSettings::setVisible(bool visible)
{
    if(!visible && currentEllipse != nullptr){
        QWidget::setVisible(true);
    } else {
        QWidget::setVisible(visible);
    }
}

void VEEllipseSettings::comboBoxIndexChanged(int index)
{
    switch (index) {
    case 1:
        ui->color_2->setVisible(true);
        ui->labelColor_2->setVisible(true);
        ui->labelColor_1->setText(trUtf8("color 1"));
        if(currentEllipse != nullptr){
            setGradient(currentEllipse);
        }
        break;
    default:
        ui->color_2->setVisible(false);
        ui->labelColor_2->setVisible(false);
        ui->labelColor_1->setText(trUtf8("background"));
        if(currentEllipse != nullptr){
            currentEllipse->setBrush(QBrush(m_color_1));
        }
        break;
    }
}

void VEEllipseSettings::setGradient(VEEllipse *ellipse)
{
    auto tmpRect = ellipse->rect();
    QLinearGradient gradient(tmpRect.left() + tmpRect.width()/2,
                             tmpRect.top(),
                             tmpRect.left() + tmpRect.width()/2,
                             tmpRect.bottom());
    gradient.setColorAt(0.0, m_color_1);
    gradient.setColorAt(1.0, m_color_2);
    ellipse->setBrush(QBrush(gradient));
}
