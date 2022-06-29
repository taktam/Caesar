#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColor>
#include <QMap>
#include <QValidator>
#include <private/qstringiterator_p.h>
#include <QString>
#include <QRegularExpressionValidator>
#include <iterator>
#include <abc.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_lineEdit_input_textEdited(const QString &arg1);
    void on_spinBox_valueChanged(int arg1);
    void on_modeButton_clicked();

private:
    Ui::MainWindow *ui;
    QMap <QString, int> abc;
    QString filteredText;
    QString textFilter(QString);
    QString result;
    int offset;
};
#endif // MAINWINDOW_H
