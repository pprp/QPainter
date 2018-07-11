#include "handle.h"
#include <QPainter>

Handle::Handle(QPointF pos,int size ,HandleShape shape ,HandleType type) : mPos(pos),mType(type) ,mShape(shape),mSize(size)
{
    this->mRect.setRect(pos.x()-size/2,pos.y()-size/2,size,size);
}
QRectF Handle::boundingRect() const {
    return mRect;
}
void Handle::setShape(HandleShape shape) {
    this->mShape = shape;
}
void Handle::setType(HandleType type) {
    this->mType = type;
}
Handle::HandleType Handle::type() {
    return this->mType;
}
Handle::HandleShape Handle::shape() {
    return this->mShape;
}
void Handle::setSize(int size) {
    this->mSize = size;
}
int Handle::size() {
    return this->mSize;
}
void Handle::setPos(QPointF pos) {
    this->mRect.setRect(pos.x()-mSize/2,pos.y()-mSize/2,mSize,mSize);
    this->mPos = pos;
}
QPointF Handle::pos() {
    return this->mPos;
}
