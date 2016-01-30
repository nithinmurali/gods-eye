
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
#include "color_constancy.hpp"


#define PI 3.14159265
#define FPS 30

using namespace cv;
using namespace std;

void balance_white(cv::Mat mat) {
  double discard_ratio = 0.012;
  int hists[3][256];
  memset(hists, 0, 3*256*sizeof(int));

  for (int y = 0; y < mat.rows; ++y) {
    uchar* ptr = mat.ptr<uchar>(y);
    for (int x = 0; x < mat.cols; ++x) {
      for (int j = 0; j < 3; ++j) {
        hists[j][ptr[x * 3 + j]] += 1;
      }
    }
  }

  //check if you wanna strech red
  int mean=0,N=0,min=-1,bin=0,start=3;
  for (int j = 255; j > -1; --j) {
      bin = hists[2][j];
      mean += bin*j;
      N += bin;
      if(min==-1 && bin>10)
        min=j;
    //cout<<j<<":"<<bin<<',';
    }
  cout<<"\n";
  mean /= N;
  cout<<"mean:"<<mean<<" min:"<<min<<endl;
  if(mean < 25 && min < 50 )
    start=2;

  // cumulative hist
  int total = mat.cols*mat.rows;
  int vmin[3], vmax[3];
  for (int i = 0; i < start; ++i) {

    for (int j = 0; j < 255; ++j) {
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


  for (int y = 0; y < mat.rows; ++y) {
    uchar* ptr = mat.ptr<uchar>(y);
    for (int x = 0; x < mat.cols; ++x) {
      
      for (int j = 0; j < start; ++j) {
        
        int val = ptr[x * 3 + j];
        if (val < vmin[j])
          val = vmin[j];
        if (val > vmax[j])
          val = vmax[j];
        ptr[x * 3 + j] = static_cast<uchar>((val - vmin[j]) * 255.0 / (vmax[j] - vmin[j]));
      }
    
    }
  }

}

void inten(Mat image)
{
    Mat inimg;
    image.copyTo(inimg);
    int hist[256];
    for (int i = 0; i < 256; ++i)
    {
        hist[i]=0;
    }
    float mean=0,N=0;
    for (int i = 0; i < inimg.rows; ++i)
    {
        for (int j = 0; j < inimg.cols; ++j)
        {
            hist[i]+= (inimg.at<cv::Vec3b>(i,j)[0]+inimg.at<cv::Vec3b>(i,j)[1]+inimg.at<cv::Vec3b>(i,j)[2])/3;
            
        }
    }
    for (int i = 0; i < 256; ++i)
    {
        mean+=hist[i]*i;
        N+=hist[i];
    }
    mean = mean/N;
    cout<<"mean intensity "<<mean<<endl;
}

 int main( int argc, char** argv )
{
    int type = 1;//img
    Mat imgOriginal;
    VideoCapture cap(argv[1]); // try capture the video

    Mat input, image, dst;
    input.create(240,320,CV_8UC(3));

    color_correction::contrast_stretching a;
    color_correction::gray_world b1;
    color_correction::gray_edge b2;
    color_correction::maxRGB b3;
    color_correction::max_edge b4;

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
        
        
        inten(input);
        
        cv::cvtColor (im1,im1,CV_BGR2YCrCb);
        vector <Mat> channels;
        cv::split(im1,channels);
        imshow("intensity",channels[0]);

        balance_white(input);
        imshow("white balence",input);

        //imshow("final",input);

        ///////////////////////////////////////////
        ////            till here                //
        ///////////////////////////////////////////
        if ( k == 27|| k == 1048603 ) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
        {
            cout << "esc key is pressed by user" << endl;
            break; 
        }
        else if ( k == 110 || k == 1048686 )//press 'n' for next frame
        {
            i=1;
        }
        
    }

   return 0;

}

