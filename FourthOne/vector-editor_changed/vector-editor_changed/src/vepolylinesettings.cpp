#include "vepolylinesettings.h"
#include "ui_vepolylinesettings.h"
#include <QColorDialog>
#include <QBrush>
#include <QPen>
#include <QDebug>
#include "vepolyline.h"

VEPolyLineSettings::VEPolyLineSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VELineSettings),
    currentPolyline(nullptr)
{
    ui->setupUi(this);
    setLineColor(QColor(Qt::black));
    setLineWidth(1);

    connect(ui->lineColor, &ColorLabel::clicked,
            [=](){
        QColorDialog dialog;
        connect(&dialog, &QColorDialog::colorSelected, this, &VEPolyLineSettings::setLineColor);
        dialog.exec();
    });

    connect(ui->lineWidth, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            this, &VEPolyLineSettings::setLineWidth);
}

VEPolyLineSettings::~VEPolyLineSettings()
{
    delete ui;
    delete currentPolyline;
}

QColor VEPolyLineSettings::lineColor() const
{
    return m_lineColor;
}

int VEPolyLineSettings::lineWidth() const
{
    return m_lineWidth;
}

void VEPolyLineSettings::setLineColor(const QColor &color)
{
    m_lineColor = color;
    ui->lineColor->setColor(m_lineColor);
    if(currentPolyline != nullptr){
        QPen pen(color,currentPolyline->pen().width());
        currentPolyline->setPen(pen);
    }
    emit lineColorChanged(m_lineColor);
}

void VEPolyLineSettings::setLineWidth(const int &width)
{
    m_lineWidth = width;
    ui->lineWidth->setValue(m_lineWidth);
    if(currentPolyline != nullptr){
        QPen pen(currentPolyline->pen().color(),width);
        currentPolyline->setPen(pen);
    }
    emit lineWidthChanged(m_lineWidth);
}

void VEPolyLineSettings::newPolyline(VEPolyline *polyline)
{
    polyline->setBrush(QBrush(Qt::transparent));
    polyline->setPen(QPen(m_lineColor, m_lineWidth));
}

void VEPolyLineSettings::loadPolyline(VEPolyline *polyline)
{
    currentPolyline = polyline;
    m_lineColor = currentPolyline->pen().color();
    m_lineWidth = currentPolyline->pen().width();
    ui->lineColor->setColor(m_lineColor);
    ui->lineWidth->setValue(m_lineWidth);
}

void VEPolyLineSettings::deselect()
{
    currentPolyline = nullptr;
}

void VEPolyLineSettings::setVisible(bool visible)
{
    if(!visible && currentPolyline != nullptr){
        QWidget::setVisible(true);
    } else {
        QWidget::setVisible(visible);
    }
}


