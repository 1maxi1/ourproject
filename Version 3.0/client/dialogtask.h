#ifndef DIALOGTASK_H
#define DIALOGTASK_H

#include <QDialog>

namespace Ui {
class DialogTask;
}

class DialogTask : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTask(QWidget *parent = nullptr);
    ~DialogTask();

private:
    Ui::DialogTask *ui;

    QString m_taskName;
    QString m_taskBody;

public slots:
    void onOpen(QString name, QString body);
};

#endif // DIALOGTASK_H
