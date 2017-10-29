# Mutimedia Assignment 1

Result Display
![pic]( https://user-images.githubusercontent.com/33059129/32145240-0aef582a-bd00-11e7-933d-a9eaf434a357.PNG "Test Title")

# Report and Discussion
This is the second assignment in course of multimedia(first one is create a reposity).

In the code file(.cpp), something worth notice:
* At the begining, I was trying to use Iplimage to write the program, but change to mat later.
* A bug that I did not notice until end... which is .clone() problem.

About the code:
* It seperate into serveral parts.
1. Read in file test.png and display(color)
2. Transform a duplicate mat of color inmage into gray and display(gray)
3. Transform a duplicate mat of gray image into black/white and display(L2-12), use method in 12th page of L2.pdf
4. Transform a duplicate mat of gray image into black/white and display(L2-13), use method in 13th page of L2.pdf
5. Redo step 4 by using different dither matrix(dith2) then display(L2-13(2))

Result discussion:
* As the result display above:
  * We could found that gray scale look more familiar to the original picture(just reduce to 1 channel)
  * The first approach of the transform between black/white picture and gray are apparently larger then others, since
    we use four pixels to perform 1 pixel's transform, so the size will be 4x bigger.
  * In the second approach of the transform between black/white picture and gray, since we use dither matrix as the method
    to perform the transform, it will keep the same size as the original picture does.
  * The second approach of second approach, which we change the dither matrix, could found that if we use different matrix, the result
    will be different(the picture of original matrix generated looks more propper).

