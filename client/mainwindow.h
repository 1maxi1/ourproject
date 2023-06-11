#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*!
\brief Класс главного окна

в нем 4 задачи и баллы по ним
*/

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*! Конструктор */
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QMap<QString, QString> m_tasks;


public slots:

    /// слот на открытие окна
    void onOpen();

    /// слот: пришла задача с сервера
    void incomingTask(QString name, QString body);

    /// слот: открыть задачу
    void slotOpenTask();

    /// слот: отобразить баллы по задачам
    void redrawBalls(QString body);

signals:

    /// сигнал: открытие задачи
    void signalOpenTask(QString name, QString body);

    /// сигнал: открытие статистики
    void openStat();
};
#endif // MAINWINDOW_H
