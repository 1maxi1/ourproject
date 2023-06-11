#ifndef DIALOGTASK_H
#define DIALOGTASK_H

#include <QDialog>
#include <QList>

namespace Ui {
class DialogTask;
}

/*!
\brief Класс окна решения задачи
*/

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

    /// слот на открытие окна
    void onOpen(QString name, QString body);

    /// слот - сервер дал результат по ответу
    void onAnswer();
};

#endif // DIALOGTASK_H
