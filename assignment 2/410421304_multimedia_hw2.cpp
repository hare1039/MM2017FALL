#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

const int freq = 400;
const int Fs = 8000; //sampler rate
const int sec = 1;
const int channel = 1;
const int bit = 16;
const int amp = 32767; //16 bit: 32767~-32768
const int buff = sec*Fs*channel;

int main(int argc, char** argv)
{
    ofstream out;
    out.open("sintest.wav", ios::binary);

    int siz[buff];
    memset(siz, 0 , buff*4); //set memory space for siz

    out.close();
    return 0;
}
