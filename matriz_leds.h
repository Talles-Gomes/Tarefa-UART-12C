// Definição de tipo da estrutura que irá controlar a cor dos LED's
typedef struct {
    double red;
    double green;
    double blue;
}Led_config;

typedef Led_config RGB_cod;
// Definição de tipo da matriz de leds
typedef Led_config Matriz_leds_config[5][5]; 

uint32_t gerar_binario_cor(double red, double green, double blue);
uint configurar_matriz(PIO pio);

void imprimir_desenho(Matriz_leds_config configuracao, PIO pio, uint sm);
//matrizes de 0 a 9

void num0(PIO pio, uint sm);
void num1(PIO pio, uint sm);
void num2(PIO pio, uint sm);
void num3(PIO pio, uint sm);
void num4(PIO pio, uint sm);
void num5(PIO pio, uint sm);
void num6(PIO pio, uint sm);
void num7(PIO pio, uint sm);
void num8(PIO pio, uint sm);
void num9(PIO pio, uint sm);
void apagar(PIO pio, uint sm);
