#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QImage>
#include <QDebug>
#include <QFile>
#include <QHash>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QImage myImage;
    unsigned char *massiv;


    QString NameFile;
    //*********************
    QByteArray myTestMassiv;
    QByteArray massiv_W1251;
    QByteArray massiv_UTF8;
    QVector <QString> dataStringUTF8;
    QHash <QString, int> hash;
private slots:
    void encode_UTFtoWIN(QByteArray data);
    QByteArray encode_WINtoUTF(QByteArray data);
    void on_pushButton_2_ReadFile_clicked();
    void on_pushButton_Translate_clicked();
    void on_pushButton_SwitchCode_clicked();
};

#endif // MAINWINDOW_H
