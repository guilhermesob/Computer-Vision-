#include <opencv2/opencv.hpp>
#include <stdio.h>

int main(int argc, char** argv)
{
    // Verifica se o nome do arquivo foi passado como argumento
    if (argc != 2) {
        printf("Uso: ./EdgeDetection <caminho_da_imagem>\n");
        return -1;
    }

    // Carrega a imagem
    cv::Mat image = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);

    // Verifica se a imagem foi carregada com sucesso
    if (image.empty()) {
        printf("Erro ao abrir a imagem\n");
        return -1;
    }

    // Aplicar detecção de bordas usando Canny
    cv::Mat edges;
    cv::Canny(image, edges, 100, 200);

    // Exibir a imagem original e a imagem com as bordas detectadas
    cv::imshow("Imagem Original", image);
    cv::imshow("Bordas Detectadas", edges);

    // Espera até que uma tecla seja pressionada
    cv::waitKey(0);

    return 0;
}
