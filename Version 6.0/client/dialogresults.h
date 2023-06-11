#ifndef DIALOGRESULTS_H
#define DIALOGRESULTS_H

#include <QDialog>

namespace Ui {
class DialogResults;
}

/*!
\brief Класс окна вывода статистики для учителя
*/

class DialogResults : public QDialog
{
    Q_OBJECT

public:
    explicit DialogResults(QWidget *parent = nullptr);
    ~DialogResults();

public slots:

    /// слот открытия окна
    void onOpen();

    /// слот: данные статистики роишли с сервера
    void onStatInput(QString stat);

private:
    Ui::DialogResults *ui;
};

#endif // DIALOGRESULTS_H
