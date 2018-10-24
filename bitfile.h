#ifndef BITFILE_H
#define BITFILE_H

#include <QFile>
#include <QDebug>
#include <QVector>

#include <iostream>
using namespace std;

#define BYTE_BIT_COUNT 8
#define INT_BIT_COUNT 32

typedef char byte;

class BitFile
{
public:
	BitFile();
	BitFile(string filePath);

	void close();

	void flush();

	// Push presets
    QVector<bool> bitVec;
    void addBitVec(QVector<bool> bitVec);

    // Push bits
    void push(long num, int count);

private:

    QFile file;
};

#endif // BITFILE_H
