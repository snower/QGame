#ifndef GMOVERRUNNABLE_H
#define GMOVERRUNNABLE_H

#include <QThread>

class GMover;

class GMoverRunnable : public QThread
{
    Q_OBJECT
public:
    explicit GMoverRunnable(GMover *parent,bool autoRun=true);
    void Msleep(int m);
    void Sleep(int s);

private:
    void run();

signals:

public slots:

private:
    GMover* parent;
};

#endif // GMOVERRUNNABLE_H
