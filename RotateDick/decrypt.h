#pragma once
#include <stdio.h>
#include<Windows.h>
#include <direct.h>

void del();
void decrypt();

void decrypt()
{
    //string path = "dick\\ddick\\";
    if (GetFileAttributesA("dick\\ddick\\") != FILE_ATTRIBUTE_DIRECTORY) {
        bool flag = CreateDirectory(L"dick\\ddick\\", NULL);
    }
    else
    {
        del();
    }
    int key = 22;
    FILE* fpSrc = fopen("dick\\Edickhead.bmp", "rb");
    FILE* fpDst = fopen("dick\\ddick\\dickhead.bmp", "wb");
    while (!feof(fpSrc))
    {
        char c;
        fread(&c, 1, 1, fpSrc);
        c = c ^ key; 
        fwrite(&c, 1, 1, fpDst);
    }
    fclose(fpDst);
    fclose(fpSrc);
    fpSrc = fopen("dick\\Edickhead1.bmp", "rb");
    fpDst = fopen("dick\\ddick\\dickhead1.bmp", "wb");
    while (!feof(fpSrc))
    {
        char c;
        fread(&c, 1, 1, fpSrc);
        c = c ^ key;
        fwrite(&c, 1, 1, fpDst);
    }
    fclose(fpDst);
    fclose(fpSrc);
    fpSrc = fopen("dick\\Edickhead2.bmp", "rb");
    fpDst = fopen("dick\\ddick\\dickhead2.bmp", "wb");
    while (!feof(fpSrc))
    {
        char c;
        fread(&c, 1, 1, fpSrc);
        c = c ^ key;
        fwrite(&c, 1, 1, fpDst);
    }
    fclose(fpDst);
    fclose(fpSrc);
    fpSrc = fopen("dick\\Edickhead3.bmp", "rb");
    fpDst = fopen("dick\\ddick\\dickhead3.bmp", "wb");
    while (!feof(fpSrc))
    {
        char c;
        fread(&c, 1, 1, fpSrc);
        c = c ^ key;
        fwrite(&c, 1, 1, fpDst);

    }
    fclose(fpDst);
    fclose(fpSrc);
    fpSrc = fopen("dick\\Ebk.bmp", "rb");
    fpDst = fopen("dick\\ddick\\bk.bmp", "wb");
    while (!feof(fpSrc))
    {
        char c;
        fread(&c, 1, 1, fpSrc);
        c = c ^ key;
        fwrite(&c, 1, 1, fpDst);

    }
    fclose(fpDst);
    fclose(fpSrc);
}
void del()
{
    DeleteFile(L"dick\\ddick\\dickhead.bmp");
    DeleteFile(L"dick\\ddick\\dickhead1.bmp");
    DeleteFile(L"dick\\ddick\\dickhead2.bmp");
    DeleteFile(L"dick\\ddick\\dickhead3.bmp");
    DeleteFile(L"dick\\ddick\\bk.bmp");
}