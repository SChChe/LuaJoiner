#ifndef JOINER_H
#define JOINER_H

#include <QString>
#include <QByteArray>

namespace jns
{
    class Joiner
    {
    public:
        Joiner() = default;
        ~Joiner() = default;

        bool fileExists(QString filePath);
        bool joinFiles();
        QByteArray getFileData(QString filePath);
        QString getArrayAsHexString(QByteArray rawArray);

        QByteArray getFirstFileData() const {return firstFileData;};
        QByteArray getSecondFileData() const {return secondFileData;};

        void setFirstFileData(QByteArray firstFileData) {this->firstFileData = firstFileData;};
        void setSecondFileData(QByteArray secondFileData) {this->secondFileData = secondFileData;};

    private:
        QByteArray firstFileData = {};
        QByteArray secondFileData = {};
    };
} // namespace jns

#endif // JOINER_H
