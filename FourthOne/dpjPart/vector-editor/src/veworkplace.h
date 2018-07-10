#ifndef WORKPLACE_H
#define WORKPLACE_H

#include <QObject>
#include <QGraphicsScene>
#include "vetextitem.h"
#include "dubezier.h"
class QGraphicsSceneMouseEvent;
class QKeyEvent;
class DuBezier;

class VEWorkplace : public QGraphicsScene
{
    Q_OBJECT

    Q_PROPERTY(int currentAction READ currentAction WRITE setCurrentAction NOTIFY currentActionChanged)
    Q_PROPERTY(QPointF previousPosition READ previousPosition WRITE setPreviousPosition NOTIFY previousPositionChanged)

public:
    explicit VEWorkplace(QObject *parent = 0);
    ~VEWorkplace();

    enum ActionTypes {
        DefaultType,
        LineType,
        RectangleType,
        EllipseType,
        SelectionType
    };

    int currentAction() const;
    QPointF previousPosition() const;

    void setCurrentAction(const int type);
    void setPreviousPosition(const QPointF previousPosition);

    void setChooseBezier(bool on);
    void setChooseLine(bool on);
    bool getBezier()const {return chooseBezier;}
    bool getLine()const {return chooseLine;}

signals:
    void previousPositionChanged();
    void currentActionChanged(int);
    void signalSelectItem(QGraphicsItem *item);
    void signalNewSelectItem(QGraphicsItem *item);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void deselectItems();

public slots:
    void slotMove(QGraphicsItem *signalOwner, qreal dx, qreal dy);

private:
    QGraphicsItem *currentItem;
    int m_currentAction;
    int m_previousAction;
    QPointF m_previousPosition;
    bool m_leftMouseButtonPressed;
    VETextItem * vti;
    //画贝塞尔曲线
    bool pressFirst;
    bool pressSecond;
    bool chooseBezier;
    bool chooseLine;//是否需要加上

    //点的确定
    QPointF mpto1;//第一个点
    QPointF mpto2;//第二个点
    QList<DuBezier*> mCurva;
};

#endif // WORKPLACE_H
