#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <cmath>

using namespace std;

const int freq = 400;
const int Fs = 8000; //sampler rate
const int sec = 17;
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
    char notes[1000]; // music note in char form
    char singlenote;

    ifstream imnotes;
    imnotes.open("music note.txt");

    int counter = 0;

    if(imnotes.is_open())
    {
        while(!imnotes.eof())
        {
            imnotes>>singlenote;
            notes[counter] = singlenote;
            counter = counter+1;
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
            level2[counter3] = 124;
            level5[counter3] = 988;
        }
        counter3++;
    }


    //end of process

    //input wav format

    ofstream out;
    out.open("levelmixtest.wav", ios::binary);

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

    //end of process format

    //output

    //for mix
    short siz[buff];
    //for lvls
    short siz2[buff];
    short siz5[buff];

    memset(siz, 0 , buff*2); //set memory space for siz

    /*

    for (int i = 0; i < buff; i++)
    {
        siz[i] = sin((2 * 3.14)* freq * i / Fs )*amp; // formula in pdf
    }

    */

    double adder = 0.0558;
    //cout << adder << "f";
    counter = 1;
    while(counter != 17)
    {
        int i=0;
        for(i=((counter-1)*adder)*buff; i<(counter*adder)*buff; i++)
        {
            double checker = ((counter+1)*adder);
            if(checker > 1)
            siz2[i] = sin((2 * 3.14)* 1 * i / Fs )*amp;
            else
            siz2[i] = sin((2 * 3.14)* level2[counter-1] * i / Fs )*amp; // formula in pdf
        }
        counter++;
    }

    //out.write((const char*)&siz[0], buff*2);

    counter = 1;

    while(counter != 17)
    {
        int i=0;
        for(i=((counter-1)*adder)*buff; i<(counter*adder)*buff; i++)
        {
            double checker = ((counter-1)*adder);
            if(checker == 0)
            siz5[i] = sin((2 * 3.14)* 1 * i / Fs )*amp;
            else
            siz5[i] = sin((2 * 3.14)* level5[counter-2] * i / Fs )*amp; // formula in pdf
        }
        counter++;
    }

    counter = 0;

    for(int i=0; i<buff; i++)
    {
        siz[i] = (int)(0.5*siz2[i] + 0.5*siz5[i]);

        if(siz[i] > 32767)
            siz[i] = 32767;
        else if(siz[i] < -32768)
            siz[i] = -32768;
    }

    /*
    for(int i=0; i<buff; i++)
    {
        siz[i] = (int)siz2[i];

        if(siz[i] > 32767)
            siz[i] = 32767;
        else if(siz[i] < -32768)
            siz[i] = -32768;
    }
    */



    out.write((const char*)&siz[0], buff*2);

    cout<<"level mix test output complete.";

    out.close();
    return 0;
}
