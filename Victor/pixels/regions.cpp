#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main(int, char**){
  Mat image;
  Vec3b val;
  Vec2b P1 , P2;

  image= imread("bolhas.png",CV_LOAD_IMAGE_GRAYSCALE);
  if(!image.data)
    cout << "nao abriu bolhas.png" << endl;

  namedWindow("janela",WINDOW_AUTOSIZE);

  for(int i=200;i<210;i++){
    for(int j=10;j<200;j++){
      image.at<uchar>(i,j)=0;
    }
  }
  
  imshow("janela", image);  
  waitKey();

  image= imread("bolhas.png",CV_LOAD_IMAGE_COLOR);

  val[0] = 0;   //B
  val[1] = 0;   //G
  val[2] = 255; //R
  
  for(int i=200;i<210;i++){
    for(int j=10;j<200;j++){
      image.at<Vec3b>(i,j)=val;
    }
  }

  imshow("janela", image);  
  waitKey();
  return 0;
}

