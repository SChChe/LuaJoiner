#include "joiner.h"

#include <QFile>
#include <QFileInfo>
#include <QIODevice>

namespace jns
{
    bool Joiner::fileExists(QString filePath)
    {
        return QFileInfo::exists(filePath) && QFileInfo(filePath).isFile();
    }

    QByteArray Joiner::getFileData(QString filePath)
    {
        if (filePath.contains(".lua") && fileExists(filePath))
        {
            QFile fileObj(filePath);
            if (fileObj.open(QIODevice::ReadOnly))
            {
                QByteArray fileData = fileObj.readAll();
                fileObj.close();
                return fileData;
            }
        }
        return {};
    }

    QString Joiner::getArrayAsHexString(QByteArray rawArray)
    {
        QByteArray hexArray = rawArray.toHex();
        QString hexString = "";

        for (int i = 0; i < hexArray.length() - 1; i += 2)
        {
            hexString += "\\x" + QString("%1%2").arg(hexArray.at(i)).arg(hexArray.at(i + 1));
        }

        return hexString;
    }

    bool Joiner::joinFiles()
    {
        QString firstFileDataHex = getArrayAsHexString(firstFileData);
        QString secondFileDataHex = getArrayAsHexString(secondFileData);

        QFile fileObj("joined.lua");

        if (!firstFileDataHex.isEmpty() && !secondFileDataHex.isEmpty() && fileObj.open(QIODevice::WriteOnly))
        {
            fileObj.write(("load(\"" + firstFileDataHex + "\")()\n").toUtf8());
            fileObj.write(("load(\"" + secondFileDataHex + "\")()").toUtf8());

            fileObj.close();

            return true;
        }
        return false;
    }
}; // namespace jns

