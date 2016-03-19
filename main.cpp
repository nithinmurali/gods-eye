
/**
 * @brief:
 *
 * @TODO: local awb, use intensity to skip fallback, cluster based hist value streching
 */

#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdlib.h>
#include <fstream>
#include <string>
#include "color_constancy.hpp"


#define PI 3.14159265
#define FPS 30

using namespace cv;
using namespace std;


void balance_white1(cv::Mat &mat) 
{
  double discard_ratio = 0.012;
  int hists[3][256];

  for (int x = 0; x < 256; ++x)
    for (int j = 0; j < 3; ++j)
      hists[j][x] = 0;
  
  //creating histogram
  for (int y = 0; y < mat.rows; ++y) 
  {
    for (int x = 0; x < mat.cols; ++x)
    {
      for (int j = 0; j < 3; ++j)
        hists[j][(mat.at<Vec3b>(y,x)).val[j]] += 1;
    }
  }

  //check if you wanna strech red
  int mean=0,N=0,min=-1,bin=0,start=3;
  for (int j = 255; j > -1; --j) 
  {
      bin = hists[2][j];
      mean += bin*j;
      N += bin;
      if(min==-1 && bin>10)
        min=j;
    //cout<<j<<":"<<bin<<',';
  }
  //cout<<"\n";
  mean /= N;
  //cout<<"mean:"<<mean<<" min:"<<min<<endl;
  if(mean < 25 && min < 50 )
    start=2;

  // cumulative hist
  int total = mat.cols*mat.rows;
  int vmin[3], vmax[3];
  for (int i = 0; i < start; ++i) 
  {
    for (int j = 0; j < 255; ++j)
    {
      hists[i][j + 1] += hists[i][j];
    }

    vmin[i] = 0;
    vmax[i] = 255;
    while (hists[i][vmin[i]] < discard_ratio * total)
      vmin[i] += 1;
    while (hists[i][vmax[i]] > (1 - discard_ratio) * total)
      vmax[i] -= 1;
    
    if (vmax[i] < 255 - 1)
      vmax[i] += 1;
  }


  for (int y = 0; y < mat.rows; ++y)
  {
    for (int x = 0; x < mat.cols; ++x)
    {  
      for (int j = 0; j < start; ++j) 
      {  
        int val = (mat.at<Vec3b>(y,x)).val[j];
        if (val < vmin[j])
          val = vmin[j];
        if (val > vmax[j])
          val = vmax[j];
        (mat.at<Vec3b>(y,x)).val[j] = (val - vmin[j]) * 255.0 / (vmax[j] - vmin[j]);
      }
    }
  }

}


void inten(Mat image)
{
    Mat inimg;
    image.copyTo(inimg);
    int hist[256],val=0;
    for (int i = 0; i < 256; ++i)
    {
        hist[i]=0;
    }
    cout<<"q"<<(int)inimg.at<cv::Vec3b>(0,0)[0]<<endl;
    float mean=0,N=0;

    for (int i = 0; i < inimg.rows; ++i)
    {
        for (int j = 0; j < inimg.cols; ++j)
        {
            val=0;
            val+= (int)inimg.at<cv::Vec3b>(i,j)[0];
            val+= (int)inimg.at<cv::Vec3b>(i,j)[1];
            val+=(int)inimg.at<cv::Vec3b>(i,j)[2];
            val/=3;
            //val+= ( (int)inimg.at<cv::Vec3b>(i,j)[0] + (int)inimg.at<cv::Vec3b>(i,j)[1]+(int)inimg.at<cv::Vec3b>(i,j)[2] )/3;
            //cout<<":"<<val;
            hist[val]++;
        }
    }
    for (int i = 0; i < 256; ++i)
    {
        mean+=hist[i]*i;
        N+=hist[i];
    }
    mean = mean/N;

    double var=0;
    int totalCount=0,sum=0;
    for( int i = 0; i < 256; i++){
          int binVal = (hist[i]);
          sum += (i-mean)*(i-mean);
          totalCount += binVal;
    }
    var = sum/totalCount;

    cout<<"mean intensity: "<<mean<<" var"<<var<<endl;
}

static void help()
{
    cout
        << "------------------------------------------------------------------------------" << endl
        << "This program enhances images/Videos"                                            << endl
        << "Usage:"                                                                         << endl
        << "./godseye fileName [i/v] [outfile]"                                             << endl
        << "   fileName - The image or video path"                                          << endl
        << "   i - if file is image"                                                        << endl
        << "   v - if file is video"                                                        << endl
        << "   s - save the output"                                                         << endl
        << "------------------------------------------------------------------------------" << endl
        << endl;
    exit(0);
}


 int main( int argc, char** argv )
{   
    
    int type = 1;//img
    bool store = false; //store output
    Mat imgOriginal;
    VideoCapture cap; // try capture the video
    VideoWriter outputVideo;
    Mat input, image, dst;
    
    switch (argc)
    {
      case 1:
        help();
        break;

      case 2:
        if(argv[1][0] == '0')
        {
          type = -1;
          cap.open(0);
        }
        else
          help();
        break;
 
      case 4:
        {
          store = true;
          const string source = argv[1];  
          string::size_type pAt = source.find_last_of('.');                  // Find extension point
          const string ext = source.substr(pAt, source.length());   // Form the new name with     
          
          if(argv[2][0] == 'v')
          {
            outputVideo.open("out.avi",CV_FOURCC('M','J','P','G'),10, Size(320,240),true);
            if (!outputVideo.isOpened())
            {
                cout  << "Could not open the output video for write" << endl;
                return -1;
            }
          }
          else if(argv[2][0] == 'i')
          {
            type = 1;
            imgOriginal = imread(argv[1], CV_LOAD_IMAGE_UNCHANGED);    
            Mat imop;
            imop = imgOriginal.clone();
            balance_white1(imop);
            imwrite("out.jpeg", imop);
          }
        }

      case 3:
   
        if(argv[2][0] == 'v')
        {
          type = 2; //video
          cap.open(argv[1]);
        }
        else if(argv[2][0] == 'i')
        {
          type =1; //image
          imgOriginal = imread(argv[1], CV_LOAD_IMAGE_UNCHANGED);    
        }
        break;
    }

    input.create(240,320,CV_8UC(3));

    /*color_correction::contrast_stretching a;
    color_correction::gray_world b1;
    color_correction::gray_edge b2;
    color_correction::maxRGB b3;
    color_correction::max_edge b4;
    */
    
    int i =1;
    while (true)
    {
        int k = waitKey(FPS);
        //cout<<k<<endl;
        if (( type == 2 || type == -1 )&& i == 1)
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
        imgOriginal.copyTo(image);
        Mat im1;
        imgOriginal.copyTo(im1);

        resize(image,input, input.size(), 0, 0, INTER_NEAREST);
        //input = image;
        imshow("original",input);

        /*imshow("contrast stretching",a.run(input));
        imshow("gray world RGB",b1.run2(input,1,2));
        imshow("gray world Lab",b1.run1(input,1));
        imshow("Shades of gray",b1.run2(input,6,2));
        imshow("gray edge",b2.run(input,1,0));*/
        
        
        //inten(input);

        /*cv::cvtColor (im1,im1,CV_BGR2YCrCb);
        vector <Mat> channels;
        cv::split(im1,channels);
        imshow("intensity",channels[0]);*/

        balance_white1(input);
        imshow("Gods Eye",input);

        //imshow("final",input);

        ///////////////////////////////////////////
        ////            till here                //
        ///////////////////////////////////////////
        
        if(store)
          outputVideo.write(input);

        if ( k == 27|| k == 1048603 ) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
        {
            cout << "esc key is pressed by user" << endl;
            break; 
        }
        else if ( /*k == 110 || k == 1048686*/ true )//press 'n' for next frame
        {
            i=1;
        }
    }

   return 0;

}

