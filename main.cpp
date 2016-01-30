#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdlib.h>
#include <fstream>

#define PI 3.14159265
#define FPS 30

using namespace cv;
using namespace std;

 int main( int argc, char** argv )
{
    int type = 1;//img
    Mat imgOriginal;
    VideoCapture cap(argv[1]); // try capture the video

    Mat input, image, dst;
    input.create(240,320,CV_8UC(3));


    if(argc >= 2)
    { 
      type = 2; //video
    }
    else
    {
        imgOriginal = imread(argv[1], CV_LOAD_IMAGE_UNCHANGED);
    }

    int run = atoi(argv[2]);

    int i =1;
    while (true)
    {
      
        int k = waitKey(FPS);
        //cout<<k<<endl;
        if (type == 2 && i == 1)
        {

            bool bSuccess = cap.read(imgOriginal); // read a new frame from video
            if (!bSuccess) //if not success, break loop
            {
                break;
            }
            i = 2;
        }

        /////////////////////////////////////////////////////////////////////
        ////                      logic start here                    ///////
        /////////////////////////////////////////////////////////////////////
        image = imgOriginal;

        resize(image,input, input.size(), 0, 0, INTER_NEAREST);
        imshow("original",input);
        


        imshow("final",frgb);

        ///////////////////////////////////////////
        ////            till here                //
        ///////////////////////////////////////////
        if ( k == 27|| k == 1048603 ) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
        {
            cout << "esc key is pressed by user" << endl;
            break; 
        }
        else if ( k == 110 || k == 1048686 )
        {
            cout << "nxt frame" << endl;
            i=1;
        }
        
    }

   return 0;

}

