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

// FUN��ES: LEITURA E ESCRITA DE IMAGENS (PBM, PGM E PPM)
IVC *vc_read_image(char *filename); // le uma imagem 
int vc_write_image(char *filename, IVC *image); // cria uma nova imagem
int vc_rgb_get_red_gray(IVC *srcdst); // transforma a imagem RGB numa imagem cinzento (com os valores do vermelho), devido a que se todos os valores forem igual no rgb a cor e um cinzento
int vc_rgb_to_gray(IVC *src, IVC *dst); // transforma uma imagem RGB numa imagem cinzento (com os valores predefinidos)  Intensidade = R * 0.299 + G * 0.587 + B * 0.114   precisa tambem de uma imagem de destino(precisam de ter a mesma dimensao)
int minhacomposta_vc_rgb_to_gray(IVC *src, IVC *dst); // minha funcao igual vc_rgb_to_gray


