#ifndef IO_STRING_H
#define IO_STRING_H

#include <stdio.h>
#include <fstream>

int saveString(std::string& str, std::ofstream* fout)
{
    if(fout == NULL)
    {
        printf("File Stream error. NULL was passed as argument.\n");
        return -1;
    }

    long size = str.size() +1;

    fout->write((char*) &size, sizeof(long));
    fout->write(str.c_str(), size);


    return 0;
}
int saveString(std::string& str, std::fstream* fio)
{
    if(fio == NULL)
    {
        printf("File Stream error. NULL was passed as argument.\n");
        return -1;
    }

    long size = str.size() +1;

    fio->write((char*) &size, sizeof(long));
    fio->write(str.c_str(), size);


    return 0;
}

int loadString(std::string& str, std::ifstream* fin)
{
    if(fin == NULL)
    {
        printf("File Stream error. NULL was passed as argument.\n");
        return -1;
    }

    long size = 0;

    fin->read((char*) &size, sizeof(long));
    if(size > 0)
    {
        char* buffer = new char[size];
        //buffer[size] = '\0';
        fin->read(buffer, size);
        str.assign(buffer);
        delete[] buffer;
    }
    else
    {
        str = "";
    }

    return 0;
}
int loadString(std::string& str, std::fstream* fio)
{
    if(fio == NULL)
    {
        printf("File Stream error. NULL was passed as argument.\n");
        return -1;
    }

    long size = 0;

    fio->read((char*) &size, sizeof(long));
    if(size > 0)
    {
        char* buffer = new char[size];
        //buffer[size] = '\0';
        fio->read(buffer, size);
        str.assign(buffer);
        delete[] buffer;
    }
    else
    {
        str = "";
    }

    return 0;
}

#endif // SAVE_STRING_H
