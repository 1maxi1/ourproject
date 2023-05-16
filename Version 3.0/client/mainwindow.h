#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QMap<QString, QString> m_tasks;


public slots:
    void onOpen();
    void incomingTask(QString name, QString body);
    void slotOpenTask();

signals:
    void signalOpenTask(QString name, QString body);
};
#endif // MAINWINDOW_H
