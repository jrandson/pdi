#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

using namespace cv;

int main(int argc, char** argv){
  Mat image, mask;
  int width, height;
  int nobjects;
  
  CvPoint p;
  image = imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);
  imshow("bolhas",image);
  
  if(!image.data){
    std::cout << "imagem nao carregou corretamente\n";
    return(-1);
  }
  width=image.size().width;
  height=image.size().height;

  p.x=0;
  p.y=0;

  // busca objetos com buracos presentes
  
  /*
      Se houverem mais de 155 ocorrencias de bolhas a contagem continua, mas a rotulação é iniciada
      Para isso ai invés de passar o valor do contador, passamos o valor do resto da divisão do contador
      por 255
  */

  // achou um objetonua,
      
  nobjects=0;
  for(int i=0; i<height; i++){
    for(int j=0; j<width; j++){
      if(image.at<uchar>(i,j) == 255){
<<<<<<< HEAD:labelling/labelling.cpp
  	
  		nobjects++;
      
  		p.x=j;
  		p.y=i;
  		floodFill(image,p,(nobjects % 255));
  	  }
	   }
=======
		// achou um objetonua,
		nobjects++;
    /*
    Se houverem mais de 155 ocorrencias de bolhas a contagem continua, mas a rotulação é iniciada
    Para isso ai invés de passar o valor do contador, passamos o valor do resto da divisão do contador
    por 255
    */    
		p.x=j;
		p.y=i;
		floodFill(image,p,(nobjects % 5)+100);
	  }
	}
>>>>>>> 348106602fe17855361c2e0b65b7216d5e63263a:Unidade I/labelling/labelling.cpp
  }

  cout << nobjects << " bolhas foram encontradas\n";
  imshow("image", image);
  imwrite("labeling.png", image);

  waitKey();
  return 0;
}
