//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//           INSTITUTO POLIT�CNICO DO C�VADO E DO AVE
//                          2022/2023
//             ENGENHARIA DE SISTEMAS INFORM�TICOS
//                    VIS�O POR COMPUTADOR
//
//             [  BRUNO OLIVEIRA - boliveira@ipca.pt  ]
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Desabilita (no MSVC++) warnings de fun��es n�o seguras (fopen, sscanf, etc...)
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include "vc.h"
#include <math.h>


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//            FUN��ES: ALOCAR E LIBERTAR UMA IMAGEM
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


// Alocar mem�ria para uma imagem
IVC* vc_image_new(int width, int height, int channels, int levels)
{
	IVC* image = (IVC*)malloc(sizeof(IVC));

	if (image == NULL) return NULL;
	if ((levels <= 0) || (levels > 255)) return NULL;

	image->width = width;
	image->height = height;
	image->channels = channels;
	image->levels = levels;
	image->bytesperline = image->width * image->channels;
	image->data = (unsigned char*)malloc(image->width * image->height * image->channels * sizeof(char));

	if (image->data == NULL)
	{
		return vc_image_free(image);
	}

	return image;
}


// Libertar mem�ria de uma imagem
IVC* vc_image_free(IVC* image)
{
	if (image != NULL)
	{
		if (image->data != NULL)
		{
			free(image->data);
			image->data = NULL;
		}

		free(image);
		image = NULL;
	}

	return image;
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//    FUN��ES: LEITURA E ESCRITA DE IMAGENS (PBM, PGM E PPM)
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


char* netpbm_get_token(FILE* file, char* tok, int len)
{
	char* t;
	int c;

	for (;;)
	{
		while (isspace(c = getc(file)));
		if (c != '#') break;
		do c = getc(file);
		while ((c != '\n') && (c != EOF));
		if (c == EOF) break;
	}

	t = tok;

	if (c != EOF)
	{
		do
		{
			*t++ = c;
			c = getc(file);
		} while ((!isspace(c)) && (c != '#') && (c != EOF) && (t - tok < len - 1));

		if (c == '#') ungetc(c, file);
	}

	*t = 0;

	return tok;
}


long int unsigned_char_to_bit(unsigned char* datauchar, unsigned char* databit, int width, int height)
{
	int x, y;
	int countbits;
	long int pos, counttotalbytes;
	unsigned char* p = databit;

	*p = 0;
	countbits = 1;
	counttotalbytes = 0;

	for (y = 0; y < height; y++)
	{
		for (x = 0; x < width; x++)
		{
			pos = width * y + x;

			if (countbits <= 8)
			{
				// Numa imagem PBM:
				// 1 = Preto
				// 0 = Branco
				//*p |= (datauchar[pos] != 0) << (8 - countbits);

				// Na nossa imagem:
				// 1 = Branco
				// 0 = Preto
				*p |= (datauchar[pos] == 0) << (8 - countbits);

				countbits++;
			}
			if ((countbits > 8) || (x == width - 1))
			{
				p++;
				*p = 0;
				countbits = 1;
				counttotalbytes++;
			}
		}
	}

	return counttotalbytes;
}


void bit_to_unsigned_char(unsigned char* databit, unsigned char* datauchar, int width, int height)
{
	int x, y;
	int countbits;
	long int pos;
	unsigned char* p = databit;

	countbits = 1;

	for (y = 0; y < height; y++)
	{
		for (x = 0; x < width; x++)
		{
			pos = width * y + x;

			if (countbits <= 8)
			{
				// Numa imagem PBM:
				// 1 = Preto
				// 0 = Branco
				//datauchar[pos] = (*p & (1 << (8 - countbits))) ? 1 : 0;

				// Na nossa imagem:
				// 1 = Branco
				// 0 = Preto
				datauchar[pos] = (*p & (1 << (8 - countbits))) ? 0 : 1;

				countbits++;
			}
			if ((countbits > 8) || (x == width - 1))
			{
				p++;
				countbits = 1;
			}
		}
	}
}


IVC* vc_read_image(char* filename)
{
	FILE* file = NULL;
	IVC* image = NULL;
	unsigned char* tmp;
	char tok[20];
	long int size, sizeofbinarydata;
	int width, height, channels;
	int levels = 255;
	int v;

	// Abre o ficheiro
	if ((file = fopen(filename, "rb")) != NULL)
	{
		// Efectua a leitura do header
		netpbm_get_token(file, tok, sizeof(tok));

		if (strcmp(tok, "P4") == 0) { channels = 1; levels = 1; }	// Se PBM (Binary [0,1])
		else if (strcmp(tok, "P5") == 0) channels = 1;				// Se PGM (Gray [0,MAX(level,255)])
		else if (strcmp(tok, "P6") == 0) channels = 3;				// Se PPM (RGB [0,MAX(level,255)])
		else
		{
#ifdef VC_DEBUG
			printf("ERROR -> vc_read_image():\n\tFile is not a valid PBM, PGM or PPM file.\n\tBad magic number!\n");
#endif

			fclose(file);
			return NULL;
		}

		if (levels == 1) // PBM
		{
			if (sscanf(netpbm_get_token(file, tok, sizeof(tok)), "%d", &width) != 1 ||
				sscanf(netpbm_get_token(file, tok, sizeof(tok)), "%d", &height) != 1)
			{
#ifdef VC_DEBUG
				printf("ERROR -> vc_read_image():\n\tFile is not a valid PBM file.\n\tBad size!\n");
#endif

				fclose(file);
				return NULL;
			}

			// Aloca mem�ria para imagem
			image = vc_image_new(width, height, channels, levels);
			if (image == NULL) return NULL;

			sizeofbinarydata = (image->width / 8 + ((image->width % 8) ? 1 : 0)) * image->height;
			tmp = (unsigned char*)malloc(sizeofbinarydata);
			if (tmp == NULL) return 0;

#ifdef VC_DEBUG
			printf("\nchannels=%d w=%d h=%d levels=%d\n", image->channels, image->width, image->height, levels);
#endif

			if ((v = fread(tmp, sizeof(unsigned char), sizeofbinarydata, file)) != sizeofbinarydata)
			{
#ifdef VC_DEBUG
				printf("ERROR -> vc_read_image():\n\tPremature EOF on file.\n");
#endif

				vc_image_free(image);
				fclose(file);
				free(tmp);
				return NULL;
			}

			bit_to_unsigned_char(tmp, image->data, image->width, image->height);

			free(tmp);
		}
		else // PGM ou PPM
		{
			if (sscanf(netpbm_get_token(file, tok, sizeof(tok)), "%d", &width) != 1 ||
				sscanf(netpbm_get_token(file, tok, sizeof(tok)), "%d", &height) != 1 ||
				sscanf(netpbm_get_token(file, tok, sizeof(tok)), "%d", &levels) != 1 || levels <= 0 || levels > 255)
			{
#ifdef VC_DEBUG
				printf("ERROR -> vc_read_image():\n\tFile is not a valid PGM or PPM file.\n\tBad size!\n");
#endif

				fclose(file);
				return NULL;
			}

			// Aloca mem�ria para imagem
			image = vc_image_new(width, height, channels, levels);
			if (image == NULL) return NULL;

#ifdef VC_DEBUG
			printf("\nchannels=%d w=%d h=%d levels=%d\n", image->channels, image->width, image->height, levels);
#endif

			size = image->width * image->height * image->channels;

			if ((v = fread(image->data, sizeof(unsigned char), size, file)) != size)
			{
#ifdef VC_DEBUG
				printf("ERROR -> vc_read_image():\n\tPremature EOF on file.\n");
#endif

				vc_image_free(image);
				fclose(file);
				return NULL;
			}
		}

		fclose(file);
	}
	else
	{
#ifdef VC_DEBUG
		printf("ERROR -> vc_read_image():\n\tFile not found.\n");
#endif
	}

	return image;
}


int vc_write_image(char* filename, IVC* image)
{
	FILE* file = NULL;
	unsigned char* tmp;
	long int totalbytes, sizeofbinarydata;

	if (image == NULL) return 0;

	if ((file = fopen(filename, "wb")) != NULL)
	{
		if (image->levels == 1)
		{
			sizeofbinarydata = (image->width / 8 + ((image->width % 8) ? 1 : 0)) * image->height + 1;
			tmp = (unsigned char*)malloc(sizeofbinarydata);
			if (tmp == NULL) return 0;

			fprintf(file, "%s %d %d\n", "P4", image->width, image->height);

			totalbytes = unsigned_char_to_bit(image->data, tmp, image->width, image->height);
			printf("Total = %ld\n", totalbytes);
			if (fwrite(tmp, sizeof(unsigned char), totalbytes, file) != totalbytes)
			{
#ifdef VC_DEBUG
				fprintf(stderr, "ERROR -> vc_read_image():\n\tError writing PBM, PGM or PPM file.\n");
#endif

				fclose(file);
				free(tmp);
				return 0;
			}

			free(tmp);
		}
		else
		{
			fprintf(file, "%s %d %d 255\n", (image->channels == 1) ? "P5" : "P6", image->width, image->height);

			if (fwrite(image->data, image->bytesperline, image->height, file) != image->height)
			{
#ifdef VC_DEBUG
				fprintf(stderr, "ERROR -> vc_read_image():\n\tError writing PBM, PGM or PPM file.\n");
#endif

				fclose(file);
				return 0;
			}
		}

		fclose(file);

		return 1;
	}

	return 0;
}


int vc_rgb_get_red_gray(IVC* srcdst) {

	unsigned char* data = (unsigned char*)srcdst->data;
	int width = srcdst->width;
	int height = srcdst->height;
	int channels = srcdst->channels;
	int levels = srcdst->levels;
	int bytesperline = srcdst->bytesperline;

	long int pos;
	//verificacao de erros com o ficheiro
	if ((srcdst->width <= 0) || (srcdst->height <= 0) || (srcdst->data == NULL))return 0;
	if (channels != 3) return 0;


	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			pos = j * bytesperline + i * channels;

			data[pos + 1] = data[pos];
			data[pos + 2] = data[pos];
		}

	}

}


/*int minha_vc_rgb_to_gray(IVC *src, IVC *dst){

	unsigned char *data_src = (unsigned char *) src->data;
	int channelssrc = src->channels;
	int bytesperlinesrc = src->width * src->channels;

	unsigned char *data_dst = (unsigned char *) dst->data;
	int channelsdst = dst->channels;
	int bytesperlinedst = dst->width * dst->channels;
	int width = src->width;
	int height = src->height;
	float auxred, auxgreen, auxblue;
	long int pos, pos_dst;

	if((src->width <= 0) || (src->height <=0) || (src->data == NULL)) printf("A imagem tem altura/largura/data impossivel"); return 0;
	if((src->width != dst->width) || (src->height != dst->height)) printf("Elas tem diferentes valores de dimensao"); return 0;
	if((src->channels != 3) || (dst->channels !=1)) printf("Os canais das imagems estao errados"); return 0;


	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			pos = i * bytesperlinesrc + j * channelssrc;
			pos_dst = i * bytesperlinedst + j * channelsdst;

			auxred = (float) data_src[pos] ;
			auxgreen = (float) data_src[pos+1] ;
			auxblue= (float) data_src[pos+2];

			data_dst[pos_dst] = (unsigned char) ((auxred * 0.299) + (auxgreen * 0.587) + (auxblue * 0.114));

		}

	}

	return 1;
}
*/

int vc_rgb_to_gray(IVC* src, IVC* dst)
{
	unsigned char* datasrc = (unsigned char*)src->data;
	int bytesperline_src = src->width * src->channels;
	int channels_src = src->channels;
	unsigned char* datadst = (unsigned char*)dst->data;
	int width = src->width;
	int height = src->height;
	int bytesperline_dst = dst->width * dst->channels;
	int channels_dst = dst->channels;
	int x, y;
	long int pos_src, pos_dst;
	float rg, gg, bg;

	for (y = 0; y < height; y++)
	{
		for (x = 0; x < width; x++)
		{
			pos_src = y * bytesperline_src + x * channels_src;
			pos_dst = y * bytesperline_dst + x * channels_dst;

			rg = (float)datasrc[pos_src];
			gg = (float)datasrc[pos_src + 1];
			bg = (float)datasrc[pos_src + 2];

			datadst[pos_dst] = (unsigned char)((rg * 0.299) + (gg * 0.587) + (bg * 0.114));
		}
	}
	return 1;
}

int minhacomposta_vc_rgb_to_gray(IVC* src, IVC* dst) {

	unsigned char* datasrc = (unsigned char*)src->data;
	int width = src->width;
	int height = src->height;
	int levels = src->levels;
	int bytesperlinesrc = src->width * src->channels;
	int channels = src->channels;

	unsigned char* datadst = (unsigned char*)dst->data;
	int channelsdst = dst->channels;
	int bytesperlinedst = dst->width * dst->channels;
	int levelsdst = dst->levels;

	long int pos, posdst;

	float auxred, auxgreen, auxblue;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			pos = i * bytesperlinesrc + j * channels;
			posdst = i * bytesperlinedst + j * channelsdst;

			auxred = (float)datasrc[pos];
			auxgreen = (float)datasrc[pos + 1];
			auxblue = (float)datasrc[pos + 2];
			datadst[posdst] = (unsigned char)((auxred * 0.299) + (auxgreen * 0.587) + (auxblue * 0.114));
		}

	}

	return 1;
}

float max(float a, float b, float c) {

	if (a > b && a > c)
	{
		return a;
	}
	else if (b > c) {
		return b;
	}
	else return c;


}

float min(float a, float b, float c) {

	if (a < b && a < c)
	{
		return a;
	}
	else if (b < c) {
		return b;
	}
	else return c;


}



int vc_rgb_to_hsv(IVC* src, IVC* dst) {

	unsigned char* datasrc = (unsigned char*)src->data;
	int width = src->width;
	int height = src->height;
	int levels = src->levels;
	int channels = src->channels;
	int bytesperline = src->width * src->channels;

	unsigned char* datadst = (unsigned char*)dst->data;
	int channels_dst = dst->channels;
	int levels_dst = dst->levels;
	int bytesperline_dst = dst->width * dst->channels;

	long int pos, pos_dst;

	float auxred, auxgreen, auxblue;

	float sat, val, hue;

	float  minlocal, delta;


	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			pos = i * bytesperline + j * channels;
			pos_dst = i * bytesperline_dst + j * channels_dst;

			auxred = datasrc[pos];
			auxgreen = datasrc[pos + 1];
			auxblue = datasrc[pos + 2];

			val = max(auxred, auxgreen, auxblue);
			minlocal = min(auxred, auxgreen, auxblue);
			delta = (val - minlocal);
			
			if (val == 0 && delta == 0) {
				sat = 0;
			}
			else {

				sat = (delta) / val;
				sat = sat * 255;
			}

			if (val == auxred && auxgreen >= auxblue) {
				hue = ((60) * (auxgreen - auxblue) / (delta));
			}

			else if (val == auxred && auxgreen < auxblue) {
				hue = ((360 + 60) * (auxgreen - auxblue) / (delta));
			}

			else if (val == auxgreen) {
				hue = ((120 + 60) * (auxblue - auxred) / (delta));
			}

			else if (val == auxblue) {
				hue = ((240 + 60) * (auxred - auxgreen) / (delta));
			}


			if (hue > 255) {
				hue = (hue / 360) * 255;
			}

			 datadst[pos] =  (unsigned char ) hue;
			 datadst[pos + 1] = (unsigned char) sat;
			 datadst[pos + 2] = (unsigned char) val;



		}

	}


}


int vc_hsv_segmentation_one_channel(IVC *src, IVC *dst, int hmin, int hmax, int smin, int smax, int vmin, int vmax){

	unsigned char* datasrc = (unsigned char*)src->data;
	int width = src->width;
	int height = src->height;
	int channels = src->channels;
	int bytesperline = src->width * src->channels;

	unsigned char* datadst = (unsigned char*)dst->data;
	int channels_dst = dst->channels;
	int bytesperline_dst = dst->width * dst->channels;

	long int pos, pos_dst;

	int hue,sat,val;
	
	
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			pos = i * bytesperline + j * channels;
			pos_dst = i * bytesperline_dst + j * channels_dst;

			
			hue = (int) (((float)datasrc[pos]) / 255.0f * 360.0f);
			sat = (int) (((float)datasrc[pos+1]) / 255.0f * 100.0f);
			val = (int) (((float)datasrc[pos+2]) / 255.0f * 100.0f);
			if (hue > hmin && hue <= hmax && sat > smin && sat <= smax && val > vmin && val <= vmax){
				
				datadst[pos_dst] = 255;

			}
			else{
				datadst[pos_dst] = 0;
			}


			
		}
	}
}

// hmin,hmax = [0, 360]; smin,smax = [0, 100]; vmin,vmax = [0, 100]
int vc_hsv_segmentation(IVC *srcdst, int hmin, int hmax, int smin, int smax, int vmin, int vmax)
{
	unsigned char *data = (unsigned char *)srcdst->data;
	int width = srcdst->width;
	int height = srcdst->height;
	int bytesperline = srcdst->bytesperline;
	int channels = srcdst->channels;
	int h, s, v; // h=[0, 360] s=[0, 100] v=[0, 100]
	int i, size;

	// Verificação de erros
	if ((srcdst->width <= 0) || (srcdst->height <= 0) || (srcdst->data == NULL)) return 0;
	if (channels != 3) return 0;

	size = width * height * channels;

	for (i = 0; i < size; i = i + channels)
	{
		h = (int) (((float)data[i]) / 255.0f * 360.0f);
		s = (int) (((float)data[i + 1]) / 255.0f * 100.0f);
		v = (int) (((float)data[i + 2]) / 255.0f * 100.0f);

		if ((h > hmin) && (h <= hmax) && (s >= smin) && (s <= smax) && (v >= vmin) && (v <= vmax))
		{
			data[i] = 255;
			data[i + 1] = 255;
			data[i + 2] = 255;
		}
		else
		{
			data[i] = 0;
			data[i + 1] = 0;
			data[i + 2] = 0;
		}
	}

	return 1;
}

int vc_scale_gray_to_rgb(IVC *src, IVC*dst)
{
    	unsigned char *data_src = (unsigned char *) src -> data;
    int width =  src -> width;
    int height = src -> height;
    int bytesperline_src = src -> width * src -> channels;
    int channels_src = src -> channels;  
    	unsigned char *data_dst = (unsigned char *) dst -> data;
    int bytesperline_dst = dst -> width * dst -> channels;
    int channels_dst = dst -> channels; 
    int x,y;
    long int pos_src,pos_dst;    
 
    for(y=0; y<height;y++)
    {
        for(x=0; x<width;x++)
        {
            pos_src = y * bytesperline_src + x * channels_src;
            pos_dst = y * bytesperline_dst + x * channels_dst;

                if(data_src[pos_src] >= 0  && data_src[pos_src] <= 64)
                {
                    data_dst[pos_dst] = 0;
                    data_dst[pos_dst + 1] = (unsigned char) (data_src[pos_src]) * 4;
                    data_dst[pos_dst + 2] = 255;
                }

                else if(data_src[pos_src] > 64  && data_src[pos_src] <= 128)
                {   
                    data_dst[pos_dst] = 0;
                    data_dst[pos_dst + 1] = 255;
                    data_dst[pos_dst + 2] = (unsigned char) (data_src[pos_src] - 128)* 4;
                }

                else if(data_src[pos_src] > 128  && data_src[pos_src] <= 192)
                {   
                    data_dst[pos_dst] = (unsigned char) (data_src[pos_src] - 192) * 4;
                    data_dst[pos_dst + 1] = 255;
                    data_dst[pos_dst + 2] = 0;
                }

                else if(data_src[pos_src] > 192  && data_src[pos_src] <= 255)
                {   
                    data_dst[pos_dst] = 255;
                    data_dst[pos_dst + 1] = (unsigned char) (data_src[pos_src] - 255) * 4;
                    data_dst[pos_dst + 2] = 0;
                }
        }
    }
}

int vc_gray_to_binary(IVC *src, IVC  *dst, int threshold){

	   	unsigned char *data_src = (unsigned char *) src -> data;
    int width =  src -> width;
    int height = src -> height;
    int bytesperline_src = src -> width * src -> channels;
    int channels_src = src -> channels; 
	int levels_src = src->levels;
    	unsigned char *data_dst = (unsigned char *) dst -> data;
    int bytesperline_dst = dst -> width * dst -> channels;
    int channels_dst = dst -> channels; 
	int levels_dst = dst ->levels;
    int x,y;
    long int pos_src,pos_dst;    
	

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			pos_src = y * bytesperline_src + x * channels_src;
            pos_dst = y * bytesperline_dst + x * channels_dst;

			if (data_src[pos_src] < threshold)
			{
				data_dst[pos_dst] = 0;
			}
			else{
				data_dst[pos_dst] = 1 ;
			}
			
		}
		
	}
	
}

int vc_gray_to_binary_global_mean(IVC *src, IVC *dst){

		   	unsigned char *data_src = (unsigned char *) src -> data;
    int width =  src -> width;
    int height = src -> height;
    int bytesperline_src = src -> width * src -> channels;
    int channels_src = src -> channels; 
	int levels_src = src->levels;
    	unsigned char *data_dst = (unsigned char *) dst -> data;
    int bytesperline_dst = dst -> width * dst -> channels;
    int channels_dst = dst -> channels; 
	int levels_dst = dst ->levels;
    int x,y;
    long int pos_src,pos_dst;

	float valor, media;   
	

	for ( y = 0; y < height; y++)
	{
		for ( x = 0; x < width; x++)
		{
			pos_src = y * bytesperline_src + x * channels_src;
			valor = valor + data_src[pos_src];
			
		}
		
	}
		media = (valor) / (width * height);
	
		vc_gray_to_binary(src,dst,media);
}

/* 

int vc_gray_to_binary_niblack(IVC *src, IVC *dst, int t, float k){

		   	unsigned char *data_src = (unsigned char *) src -> data;
    int width =  src -> width;
    int height = src -> height;
    int bytesperline_src = src -> width * src -> channels;
    int channels_src = src -> channels; 
	int levels_src = src->levels;
    	unsigned char *data_dst = (unsigned char *) dst -> data;
    int bytesperline_dst = dst -> width * dst -> channels;
    int channels_dst = dst -> channels; 
	int levels_dst = dst ->levels;
    long int pos_src,pos_dst, pos_x,pos_k,pos,x,y,z,xx,yy;
	int soma,soma_quadrados,media,desvio_padrao,pixel;

	float valor, media;   
	

	for ( y = 0; y < height; y++)
	{
		for ( x = 0; x < width; x++)
		{
			pos_src = y * bytesperline_src + x * channels_src;
			pos_dst = y * bytesperline_dst + x * channels_dst;
			for (yy = -(t-1)/2; yy <= (t-1)/2; yy++)
			{
				for (xx = -(t-1)/2; xx <= (t-1)/2; xx++)
				{
					pos_k = ((yy + y)* bytesperline_src) + ((xx + x ) * channels_src);

					
				}
				
			}
				
		}
		
	}
		media = (valor) / (width * height);
	
		vc_gray_to_binary(src,dst,media);
}

 */

int vc_binary_erode(IVC *src, IVC *dst, int kernel){

		   	unsigned char *data_src = (unsigned char *) src -> data;
    int width =  src -> width;
    int height = src -> height;
    int bytesperline_src = src -> width * src -> channels;
    int channels_src = src -> channels; 
	int levels_src = src->levels;
    	unsigned char *data_dst = (unsigned char *) dst -> data;
    int bytesperline_dst = dst -> width * dst -> channels;
    int channels_dst = dst -> channels; 
	int levels_dst = dst ->levels;
    long int pos_src,pos_dst, pos_x,pos_kernel,pos,x,y,z,xx,yy;
	

	for ( y = 0; y < height; y++)
	{
		for ( x = 0; x < width; x++)
		{
			pos_src = y * bytesperline_src + x * channels_src;
			pos_dst = y * bytesperline_dst + x * channels_dst;
			
			data_dst[pos_dst] = data_src[pos_src];

			for (yy = -(kernel-1)/2; yy <= (kernel-1)/2; yy++)
			{
				for (xx = -(kernel-1)/2; xx <= (kernel-1)/2; xx++)
				{
					pos_kernel = ((yy + y)* bytesperline_src) + ((xx + x) * channels_src);

					if (data_src[pos_kernel] == 0){
						data_dst[pos_dst] = 0;
					}
					
				}
				
			}
				
		}
		
	}

}

int vc_binary_dilate(IVC *src, IVC *dst, int kernel){

		   	unsigned char *data_src = (unsigned char *) src -> data;
    int width =  src -> width;
    int height = src -> height;
    int bytesperline_src = src -> width * src -> channels;
    int channels_src = src -> channels; 
	int levels_src = src->levels;
    	unsigned char *data_dst = (unsigned char *) dst -> data;
    int bytesperline_dst = dst -> width * dst -> channels;
    int channels_dst = dst -> channels; 
	int levels_dst = dst ->levels;
    long int pos_src,pos_dst, pos_x,pos_kernel,pos,x,y,z,xx,yy;
	

	for ( y = 0; y < height; y++)
	{
		for ( x = 0; x < width; x++)
		{
			pos_src = y * bytesperline_src + x * channels_src;
			pos_dst = y * bytesperline_dst + x * channels_dst;
			
			data_dst[pos_dst] = data_src[pos_src];

			for (yy = -(kernel-1)/2; yy <= (kernel-1)/2; yy++)
			{
				for (xx = -(kernel-1)/2; xx <= (kernel-1)/2; xx++)
				{
					pos_kernel = ((yy + y)* bytesperline_src) + ((xx + x) * channels_src);

					if (data_src[pos_kernel] == 1){
						data_dst[pos_dst] = 1;
					}
					
				}
				
			}
				
		}
		
	}

}

int vc_binary_open(IVC *src, IVC *dst , int kernel){

	IVC *temp;

	unsigned char *data_src = (unsigned char *) src -> data;
    int width =  src -> width;
    int height = src -> height;
    int bytesperline_src = src -> width * src -> channels;
    int channels_src = src -> channels; 
	int levels_src = src->levels;
	long int pos_src, pos_temp;

	temp = vc_image_new(src->width, src->height, src->channels, src->levels);

	unsigned char *data_temp = (unsigned char *) temp -> data;
	
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			pos_src = i * bytesperline_src + j * channels_src;
			//pos_temp = i * bytesperline_src + j * channels_src;

			data_temp[pos_src] = data_src[pos_src];
		}
		
	}
	

	vc_binary_erode(src,temp,kernel);


	vc_binary_dilate(temp,dst,kernel);

}

int vc_binary_close(IVC *src, IVC *dst , int kernel){
	
	IVC *temp;

	unsigned char *data_src = (unsigned char *) src -> data;
    int width =  src -> width;
    int height = src -> height;
    int bytesperline_src = src -> width * src -> channels;
    int channels_src = src -> channels; 
	int levels_src = src->levels;
	long int pos_src, pos_temp;

	temp = vc_image_new(src->width, src->height, src->channels, src->levels);

	unsigned char *data_temp = (unsigned char *) temp -> data;
	
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			pos_src = i * bytesperline_src + j * channels_src;
			//pos_temp = i * bytesperline_src + j * channels_src;

			data_temp[pos_src] = data_src[pos_src];
		}
		
	}
	

	vc_binary_dilate(src,temp,kernel);
	vc_binary_erode(temp,dst,kernel);
}


int vc_gray_dilate(IVC *src, IVC *dst, int kernel){

		   	unsigned char *data_src = (unsigned char *) src -> data;
    int width =  src -> width;
    int height = src -> height;
    int bytesperline_src = src -> width * src -> channels;
    int channels_src = src -> channels; 
	int levels_src = src->levels;
    	unsigned char *data_dst = (unsigned char *) dst -> data;
    int bytesperline_dst = dst -> width * dst -> channels;
    int channels_dst = dst -> channels; 
	int levels_dst = dst ->levels;
    long int pos_src,pos_dst, pos_x,pos_kernel,pos,x,y,z,xx,yy;
	long int max = 0;
	

	for ( y = 0; y < height; y++)
	{
		for ( x = 0; x < width; x++)
		{
			pos_src = y * bytesperline_src + x * channels_src;
			pos_dst = y * bytesperline_dst + x * channels_dst;
			
			data_dst[pos_dst] = data_src[pos_src];

			max = 0;

			for (yy = -(kernel-1)/2; yy <= (kernel-1)/2; yy++)
			{
				for (xx = -(kernel-1)/2; xx <= (kernel-1)/2; xx++)
				{
					pos_kernel = ((yy + y)* bytesperline_src) + ((xx + x) * channels_src);

					if (data_src[pos_kernel] >= max){
						max = data_src[pos_kernel];
						
					}
					

				}
				
			}

			data_dst[pos_dst] = max;

				
		}
		
	}

} 



int vc_gray_erode(IVC *src, IVC *dst, int kernel){

		   	unsigned char *data_src = (unsigned char *) src -> data;
    int width =  src -> width;
    int height = src -> height;
    int bytesperline_src = src -> width * src -> channels;
    int channels_src = src -> channels; 
	int levels_src = src->levels;
    	unsigned char *data_dst = (unsigned char *) dst -> data;
    int bytesperline_dst = dst -> width * dst -> channels;
    int channels_dst = dst -> channels; 
	int levels_dst = dst ->levels;
    long int pos_src,pos_dst, pos_x,pos_kernel,pos,x,y,z,xx,yy;
	long int min = 0;
	

	for ( y = 0; y < height; y++)
	{
		for ( x = 0; x < width; x++)
		{
			pos_src = y * bytesperline_src + x * channels_src;
			pos_dst = y * bytesperline_dst + x * channels_dst;
			
			data_dst[pos_dst] = data_src[pos_src];

			min = 0;

			for (yy = -(kernel-1)/2; yy <= (kernel-1)/2; yy++)
			{
				for (xx = -(kernel-1)/2; xx <= (kernel-1)/2; xx++)
				{
					pos_kernel = ((yy + y)* bytesperline_src) + ((xx + x) * channels_src);

					if (data_src[pos_kernel] <= min){
						min = data_src[pos_kernel];
						
					}
					

				}
				
			}
			
			data_dst[pos_dst] = min;

				
		}
		
	}

} 



int vc_gray_histogram_show(IVC *src, IVC *dst){

		unsigned char *data_src = (unsigned char *) src -> data;
    int width =  src -> width;
    int height = src -> height;
    int bytesperline_src = src -> width * src -> channels;
    int channels_src = src -> channels; 
	int levels_src = src->levels;
    	unsigned char *data_dst = (unsigned char *) dst -> data;
    int bytesperline_dst = dst -> width * dst -> channels;
    int channels_dst = dst -> channels; 
	int levels_dst = dst ->levels;
    long int pos_src,pos_dst;
	long int min = 0;

	float array[256] = {0};

	for ( int y = 0; y < height; y++)
	{
		for ( int x = 0; x < width; x++)
		{
			pos_src = y * bytesperline_src + x * channels_src;
			pos_dst = y * bytesperline_dst + x * channels_dst;

			array[data_src[pos_src]] += 1;

			
		}
		
	}


	int max=0;
	for (int k = 0; k < 256; k++)
	{
		if (array[k] > max)
		{
			max = array[k];
		}
		
	}

	float normhist[256];
	for (int i = 0; i < 256; i++)
	{
		normhist[i] = array[i] / max;
	}
	
	

	
	// Gera o gr�fico com o histograma
	for (int i = 0, x = (width - 256) / 2; i<256; i++, x++)
		{
	for (int y = height - 1; y>height - 1 - normhist[i] * height; y--)
		{
		data_dst[y * bytesperline_dst + x * channels_dst] = 255;
	}
}

// Desenha linhas de in�cio (itensidade = 0) e fim (intensidade = 255)
	for (int y = 0; y<height - 1; y++)
		{
	data_dst[y * bytesperline_dst + ((width - 256) / 2 - 1) * channels_dst] = 127;
	data_dst[y * bytesperline_dst + ((width + 256) / 2 + 1) * channels_dst] = 127;
}
	

}

int vc_gray_histogram_equalization(IVC *src, IVC *dst){

			unsigned char *data_src = (unsigned char *) src -> data;
    int width =  src -> width;
    int height = src -> height;
    int bytesperline_src = src -> width * src -> channels;
    int channels_src = src -> channels; 
	int levels_src = src->levels;
    	unsigned char *data_dst = (unsigned char *) dst -> data;
    int bytesperline_dst = dst -> width * dst -> channels;
    int channels_dst = dst -> channels; 
	int levels_dst = dst ->levels;
    long int pos_src,pos_dst;

	int total = height *width;

	float array[256] = {0};

	for ( int y = 0; y < height; y++)
	{
		for ( int x = 0; x < width; x++)
		{
			pos_src = y * bytesperline_src + x * channels_src;
			pos_dst = y * bytesperline_dst + x * channels_dst;

			array[data_src[pos_src]] += 1;

			
		}
		
	}


	float pdf[256];
	float cdf[256];
	
	for (int i = 0; i < 256; i++)
	{
		pdf[i] = array[i] / total;
		if(i != 0){
		cdf[i] = cdf[i-1] + pdf[i];
		}
		else{
			cdf[i] = pdf[i];
		}
	}

	int min=9999;
	for (int k = 0; k < 256; k++)
	{
		if (cdf[k] !=0)
		{
			min = cdf[k];
			break;
		}
		
	}

	printf("%f" , cdf[255]);

	for ( int y = 0; y < height; y++)
	{
		for ( int x = 0; x < width; x++)
		{
			pos_src = y * bytesperline_src + x * channels_src;
			pos_dst = y * bytesperline_dst + x * channels_dst;

			data_dst[pos_dst] = (unsigned char) (((cdf[data_src[pos_src]] - min) / (1 - min)) * 255);


			
		}
		
	}
}

	
	