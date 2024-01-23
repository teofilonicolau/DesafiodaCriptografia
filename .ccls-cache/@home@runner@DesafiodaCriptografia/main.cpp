#include <stdio.h>


unsigned char inverterBits(unsigned char byte) {
    return byte ^ 0b00000011;
}


unsigned char trocarBits(unsigned char byte) {
    return ((byte & 0b11110000) >> 4) | ((byte & 0b00001111) << 4);
}


void descriptografarMensagem(unsigned char mensagem[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        mensagem[i] = trocarBits(inverterBits(mensagem[i]));
    }
}


void imprimirMensagem(unsigned char mensagem[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%c", mensagem[i]);
    }
    printf("\n");
}

int main() {
    unsigned char mensagem[] = {0b10010110, 0b11110111, 0b01010110, 0b00000001, 0b00010111, 0b00100110, 0b01010111, 0b00000001, 0b00010111, 0b01110110, 0b01010111, 0b00110110, 0b11110111, 0b11010111, 0b01010111, 0b00000011};
    int tamanho = sizeof(mensagem) / sizeof(mensagem[0]);

    descriptografarMensagem(mensagem, tamanho);
    imprimirMensagem(mensagem, tamanho);

    return 0;
}
