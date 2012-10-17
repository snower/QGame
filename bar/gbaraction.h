#ifndef GBARACTION_H
#define GBARACTION_H

#include "../element/gitem.h"

class GBar;

class GBarAction : public GItem
{
    Q_OBJECT
public:
    explicit GBarAction(GBar *bar,int x,int y,int width,int height,int interval);
    explicit GBarAction(GBar *bar,int x,int y,int width,int height,int interval,QString string);

    GBar* GetBar();

    virtual void Triggered();
    virtual void Paint(QPainter *painter);
    void SetString(QString string);

protected:
    void Init();

    virtual void mouseReleaseEvent(GMouseEvent* event );
    virtual void mouseMoveEvent(GMouseEvent* event );
    virtual void mousePressEvent(GMouseEvent *event);
    virtual void PaintBackGround(QPainter *painter);
    virtual void PaintForeGround(QPainter *painter);
    virtual void PaintSelect(QPainter *painter);

public slots:
    void UpdateString(QString string);

signals:

public:
    QString string;
    QColor color;
    QColor bgColor;
    QFont font;
    int interval;
    bool isSelect;
    bool selected;
    int xRadius;
    int yRadius;

protected:
    QPoint pressPoint;
    GBar *bar;
};

#endif // GBARACTION_H
