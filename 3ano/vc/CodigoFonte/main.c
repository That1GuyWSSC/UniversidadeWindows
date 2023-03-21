#include <stdio.h>
#include "vc.h"

int main(){

    IVC *imagesrc, *imagedst;
    imagesrc= vc_read_image("../Images/Chess/chess.pgm");
    if(imagesrc == NULL)
    {
        printf("Error -> vc_read_image(): \n \tFile not found\n");
        getchar();
        return 0;
    }

    imagedst = vc_image_new(imagesrc->width,imagesrc->height,1,1);

    vc_gray_to_binary_global_mean(imagesrc,imagedst);

    vc_write_image("testemediachess.ppm", imagedst);
    
    //vc_gray_to_binary(imagesrc,imagedst,100);
    
    //vc_write_image("testechess.ppm",imagedst);

    system("cmd /c start FilterGear ../Images/Chess/chess.pgm"); // Input// Input
    //system("FilterGear testechess.ppm"); // Output
    system("FilterGear testemediachess.ppm");

    vc_image_free(imagesrc);
    vc_image_free(imagedst);

    printf("Press any key to close...");
    getchar();

    return 0;

}

int main_scale_gray_to_rgb(){

    IVC *image1, *image2;
        image1 = vc_read_image("../Images/FLIR/flir-04.pgm");
    if (image1 == NULL)
    {
        printf("Error -> vc_read_image(): \n \tFile not found\n");
        getchar();
        return 0;
    }

     image2 = vc_image_new(image1->width,image1->height,3,image1->levels);
     if (image2 == NULL)
    {
        printf("Error -> vc_image_new: \n \tFile not found\n");
        getchar();
        return 0;
    }
    
    vc_scale_gray_to_rgb(image1,image2);

    vc_write_image("carroqueveiodegray.ppm",image2);


     //filtergear dings

    system("cmd /c start FilterGear ../Images/FLIR/flir-04.pgm"); // Input// Input
    system("FilterGear carroqueveiodegray.ppm"); // Output

    vc_image_free(image1);
    vc_image_free(image2);

    printf("Press any key to close...");
    getchar();

    return 0;
}

/*
int main_hsv_segmentation(){

    IVC *imagesrc, *imagedst;
    imagesrc = vc_read_image("../Images/HSV/hsvtestefeita.ppm");
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

        printf("teste1\n");

    vc_hsv_segmentation_one_channel(imagesrc, imagedst, 55, 90, 230, 255,230,255);
    printf("teste2\n");

     vc_write_image("segmentedyellow.ppm",imagedst);


     //filtergear dings

    system("cmd /c start FilterGear ../Images/HSV/hsvtestefeita.ppm"); // Input
    system("FilterGear ../Images/HSV/HSVTestImage01.ppm"); // Input
    system("FilterGear segmentedyellow.ppm"); // Output

    vc_image_free(imagesrc);
    vc_image_free(imagedst);

    printf("Press any key to close...");
    getchar();
    return 0;

}

*/
int main_rgb_to_hsv(){

    IVC *imagesrc, *imagedst;
      imagesrc = vc_read_image("../Images/HSV/HSVTestImage01.ppm");
    if (imagesrc == NULL)
    {
        printf("Error -> vc_read_image(): \n \tFile not found\n");
        getchar();
        return 0;
    }
 
    imagedst = vc_image_new(imagesrc->width,imagesrc->height,imagesrc->channels,imagesrc->levels);
     if (imagedst == NULL)
    {
        printf("Error -> vc_image_new: \n \tFile not found\n");
        getchar();
        return 0;
    }

      vc_rgb_to_hsv(imagesrc,imagedst);
      printf("teste1\n");

    //vc_write_image("srcrgb.ppm", imagesrc);
    vc_write_image("hsvteste.ppm",imagedst);

    //filtergear dings
    system("cmd /c start FilterGear ../Images/HSV/HSVTestImage01.ppm"); // Input
    system("FilterGear hsvteste.ppm"); // Output

    vc_image_free(imagesrc);
    vc_image_free(imagedst);

    printf("Press any key to close...");
    getchar();
    return 0;
    

}

int main_vc_rgb_to_gray(){

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

