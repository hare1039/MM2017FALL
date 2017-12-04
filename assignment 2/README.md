# Mutimedia Assignment 2

# Report and Discussion
About the format:
* Example:

  0.6

  5 3 3 0 4 2 2 0

  1 2 3 4 5 5 2 1

The first input is use as the **metre** in the program, which represent how much time each music note will take.
In the given exampl it would be 0.6. And the music note were transfer to decimal in following format:
C = 1 D = 2 E = 3 F = 4 G = 5 A = 6 B = 7. Rest note would be 0.
By this order, we could know that the example is song "little bee" with a slight modified.
When the total time exceed the space wav file had been given, it would stop recording.
 
Flowchart:
![pic]( https://user-images.githubusercontent.com/33059129/33530090-ff2e9ce6-d8b4-11e7-988f-140c44e02b4e.PNG "flow chart")
About how my program works, it was made up with serveral parts:
* First part is initial part. The values such as Fs, frquncy, sec, etc. With all these values here, we could easliy make
  change or modified the program just by do change in here.
* Second part is the input part. Contain with code dealing with input datas and change them into the information we want, such as 
  change music notes into frequncy.
* Third part is the wav file setting parts. In here, we set up the required format for the wav files we are going to generate
  by the values we had initial from 1st part. This part include the function we define above.
* 4th part is the arithmeitc part. What we do is following the formula we had been given from the pdf and rules to create the 
  required data for wav file by using the frequncies from part 2 and values from part 1.
* The last part is the output part. Use the data we had get from 4th part to put int the wav file we had set up in part3, then
  its all done!
   
How to run my program:

Its simple! What you need to do is simply set up your music note in music note.txt, run the 410421304_multimedia_hw2.exe for execute
or run .cpp by compiler, then the result of normal merge would be normalmerge.wav, modulation with f=100 would be cosf100.wav, with
f=500 would be cosf500.wav, and f=800 would be cosf800.wav. And thats all of the requied results!

Result display:
* Normal Merge :
![pic]( https://user-images.githubusercontent.com/33059129/33530100-3c3c059c-d8b5-11e7-9166-5a388a56c4b3.PNG "normal merge")
 
 We can see that two wave merge to one.
 
 * Modulation f = 100
![pic]( https://user-images.githubusercontent.com/33059129/33530120-5e92b3b6-d8b5-11e7-9248-cc6e74d42e5e.PNG "100")
* Modulation f = 500
![pic]( https://user-images.githubusercontent.com/33059129/33530126-7daafb32-d8b5-11e7-96b2-65b3cee715b4.PNG "500")
* Modulation f = 800
![pic]( https://user-images.githubusercontent.com/33059129/33530128-8bfb5254-d8b5-11e7-8430-aee6737f4946.PNG "800")

It seems to be some frequncy change before and after modulation, but after modulation it seems to be at same frequncy on f change.


Problem facing:

Countless problem face in making this program, just list some important parts.
Of course, the first thing is to set up the wav file format. Without using library, I decide to do this by myself. But there are a
lot of things to set in wav file, so I trying to set up program with simple sin wave first. At first, the file even not generate. Then
it generate, but the file was crashed, due to the wrong formating. Check through numerous page taliking about wav file and countless of
try hards, finally it was done. Mostly done by try and error.

At by this build-up settings, something that I did not notice and accept by the system but actually wrong finally would be solve during the run-through test outputs, although some problem was finally been found and some thing was finally been notice at the very end of this programing. A lot of things is "learned" by program error, such as how to set up the type "correctly" to make program correct--not only for the single launch up.

That is the main problem, other than that the second important thing is how to merge 2 programs. I found someone said just "add them up", so I simply add them up, and result with head-blowing noise. Then I know it should be "add them by rates".

Input file is a small thing, though I nearly forget this basic, so take some time re-study this basic.

And also some small but annoying problem, such as output always level2 or level5 sound, then I need to walk back to check where is wrong; program cannot wrong with propriate header; or even the compiler setting...

Its good thing they all be conquired by try hards.

Result discussion:

* As the result display above and the wav file we got:
  * Level intefere the frequncy's hi-lo, low level low and high level high.
  * Not nuch thing to talk about merging. Just simply set up the time delay for each level. Basso(low) part come out first, so it
    may discard some part at the end; on the contrary, alto(high) part would abandon same amount from the begining.
  * The modulation part, by the result we could found that with greater frequncy, the sound would become more sharp and thick, and
    the frequncy of the result surely change by add this modified.

What I have learn:

I learn a lot of things from this assignment. Such as how to set up wav files for generates sounds; how to input files; how to use 
sin/cos formula with header cmath; file stream with type aside text; how to generate song with simple music notes; how to change the
pitch tone between levles; and how to merge two wav file into one.

Aside hard or not, this assignment really torture to hear those "wrong" and noisy sound for hours though.

Talking about some feeling during and after the programing. It have so much little troubles intefere me to complete this assignment.
I was doing type correction really often thanks to wrong set up at the begining. By all these I keep asking some "small" question to
my former classmate, like "Why my double won't show float value?" and reason is simple:int delete int. And I make this mistake twice.
Type correction, I set up buffer by interger at the begining. It then change to double, change back to int, to float, till I finally
realize it was not a short for no reason, then it finally been set up as short. But the thing is that I also gain some knowledge and
found some interesting plot inside this, such as by changeing type, the actual output voice would also be different, and some settings must be change either; or some wrong buff size would change the length of the voice; finally realize I actually output a level 5 instead of level 2 until I start to merging them, even some basic things like 8bit=1byte, I knew that, but when I finally understand why all these settings are 2, 4, 8... it was like when Archimedes shouting out "Eureka!" though I did not really found something important, but thats something imporatnt to those someone who had some hard time in programing, this may be a small but important push to make them keep going. Although it have hard time, but spring always come after winter, and it will be all well paid for this.


*Readding, coding, debugging. This is what I had done this program, by this circulation.*
  
