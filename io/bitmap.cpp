//
// bitmap.cpp
//
// handle MS bitmap I/O. For portability, we don't use the data structure defined in Windows.h
//

#include "bitmap.h"
 
#include <cstdio>
#include <cstring>

using namespace std;

#define BMP_BI_RGB        0L

typedef unsigned short BMP_WORD; 
typedef unsigned int BMP_DWORD; 
typedef int BMP_LONG; 
 
#pragma pack(push)
// word-aligned structure, so that the following two
// structures will have the sizes we expect.
#pragma pack(2) 

typedef struct { 
	BMP_WORD        bfType; 
	BMP_DWORD       bfSize; 
	BMP_WORD        bfReserved1; 
	BMP_WORD        bfReserved2; 
	BMP_DWORD       bfOffBits; 
} BMP_BITMAPFILEHEADER; 
 
typedef struct { 
	BMP_DWORD       biSize; 
	BMP_LONG        biWidth; 
	BMP_LONG        biHeight; 
	BMP_WORD        biPlanes; 
	BMP_WORD        biBitCount; 
	BMP_DWORD       biCompression; 
	BMP_DWORD       biSizeImage; 
	BMP_LONG        biXPelsPerMeter; 
	BMP_LONG        biYPelsPerMeter; 
	BMP_DWORD       biClrUsed; 
	BMP_DWORD       biClrImportant; 
} BMP_BITMAPINFOHEADER; 

#pragma pack(pop)

BMP_BITMAPFILEHEADER bmfh; 
BMP_BITMAPINFOHEADER bmih; 

unsigned char* readBMP(const char *szFileName, int& iWidth, int& iHeight)
{ 
	FILE* pfBMPFile;
	BMP_DWORD dwPos;
	unsigned char *pbyData = NULL; 
 
	do {
		if ((pfBMPFile = fopen(szFileName, "rb")) == NULL)
			break; 

		fread(&bmfh, sizeof(BMP_BITMAPFILEHEADER), 1, pfBMPFile);

		dwPos = bmfh.bfOffBits; 
 
		fread(&bmih, sizeof(BMP_BITMAPINFOHEADER), 1, pfBMPFile); 
 
		// error checking
		if (bmfh.bfType!= 0x4d42) {	// "BM" actually
			break;
		}
		if (bmih.biBitCount != 24)  
			break;
		/*
 		if (bmih.biCompression != BMP_BI_RGB) {
			return NULL;
		}
		*/
		fseek(pfBMPFile, dwPos, SEEK_SET); 
 
		iWidth = bmih.biWidth; 
		iHeight = bmih.biHeight; 
 
		int iPadWidth = iWidth * 3; 
		int iPad = 0; 
		if (iPadWidth % 4 != 0) { 
			iPad = 4 - (iPadWidth % 4); 
			iPadWidth += iPad; 
		} 
		int iBytes = iHeight * iPadWidth; 
 
		pbyData = new unsigned char[iBytes]; 

		int iBytesRead = fread(pbyData, iBytes, 1, pfBMPFile); 
		
		if (!iBytesRead) {
			delete [] pbyData;
			pbyData = NULL;
			break;
		}

		// shuffle bitmap data such that it is (R,G,B) tuples in row-major order
		// also get away with the padding
		int i, j;
		j = 0;
		unsigned char byTemp;
		unsigned char* pbyIn;
		unsigned char* pbyOut;

		pbyIn = pbyData;
		pbyOut = pbyData;

		for (j = 0; j < iHeight; ++j) {
			for (i = 0; i < iWidth; ++i) {
				pbyOut[1] = pbyIn[1];
				byTemp = pbyIn[2];
				pbyOut[2] = pbyIn[0];
				pbyOut[0] = byTemp;

				pbyIn += 3;
				pbyOut += 3;
			}
			pbyIn += iPad;
		}
	} while (false);

	if (pfBMPFile)
		fclose(pfBMPFile);

	return pbyData; 
} 
 
bool writeBMP(const char* szFileName, int iWidth, int iHeight, const unsigned char* pbyData) 
{ 
	int iBytes, iPad;
	iBytes = iWidth * 3;
	iPad = (iBytes % 4) ? 4 - (iBytes % 4) : 0;
	iBytes += iPad;
	iBytes *= iHeight;

	bmfh.bfType = 0x4d42; // "BM"
	bmfh.bfSize = sizeof(BMP_BITMAPFILEHEADER) + sizeof(BMP_BITMAPINFOHEADER) + iBytes;
	bmfh.bfReserved1 = 0;
	bmfh.bfReserved2 = 0;
	bmfh.bfOffBits = sizeof(BMP_BITMAPFILEHEADER) + sizeof(BMP_BITMAPINFOHEADER);

	bmih.biSize = sizeof(BMP_BITMAPINFOHEADER);
	bmih.biWidth = iWidth;
	bmih.biHeight = iHeight;
	bmih.biPlanes = 1;
	bmih.biBitCount = 24;
	bmih.biCompression = BMP_BI_RGB;
	bmih.biSizeImage = 0;
	bmih.biXPelsPerMeter = (int)(100 / 2.54 * 72);
	bmih.biYPelsPerMeter = (int)(100 / 2.54 * 72);
	bmih.biClrUsed = 0;
	bmih.biClrImportant = 0;

	FILE* pfBMPFile = fopen(szFileName, "wb");

	if (pfBMPFile) {
		fwrite(&bmfh, sizeof(BMP_BITMAPFILEHEADER), 1, pfBMPFile);
		fwrite(&bmih, sizeof(BMP_BITMAPINFOHEADER), 1, pfBMPFile); 

		iBytes /= iHeight;
		unsigned char* pbyScanLine = new unsigned char[iBytes];
		for (int j = 0; j < iHeight; ++j) {
			memcpy(pbyScanLine, pbyData + j * 3 * iWidth, iBytes);
			for (int i = 0; i < iWidth; ++i) {
				unsigned char byTemp = pbyScanLine[i * 3];
				pbyScanLine[i * 3] = pbyScanLine[i * 3 + 2];
				pbyScanLine[i * 3 + 2] = byTemp;
			}
			fwrite(pbyScanLine, iBytes, 1, pfBMPFile);
		}

		delete [] pbyScanLine;
		fclose(pfBMPFile);
		return true;
	}

	return false;
} 
