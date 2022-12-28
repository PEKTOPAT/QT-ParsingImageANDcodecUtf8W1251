#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColor>
#include <QLabel>
#include <QFile>



//const unsigned char dataControlByteWin1251[] =
//{
//    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, //0..15]
//    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
//    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
//    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
//    0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
//    0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,
//    0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
//    0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F, //..127]
//    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F,
//    0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F,
//    0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF,
//    0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF,
//    0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF,
//    0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0XDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF,
//    0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF,
//    0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF
//};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{   
//    dataControlStringUTF8 << "\x00" <<   "\x01" <<  "\x02" <<  "\x03" <<  "\x04" <<  "\x05" <<  "\x06" <<  "\x07" <<  "\x08" <<  "\x09" <<  "\x0A" <<  "\x0B" <<  "\x0C" <<  "\x0D" <<  "\x0E" <<  "\x0F"
//                          << "\x10" <<   "\x11" <<  "\x12" <<  "\x13" <<  "\x14" <<  "\x15" <<  "\x16" <<  "\x17" <<  "\x18" <<  "\x19" <<  "\x1A" <<  "\x1B" <<  "\x1C" <<  "\x1D" <<  "\x1E" <<  "\x1F"
//                          << "\x20" <<   "\x21" <<  "\x22" <<  "\x23" <<  "\x24" <<  "\x25" <<  "\x26" <<  "\x27" <<  "\x28" <<  "\x29" <<  "\x2A" <<  "\x2B" <<  "\x2C" <<  "\x2D" <<  "\x2E" <<  "\x2F"
//                          << "\x30" <<   "\x31" <<  "\x32" <<  "\x33" <<  "\x34" <<  "\x35" <<  "\x36" <<  "\x37" <<  "\x38" <<  "\x39" <<  "\x3A" <<  "\x3B" <<  "\x3C" <<  "\x3D" <<  "\x3E" <<  "\x3F"
//                          << "\x40" <<   "\x41" <<  "\x42" <<  "\x43" <<  "\x44" <<  "\x45" <<  "\x46" <<  "\x47" <<  "\x48" <<  "\x49" <<  "\x4A" <<  "\x4B" <<  "\x4C" <<  "\x4D" <<  "\x4E" <<  "\x4F"
//                          << "\x50" <<   "\x51" <<  "\x52" <<  "\x53" <<  "\x54" <<  "\x55" <<  "\x56" <<  "\x57" <<  "\x58" <<  "\x59" <<  "\x5A" <<  "\x5B" <<  "\x5C" <<  "\x5D" <<  "\x5E" <<  "\x5F"
//                          << "\x60" <<   "\x61" <<  "\x62" <<  "\x63" <<  "\x64" <<  "\x65" <<  "\x66" <<  "\x67" <<  "\x68" <<  "\x69" <<  "\x6A" <<  "\x6B" <<  "\x6C" <<  "\x6D" <<  "\x6E" <<  "\x6F"
//                          << "\x70" <<   "\x71" <<  "\x72" <<  "\x73" <<  "\x74" <<  "\x75" <<  "\x76" <<  "\x77" <<  "\x78" <<  "\x79" <<  "\x7A" <<  "\x7B" <<  "\x7C" <<  "\x7D" <<  "\x7E" <<  "\x7F"  //..127]
//                          << "\xD0\x82"     <<  "\xD0\x83"     <<      "\xE2\x80\x9A" <<      "\xD1\x93"     <<      "\xE2\x80\x9E" <<      "\xE2\x80\xA6" <<      "\xE2\x80\xA0"
//                          << "\xE2\x80\xA1" <<  "\xE2\x82\xAC" <<      "\xE2\x80\xB0" <<      "\xD0\x89"     <<      "\xE2\x80\xB9" <<      "\xD0\x8A"     <<      "\xD0\x8C"
//                          << "\xD0\x8B"     <<  "\xD0\x8F"     <<      "\xD1\x92"     <<      "\xE2\x80\x98" <<      "\xE2\x80\x99" <<      "\xE2\x80\x9C" <<      "\xE2\x80\x9D"
//                          << "\xE2\x80\xA2" <<  "\xE2\x80\x93" <<      "\xE2\x80\x94" <<      "null"         <<      "\xE2\x84\xA2" <<      "\xD1\x99"     <<      "\xE2\x80\xBA"
//                          << "\xD1\x9A"     <<  "\xD1\x9C"     <<      "\xD1\x9B"     <<      "\xD1\x9F"     <<      "0xA0"         <<      "\xD0\x8E"     <<      "\xD1\x9E"
//                          << "\xD0\x88"     <<  "\xC2\xA4"     <<      "\xD2\x90"     <<      "\xC2\xA6"     <<      "\xC2\xA7"     <<      "\xD0\x81"     <<      "\xC2\xA9" <<      "\xD0\x84"
//                          << "\xC2\xAB"     <<  "\xC2\xAC"     <<      "\xE2\x80\x93" <<      "\xC2\xAE"     <<      "\xD0\x87"     <<      "\xC2\xB0"     <<      "\xC2\xB1" <<      "\xD0\x86" <<  "\xD1\x96" <<  "\xD2\x91"  //...180]
//                          << "\xC2\xB5"     <<  "\xC2\xB6"     <<      "\xC2\xB7"     <<      "\xD1\x91"     <<      "\xE2\x84\x96" <<      "\xD1\x94"     <<      "\xC2\xBB" <<      "\xD1\x98" <<  "\xD0\x85" <<  "\xD1\x95" //...190]
//                          << "\xD1\x97"     <<  "\xD0\x90"     <<      "\xD0\x91"     <<      "\xD0\x92"     <<      "\xD0\x93"     <<      "\xD0\x94"     <<      "\xD0\x95" <<      "\xD0\x96" <<  "\xD0\x97" <<  "\xD0\x98" //...200]
//                          << "\xD0\x99"     <<  "\xD0\x9A"     <<      "\xD0\x9B"     <<      "\xD0\x9C"     <<      "\xD0\x9D"     <<      "\xD0\x9E"     <<      "\xD0\x9F" <<      "\xD0\xA0" <<  "\xD0\xA1" <<  "\xD0\xA2" <<  "\xD0\xA3"
//                          << "\xD0\xA4"     <<  "\xD0\xA5"     <<      "\xD0\xA6"     <<      "\xD0\xA7"     <<      "\xD0\xA8"     <<      "\xD0\xA9"     <<      "\xD0\xAA" <<      "\xD0\xAB" <<  "\xD0\xAC" <<  "\xD0\xAD" <<  "\xD0\xAE"
//                          << "\xD0\xAF"     <<  "\xD0\xB0"     <<      "\xD0\xB1"     <<      "\xD0\xB2"     <<      "\xD0\xB3"     <<      "\xD0\xB4"     <<      "\xD0\xB5" <<      "\xD0\xB6" <<  "\xD0\xB7" <<  "\xD0\xB8" <<  "\xD0\xB9"
//                          << "\xD0\xBA"     <<  "\xD0\xBB"     <<      "\xD0\xBC"     <<      "\xD0\xBD"     <<      "\xD0\xBE"     <<      "\xD0\xBF"     <<      "\xD1\x80" <<      "\xD1\x81" <<  "\xD1\x82" <<  "\xD1\x83" <<  "\xD1\x84"
//                          << "\xD1\x85"     <<  "\xD1\x86"     <<      "\xD1\x87"     <<      "\xD1\x88"     <<      "\xD1\x89"     <<      "\xD1\x8A"     <<      "\xD1\x8B" <<      "\xD1\x8C" <<  "\xD1\x8D" <<  "\xD1\x8E" <<  "\xD1\x8F"; //...255]
    NameFile = "dataWindows2.txt";


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
    memset(massiv, 0, fullSize);
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
            if(MyColor.red() < 253)
            {
                if(ui->comboBox->currentIndex() != 1) massiv[fullWidthImage * j + prefix + i/8] |= 1 << (i%8);
                else massiv[fullWidthImage * j + prefix + i/8] |= 1 << (7 - (i%8));
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
//*************************************************************
//*************************************************************
//*************************************************************
//*************************************************************
//QByteArray MainWindow::encode_UTFtoWIN(QByteArray data)
//{
//    massivOut_W1251.clear();
//    QString dataStr = data;
//    for(int i = 0; i < dataControlStringUTF8.size(); i++)
//    {
//        quint8 ind = dataControlByteWin1251[i];
//        dataControlHashUTF8[dataControlStringUTF8[i]] = ind;
//    }
//    for(int i = 0; i < dataStr.size(); i++)
//    {
//        massivOut_W1251.append(dataControlHashUTF8[dataStr.at(i)]);
//    }
//    return massivOut_W1251;
//}
//*************************************************************
//QByteArray MainWindow::encode_WINtoUTF(QByteArray data)
//{
//    massivOut_UTF8.clear();
//    for(int i = 0; i < data.size(); i++)
//    {
//        quint8 ind = data[i];
//        massivOut_UTF8.append(dataControlStringUTF8[ind]);
//    }
//    return massivOut_UTF8;
//}
//*************************************************************
void MainWindow::on_pushButton_2_ReadFile_clicked()
{
    ui->label_3->setStyleSheet("QLabel {color : blue; }");
    ui->label_4->setStyleSheet("QLabel {color : blue; }");
    myTestMassiv.clear();
    QFile myFile(NameFile);
    if(myFile.exists())
    {
        if(myFile.isOpen())
        {

        }else
        {
            myFile.open(QIODevice::ReadOnly);
            myTestMassiv = myFile.readAll();
            //qDebug() << myTestMassiv;
            ui->lineEdit->setText(QString(myTestMassiv));
        }
    } else qDebug() << "File not found!!!";
}
//*************************************************************
void MainWindow::on_pushButton_Translate_clicked()
{
    ui->lineEdit_2->clear();
    if(myTestMassiv.size() != 0)
    {
        if(ui->label_3->text() == "W1251")
        {
            //encode_WINtoUTF(myTestMassiv);
            ui->lineEdit_2->setText(DataCodek::encode_WINtoUTF(myTestMassiv));
        }
        else
        {
            ui->lineEdit_2->setText(DataCodek::encode_UTFtoWIN(myTestMassiv));
        }
    }else qDebug() << "Massiv is empty!";

}
//*************************************************************
void MainWindow::on_pushButton_SwitchCode_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    if(ui->label_3->text() == "W1251")
    {
        ui->label_3->setText("UTF8");
        ui->label_4->setText("W1251");
        NameFile = "dataWindows.txt";
    }else
    {
        ui->label_3->setText("W1251");
        ui->label_4->setText("UTF8");
        NameFile = "dataWindows2.txt";
    }

}
//*************************************************************
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lineEdit_editingFinished()
{
//    if(ui->label_3->text() == "W1251")
//    {
//        myTestMassiv = ui->lineEdit->text().toLocal8Bit();
//        qDebug() << myTestMassiv;
//    }else
//    {
//        myTestMassiv = ui->lineEdit->text().toUtf8();
//    }
}
