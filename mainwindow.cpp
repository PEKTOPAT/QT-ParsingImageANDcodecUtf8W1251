#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColor>
#include <QLabel>
#include <QFile>
#include <QTextCodec>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    QFile file("out.txt");
    const int prefix = 14;
    const int postPrefix = 1;
    QColor MyColor;
    ui->setupUi(this);
    myImage.load("SEMZ_4.png");
    QSize sizeImage = myImage.size();
    int heigtImage = sizeImage.height();
    int widthImage_RoundUp = (sizeImage.width() + 7)/8;
    int fullWidthImage = widthImage_RoundUp + prefix + postPrefix;
    int fullSize = heigtImage * fullWidthImage;
    massiv = new unsigned char[fullSize];
    qDebug() << fullSize;
    memset(massiv, 0, fullSize);
    //QByteArray massivByte;
    ui->label->setPixmap(QPixmap::fromImage(myImage));
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {

        return;
    }


    QTextStream out(&file);

    for(int j = 0; j < heigtImage; j++)
    {
        for(int i = 0; i < sizeImage.width(); i++)
        {
            MyColor = myImage.pixel(i,j);
            if(MyColor.red() < 220)
            {
                if(ui->comboBox->currentIndex() != 1)
                {
                    massiv[fullWidthImage * j + prefix + i/8] |= 1 << (i%8);
                }
                else
                {
                    massiv[fullWidthImage * j + prefix + i/8] |= 1 << (7 - (i%8));
                }
            }
        }
    }

    for(int i = 0; i < fullSize; i++)
    {
        //out << QString("%1").arg(massiv[i]).toLocal8Bit();
        if(i % 20 == 0 && i != 0) out << "\n";
        out << QString().sprintf("0x%02X, ", massiv[i]);
    }


    ui->label_2->setPixmap(QPixmap::fromImage(myImage));
}








//*************************************************************
void MainWindow::encode_UTFtoWIN(QByteArray data)
{

}
//*************************************************************
void MainWindow::encode_WINtoUTF(QByteArray data)
{
    for(int i = 0; i < data.size(); i++)
    {

    }
}
//*************************************************************
void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit_2->setText(ui->lineEdit->text());
    if(myTestMassiv.size() != 0)
    {
        encode_WINtoUTF(myTestMassiv);
    }else qDebug() << "Massiv is empty!";

}

MainWindow::~MainWindow()
{
    delete ui;
}
//"Hello \xD0\xBC\xD0\xB8\xD1\x80!\r\n\xD0\x90\xD0\xBD\xD0\xB4\xD1\x80\xD0\xB5\xD0\xB9 here"
void MainWindow::on_pushButton_2_clicked()
{
    myTestMassiv.clear();
    QFile myFile("dataWindows.txt");
    if(myFile.exists())
    {
        if(myFile.isOpen())
        {

        }else
        {
            myFile.open(QIODevice::ReadOnly);
            myTestMassiv = myFile.readAll();
            ui->lineEdit->setText(QString(myTestMassiv));
            if(myTestMassiv[0] == 0x48) qDebug() << "УРААА";
            qDebug() << myTestMassiv;
            qDebug() << QString(0x48);
//            QTextCodec *Codec;
//            Codec->toUnicode(myTestMassiv);

        }
    } else qDebug() << "File not found!!!";


}
