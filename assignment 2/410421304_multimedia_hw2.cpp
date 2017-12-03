#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <cmath>

using namespace std;

const int freq = 400;
const int Fs = 8000; //sampler rate
const int sec = 4;
const int channel = 1;
const int bit = 16;
const int amp = 32767; //16 bit: 32767~-32768
const int buff = sec*Fs*channel;

template<typename Type> void write(ofstream& out, const Type& sting)
{
	out.write((const char*)&sting, sizeof(Type));
}

int main(int argc, char** argv)
{
    char notes[1000];

    ifstream imnotes;
    imnotes.open("music note.txt");

    if(imnotes.is_open())
    {
        while(!imnotes.eof())
        {
            imnotes>>notes;
            cout<<notes;
        }
    }

    cout<<"\n";


    ofstream out;
    out.open("sintest.wav", ios::binary);

    out.write("RIFF", 4);
    write<int>(out, 36 + (buff*sizeof(signed short)));
    out.write("WAVEfmt ", 8);
    write<int>(out, 16);
    write<short>(out, 1);
    write<unsigned short>(out, channel);
    write<int>(out, Fs);
    write<int>(out, Fs*channel*sizeof(signed short));
    write<short>(out, channel*sizeof(signed short));
    write<short>(out, sizeof(signed short)*8);
    out.write("data", 4);
    write<int>(out, buff*sizeof(signed short));

    short siz[buff];
    memset(siz, 0 , buff*2); //set memory space for siz

    /*

    for (int i = 0; i < buff/4; i++)
    {
        siz[i] = sin((2 * 3.14)* freq * i / Fs )*amp; // formula in pdf
    }

    */

    //test

    for (int i = 0; i < buff/4; i++)
    {
        siz[i] = sin((2 * 3.14)* 98 * i / Fs )*amp; // formula in pdf
    }

    for (int i = buff/4; i < buff/2; i++)
    {
        siz[i] = sin((2 * 3.14)* 82 * i / Fs )*amp; // formula in pdf
    }

    for (int i = buff/2; i < (buff/2+buff/4); i++)
    {
        siz[i] = sin((2 * 3.14)* 98 * i / Fs )*amp; // formula in pdf
    }

    for (int i = (buff/2+buff/4); i < buff; i++)
    {
        siz[i] = sin((2 * 3.14)* 82 * i / Fs )*amp; // formula in pdf
    }


    out.write((const char*)&siz[0], buff*2);

    out.close();
    return 0;
}
