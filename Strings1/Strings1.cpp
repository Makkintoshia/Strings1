#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>

using namespace std;


 int main()
{
    // создание входного потока и открытие файла
    ifstream fin("D:\\textin.txt", ios::in);
    if (!fin)
    {
        cout << "Can't open input file" << endl;
        return 1;
    }
    fin.seekg(0, ios::end);
    long len = fin.tellg();
    char *buf = new char[len + 1];
    char *buffer = new char[len + 1];
    char *word = new char[len + 1];


    // неформатированное чтение текстового файла

    fin.seekg(0, ios::beg); //указатель в начало файла
    fin.read(buf, len); //скопировать len символов из fin в буфер
    buf[len] = '\0'; //поместить в буфер нуль-литеру

   

    long n = 0;
    long i = 0;
    long j = 0;
    long m = 0;
    long cnt = 0;

    cout << "Write word";
    cin >> word;

    while (buf[i])
    {
        if (buf[i] == '?' || (buf[i]) == '!' || (buf[i]) == '.')
        {
            for (j = n, m = 0;j <= i;j++, m++)
            {
                buffer[m] = buf[j];
            }
            buffer[m] = '\0';
            if (strstr(buffer, word))
            {
                cnt++;
                    cout << buffer;
            }
            n = i + 1;
        }
        i++;
    }
    cout << endl;
    if(0==cnt)
    {
        cout << "Not find sentenses";
    }
   


}


