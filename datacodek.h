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
    static QByteArray encode_UTFtoWIN(QByteArray dataIn);
    static QByteArray encode_WINtoUTF(QByteArray dataIn);

  private:
    static const unsigned char dataControlByteWin1251[256];
    static const QVector<QString> dataControlStringUTF8;
};

#endif // DATACODEK_H
