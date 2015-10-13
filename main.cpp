#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <cv.h>
#include <highgui.h>

//Created by Liang Sun
//20, Mar, 2011

#define PI acos(-1)
int main() {
  IplImage* img = 0;
  int height,width,step,channels;
  uchar *data, *result;
  int i,j,k,t,x,y;
  double angle = PI / 6;
  double cosa, sina;
  cosa = cos(angle);
  sina = sin(angle);

  // load an image  
  img=cvLoadImage("lena512.bmp");
  if(!img){
    printf("Could not load image filen");
    exit(0);
  }

  // get the image data
  height    = img->height;
  width     = img->width;
  step      = img->widthStep;
  channels  = img->nChannels;
  data      = (uchar *)img->imageData;
  result	= (uchar *)malloc(height * step);
  printf("Processing a %dx%d image with %d channelsn",height,width,channels); 


  // create a window
  cvNamedWindow("mainWin", CV_WINDOW_AUTOSIZE); 
  cvMoveWindow("mainWin", 100, 100);

  // invert the image
	for(i=0;i<height;i++) {
		for(j=0;j<width;j++) {
			x = (j - width / 2) * cosa - (i - height / 2) * sina + width / 2;
			y = (j - width / 2) * sina + (i - height / 2) * cosa + height / 2;
			for(k=0;k<channels;k++) {
				t = y * step + x * channels + k;
				if (t >= 0 && t < height * step){
					result[i * step + j * channels + k] = data[t];
				}
			}
		}
	}

	for (i = 0; i < height * step; ++i) {
		data[i] = result[i];
	}
  // show the image
  cvShowImage("mainWin", img );

  // wait for a key
  cvWaitKey(0);

  // release the image
  cvReleaseImage(&img );
  return 0;
}

