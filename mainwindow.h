#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QImage>
#include <QDebug>
#include <QFile>
#include <QHash>
#include <QElapsedTimer>

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

//    QElapsedTimer timeer;
//    QElapsedTimer timeer1;
//    QString NameFile;
    //*********************
//    QByteArray myTestMassiv;
//    QByteArray massivOut_W1251;
//    QByteArray massivOut_UTF8;
//    QVector <QString> dataControlStringUTF8;
//    QHash <QString, int> dataControlHashUTF8;

private slots:
//    QByteArray encode_UTFtoWIN(QByteArray dataIn);
//    QByteArray encode_WINtoUTF(QByteArray data);
    void on_pushButton_2_ReadFile_clicked();
    void on_pushButton_Translate_clicked();
    void on_pushButton_SwitchCode_clicked();
    void on_lineEdit_editingFinished();
};


#endif // MAINWINDOW_H
