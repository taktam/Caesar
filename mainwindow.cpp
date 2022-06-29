#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    abc ["A"] = 0;
    abc ["B"] = 1;
    abc ["C"] = 2;
    abc ["D"] = 3;
    abc ["E"] = 4;
    abc ["F"] = 5;
    abc ["G"] = 6;
    abc ["H"] = 7;
    abc ["I"] = 8;
    abc ["J"] = 9;
    abc ["K"] = 10;
    abc ["L"] = 11;
    abc ["M"] = 12;
    abc ["N"] = 13;
    abc ["O"] = 14;
    abc ["P"] = 15;
    abc ["Q"] = 16;
    abc ["R"] = 17;
    abc ["S"] = 18;
    abc ["T"] = 19;
    abc ["U"] = 20;
    abc ["V"] = 21;
    abc ["W"] = 22;
    abc ["X"] = 23;
    abc ["Y"] = 24;
    abc ["Z"] = 25;

    ui->setupUi(this);
    setStyleSheet("background-color:#E6BA95");
    ui->lineEdit_input->setStyleSheet("background-color:#E4E9BE");
    ui->textEdit_output->setStyleSheet("background-color:#E4E9BE");
    ui->spinBox->setStyleSheet("background-color:#FAFDD6");
    ui->pushButton->setStyleSheet("background-color:#FAFDD6");
    ui->pushButton_2->setStyleSheet("background-color:#FAFDD6");
    ui->modeButton->setStyleSheet("background-color:#FAFDD6");
    QRegularExpression regXp("([A-Za-z\\s]){0,80}");
    QRegularExpressionValidator *inputVal = new QRegularExpressionValidator(regXp, this);
    ui->lineEdit_input->setValidator(inputVal);
    offset = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{ 
    ui->textEdit_output->clear();
    result.clear();
    int bin = 0;
    int translated = 0;
    QString::iterator i;
    for (i = filteredText.begin(); i != filteredText.end(); i++)
        if (*i == ' ')
            result.append(' ');
        else
        {
            bin = abc[*i];
            translated = bin + offset;
            while (translated > 25)
                translated = translated - 26;
            while (translated < 0)
                translated = translated + 26;
            result.append(abc.key(translated));
        }
    ui->textEdit_output->setText(result);
}

QString MainWindow::textFilter(QString input_string)
{
    QString output;
    QStringIterator it(input_string);
    while (it.hasNext())
    {
        output.append(it.next());
    }
    return output.toUpper();
}

void MainWindow::on_lineEdit_input_textEdited(const QString &arg1)
{
    filteredText = textFilter(arg1);
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    if (ui->modeButton->isChecked() == false)
        offset = arg1;
    else
        offset = 0-arg1;
}

void MainWindow::on_modeButton_clicked()
{
    if (ui->modeButton->isChecked() == false)
    {
        ui->modeButton->setText("Encoding");
        offset = abs(offset);
    }
    else
    {
        ui->modeButton->setText("Decoding");
        offset = 0 - abs(offset);
    }
}
