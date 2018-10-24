#include "bitfile.h"

BitFile::BitFile()
{
}

BitFile::BitFile(string fileName)
{
	file.setFileName(QString::fromStdString(fileName));
}

void BitFile::flush()
{
    file.open(QIODevice::WriteOnly);
	if(!file.isOpen())
        qWarning() << "File couldn't open!";

	// Add indent
    byte indent = bitVec.size() % BYTE_BIT_COUNT;
	if(indent != 0)
	{
        for(int mBit = indent; mBit < BYTE_BIT_COUNT; mBit++)
		{
            bitVec.push_back(false);
		}
	}

    cout << "Bit vec:" << endl;
    for(bool mBit: bitVec) {
        cout << mBit << endl;
    }

	// Flush
    for(size_t mBytePartId = 0; mBytePartId < bitVec.size() / BYTE_BIT_COUNT; mBytePartId++)
	{
		int mByteId = mBytePartId * BYTE_BIT_COUNT;

		// Read byte
		byte mByte = 0;
        for(size_t mByteBitId = 0; mByteBitId < BYTE_BIT_COUNT; mByteBitId++)
		{
			mByte <<= 1;
			mByte |= (bitVec.at(mByteId + mByteBitId)
					  ? 1
					  : 0);
		}

		// Write byte
		file.putChar(mByte);
	}

	file.flush();
    file.close();
}

void BitFile::addBitVec(QVector<bool> bitVec)
{
    for(bool mBool: bitVec) {
        this->bitVec.push_back(mBool);
    }
}
