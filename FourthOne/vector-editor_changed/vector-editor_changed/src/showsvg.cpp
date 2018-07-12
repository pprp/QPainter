#include "showsvg.h"


ShowSvg::ShowSvg(QWidget *parent) : QSvgWidget(parent)
{
    // 获得本窗体的QSvgRenderer对象
    render = renderer();
}

void ShowSvg::wheelEvent(QWheelEvent *event)
{
    // 表示每次滚轮滚动的值，图片大小改变的比例
    const double diff = 0.1;
    // 先获取图片显示区的大小，以便进行下一步操作
    QSize size = render->defaultSize();
    int width = size.width();
    int height = size.height();

    // 滚动方向
    if (event->delta() > 0)
    {
        width = int(this->width() + this->width() * diff);
        height = int(this->height() + this->height() * diff);
    }
    else
    {
        width = int(this->width() - this->width() * diff);
        height = int(this->height() - this->height() * diff);
    }

    resize(width, height);
}
