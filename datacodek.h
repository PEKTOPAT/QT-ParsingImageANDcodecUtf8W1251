//******************************************************************************
#ifndef DATACODEK_H
#define DATACODEK_H
//******************************************************************************
#include <QByteArray>
#include <QHash>
#include <QVector>
//******************************************************************************
class DataCodek
{
  public:
    DataCodek();
  private:
    QByteArray myTestMassiv;
    QByteArray massivOut_W1251;
    QByteArray massivOut_UTF8;
    QVector <QString> dataControlStringUTF8;
    QHash <QString, int> dataControlHashUTF8;

    static QByteArray encode_UTFtoWIN(QByteArray dataIn);
    static QByteArray encode_WINtoUTF(QByteArray data);
};

#endif // DATACODEK_H
