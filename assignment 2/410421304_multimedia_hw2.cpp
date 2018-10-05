#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

//initial part
const int freq = 400;
const double Fs = 8000; //sampler rate
const int sec = 5;
const int channel = 1;
const int bit = 16;
const int amp = 32767; //16 bit: 32767~-32768
const int buff = sec*Fs*channel;
const double D = 1;

template<typename Type> void write(ofstream& out, const Type& sting)
{
    out.write((const char*)&sting, sizeof(Type));
}

int main(int argc, char** argv)
{
    //input part
    char notes[1000]; // music note in char form
    char singlenote;

    ifstream imnotes;
    imnotes.open("music note.txt");

    int counter = 0;
    double metre =0;

    if(imnotes.is_open())
    {
        while(!imnotes.eof())
        {
            if(metre == 0)
            {
                imnotes>>metre;
            }
            else
            {
                imnotes>>singlenote;
                notes[counter] = singlenote;
                counter = counter+1;
            }
        }
    }


    //process with input notes

    counter = 0;
    int counter2 = 0;
    int intnotes[1000]; //array to set notes in decimal form

    while(counter!=1000)
    {
        if((notes[counter] >= 48) && (notes[counter] <= 57))
        {
            intnotes[counter2] = notes[counter] - 48;
            counter2++;
        }
        counter++;
    }

    int counter3 = 0;

    double level2[1000];
    double level5[1000];

    while(counter3 < (counter2-1))
    {
        if(intnotes[counter3] == 0)
        {
            level2[counter3] = 1;
            level5[counter3] = 1;
        }
        else if(intnotes[counter3] == 1)
        {
            level2[counter3] = 65;
            level5[counter3] = 523;
        }
        else if(intnotes[counter3] == 2)
        {
            level2[counter3] = 73;
            level5[counter3] = 587;
        }
        else if(intnotes[counter3] == 3)
        {
            level2[counter3] = 82;
            level5[counter3] = 659;
        }
        else if(intnotes[counter3] == 4)
        {
            level2[counter3] = 87;
            level5[counter3] = 699;
        }
        else if(intnotes[counter3] == 5)
        {
            level2[counter3] = 98;
            level5[counter3] = 784;
        }
        else if(intnotes[counter3] == 6)
        {
            level2[counter3] = 110;
            level5[counter3] = 880;
        }
        else if(intnotes[counter3] == 7)
        {
            level2[counter3] = 124;
            level5[counter3] = 988;
        }
        counter3++;
    }

    //wav format setting
    ofstream out;
    out.open("normalmerge.wav", ios::binary);

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

    //for part2 f = 100
    ofstream out100;
    out100.open("cosf100.wav", ios::binary);

    out100.write("RIFF", 4);
    write<int>(out100, 36 + (buff*sizeof(signed short)));
    out100.write("WAVEfmt ", 8);
    write<int>(out100, 16);
    write<short>(out100, 1);
    write<unsigned short>(out100, channel);
    write<int>(out100, Fs);
    write<int>(out100, Fs*channel*sizeof(signed short));
    write<short>(out100, channel*sizeof(signed short));
    write<short>(out100, sizeof(signed short)*8);
    out100.write("data", 4);
    write<int>(out100, buff*sizeof(signed short));

    //for part2 f = 500
    ofstream out500;
    out500.open("cosf500.wav", ios::binary);

    out500.write("RIFF", 4);
    write<int>(out500, 36 + (buff*sizeof(signed short)));
    out500.write("WAVEfmt ", 8);
    write<int>(out500, 16);
    write<short>(out500, 1);
    write<unsigned short>(out500, channel);
    write<int>(out500, Fs);
    write<int>(out500, Fs*channel*sizeof(signed short));
    write<short>(out500, channel*sizeof(signed short));
    write<short>(out500, sizeof(signed short)*8);
    out500.write("data", 4);
    write<int>(out500, buff*sizeof(signed short));

    //for part2 f = 800
    ofstream out800;
    out800.open("cosf800.wav", ios::binary);

    out800.write("RIFF", 4);
    write<int>(out800, 36 + (buff*sizeof(signed short)));
    out800.write("WAVEfmt ", 8);
    write<int>(out800, 16);
    write<short>(out800, 1);
    write<unsigned short>(out800, channel);
    write<int>(out800, Fs);
    write<int>(out800, Fs*channel*sizeof(signed short));
    write<short>(out800, channel*sizeof(signed short));
    write<short>(out800, sizeof(signed short)*8);
    out800.write("data", 4);
    write<int>(out800, buff*sizeof(signed short));


    //arithmetic part

    //for mix
    short siz[buff];
    //for levels
    short siz2[buff];
    short siz5[buff];

    memset(siz, 0 , buff*2); //set memory space for siz


    int i = 0;
    counter = 0;
    double doublecounter = 0;

    for(i=0; i<buff; i++)
    {
        double checker = (i/Fs);
        if(checker < 1)
        siz2[i] = sin((2 * 3.14)* 1 * i / Fs )*amp;
        else
        {
            siz2[i] = sin((2 * 3.14)* level5[counter] * i / Fs )*amp; // formula in pdf
            doublecounter+=(1/Fs);
            if(doublecounter >= metre)
            {
                counter+=1;
                doublecounter=0;
            }
        }
    }

    counter = 0;
    doublecounter = 0;

    for(i=0; i<buff; i++)
    {
        double checker = (i/Fs);
        if((sec-checker) <= 1)
        siz5[i] = sin((2 * 3.14)* 1 * i / Fs )*amp;
        else
        {
            siz5[i] = sin((2 * 3.14)* level2[counter] * i / Fs )*amp; // formula in pdf
            doublecounter+=(1/Fs);
            if(doublecounter >= metre)
            {
                counter+=1;
                doublecounter=0;
            }
        }
    }

    //output part
    counter = 0;

    for(int i=0; i<buff; i++)
    {
        siz[i] = (int)(0.5*siz2[i] + 0.5*siz5[i]);

        if(siz[i] > 32767)
            siz[i] = 32767;
        else if(siz[i] < -32768)
            siz[i] = -32768;
    }

    out.write((const char*)&siz[0], buff*2);

    //100 test
    for(int i=0; i<buff; i++)
    {
        siz[i] = (int)(0.5*siz2[i]*cos((2 * 3.14)* 100 * i / Fs ) + 0.5*siz5[i]*cos((2 * 3.14)* 100 * i / Fs ));

        if(siz[i] > 32767)
            siz[i] = 32767;
        else if(siz[i] < -32768)
            siz[i] = -32768;
    }

    out100.write((const char*)&siz[0], buff*2);

    //500 test
    for(int i=0; i<buff; i++)
    {
        siz[i] = (int)(0.5*siz2[i]*cos((2 * 3.14)* 500 * i / Fs ) + 0.5*siz5[i]*cos((2 * 3.14)* 500 * i / Fs ));

        if(siz[i] > 32767)
            siz[i] = 32767;
        else if(siz[i] < -32768)
            siz[i] = -32768;
    }

    out500.write((const char*)&siz[0], buff*2);

    //800 test
    for(int i=0; i<buff; i++)
    {
        siz[i] = (int)(0.5*siz2[i]*cos((2 * 3.14)* 800 * i / Fs ) + 0.5*siz5[i]*cos((2 * 3.14)* 800 * i / Fs ));

        if(siz[i] > 32767)
            siz[i] = 32767;
        else if(siz[i] < -32768)
            siz[i] = -32768;
    }

    out800.write((const char*)&siz[0], buff*2);

    cout<<"Output complete.";

    out.close();
    return 0;
}
