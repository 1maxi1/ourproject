#ifndef DIALOGTASK_H
#define DIALOGTASK_H

#include <QDialog>
#include <QList>

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
    QList<int> m_listInputVector;

public slots:
    void onOpen(QString name, QString body);
    void onAnswer();
};

#endif // DIALOGTASK_H
