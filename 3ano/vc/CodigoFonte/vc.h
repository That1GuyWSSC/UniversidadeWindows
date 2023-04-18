//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//           INSTITUTO POLIT�CNICO DO C�VADO E DO AVE
//                          2022/2023
//             ENGENHARIA DE SISTEMAS INFORM�TICOS
//                    VIS�O POR COMPUTADOR
//
//             [  BRUNO OLIVEIRA - boliveira@ipca.pt  ]
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#define VC_DEBUG


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//                   ESTRUTURA DE UMA IMAGEM
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


typedef struct {
	unsigned char *data;
	int width, height;
	int channels;			// Bin�rio/Cinzentos=1; RGB=3
	int levels;				// Bin�rio=1; Cinzentos [1,255]; RGB [1,255]
	int bytesperline;		// width * channels
} IVC;


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//                    PROT�TIPOS DE FUN��ES
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// FUN��ES: ALOCAR E LIBERTAR UMA IMAGEM
IVC *vc_image_new(int width, int height, int channels, int levels);
IVC *vc_image_free(IVC *image);


//system("cmd /c start FilterGear Images/FLIR/flir-01.pgm"); // Input
//system("FilterGear vc0001.pgm"); // Output


float max(float a , float b, float c);//max para tres floats
float min(float a , float b, float c);//min para tres floats

// FUN��ES: LEITURA E ESCRITA DE IMAGENS (PBM, PGM E PPM)
IVC *vc_read_image(char *filename); // le uma imagem 
int vc_write_image(char *filename, IVC *image); // cria uma nova imagem
int vc_rgb_get_red_gray(IVC *srcdst); // transforma a imagem RGB numa imagem cinzento (com os valores do vermelho), devido a que se todos os valores forem igual no rgb a cor e um cinzento
int vc_rgb_to_gray(IVC *src, IVC *dst); // transforma uma imagem RGB numa imagem cinzento (com os valores predefinidos)  Intensidade = R * 0.299 + G * 0.587 + B * 0.114   precisa tambem de uma imagem de destino(precisam de ter a mesma dimensao)
int minhacomposta_vc_rgb_to_gray(IVC *src, IVC *dst); // minha funcao igual vc_rgb_to_gray
int vc_rgb_to_hsv(IVC *src, IVC *dst);//funcao para transformar imagem rgb para hsv com as mesmas dimensoes
int vc_hsv_segmentation_one_channel(IVC *src, IVC *dst, int hmin, int hmax, int smin, int smax, int vmin, int vmax);//segmenta uma imagem hsv dentro de valores;
int vc_hsv_segmentation(IVC *srcdst, int hmin, int hmax, int smin, int smax, int vmin, int vmax);//pelo stor para 3 canais.
int vc_scale_gray_to_rgb(IVC *src, IVC *dst); // pega numa scale e faz as contas com ela
int vc_gray_to_binary(IVC *src, IVC  *dst, int threshold);// segmentacao global de com uma treshold global set by the input 
int vc_gray_to_binary_global_mean(IVC *src, IVC *dst); // segmentar a imagem usando um threshold global dado pelo media de todos os pixeis da imagem
int vc_binary_dilate(IVC *src, IVC *dst, int kernel); //dilatacao de uma imagem BINARIA com valor do kernel
int vc_binary_erode(IVC *src, IVC *dst, int kernel); //erosao de uma imagem BINARIA com valor do kernel
int vc_binary_close(IVC *src, IVC *dst , int kernel);// fechar de uma imagem binaria
int vc_binary_open(IVC *src, IVC *dst , int kernel);// abertura de uma imagem binaria
int vc_gray_dilate(IVC *src, IVC *dst, int kernel);
int vc_gray_erode(IVC *src, IVC *dst, int kernel);
int vc_gray_histogram_show(IVC *src, IVC *dst);
int vc_gray_histogram_equalization(IVC *src, IVC *dst);







