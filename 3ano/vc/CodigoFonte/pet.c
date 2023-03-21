#include <stdio.h>
#include "vc.h"

int main(){

	IVC *image, *imageGray;

	//image = vc_read_image("Images/Additional/fruits.ppm");
	image = vc_read_image("../Images/PET/PET-Alzheimer.ppm");
	if (image == NULL)
	{
		printf("ERROR -> vc_read_image():\n\tFile not found!\n");
		getchar();
		return 0;
	}

	imageGray = vc_image_new(image->width, image->height, 1, image->levels);

	vc_rgb_to_hsv(image,image);
	vc_write_image("alzheimerhsv.ppm", image);

	vc_hsv_segmentation(image, 91, 180, 50, 100, 60, 100); 
	//vc_hsv_segmentation_one_channel(image, imageGray, 91, 180, 80,100,80,100);
	//vc_hsv_segmentation(image, 58, 60, 50, 100, 60, 100); // HSVTestImage02.ppm -> Amarelo
	//vc_hsv_segmentation(image, 30, 55, 40, 100, 40, 100); // Fruits (amarelo e laranja)
	vc_rgb_to_gray(image, imageGray);

	vc_write_image("vc0010.pgm", imageGray);



	//system("cmd /c start FilterGear Images/Additional/fruits.ppm");
	system("cmd /c start FilterGear ../Images/PET/PET-Alzheimer.ppm");
	system("cmd /c start FilterGear alzheimerhsv.ppm");
	system("FilterGear vc0010.pgm");
	
	vc_image_free(image);
	vc_image_free(imageGray);

	printf("Press any key to exit...\n");
	getchar();

	return 0;



    printf("Press any key to close...");
    getchar();
    return 0;

}
