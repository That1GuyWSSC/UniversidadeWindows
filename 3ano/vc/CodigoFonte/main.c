#include <stdio.h>
#include "vc.h"

int main(){

    IVC *imagesrc, *imagedst;
    int i;
    imagesrc = vc_read_image("../Images/Classic/pepper.ppm");
    if (imagesrc == NULL)
    {
        printf("Error -> vc_read_image(): \n \tFile not found\n");
        getchar();
        return 0;
    }
 
    imagedst = vc_image_new(imagesrc->width,imagesrc->height,1,imagesrc->levels);
     if (imagedst == NULL)
    {
        printf("Error -> vc_image_new: \n \tFile not found\n");
        getchar();
        return 0;
    }

    minhacomposta_vc_rgb_to_gray(imagesrc,imagedst); 
    //vc_rgb_to_gray(imagesrc,imagedst); 
    printf("teste\n");

    vc_write_image("src.ppm", imagesrc);
    vc_write_image("TesteImageGray.pgm",imagedst);

    vc_image_free(imagesrc);
    vc_image_free(imagedst);
    /*printf("Width = %d\n", imagedst->width);
    printf("height = %d\n", imagedst->height);*/
    

    printf("Press any key to close...");
    getchar();
    return 0;
    

}

