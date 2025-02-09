#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "matriz_leds.h"
#include "pico/bootrom.h"
#include "hardware/timer.h"

#define Tempo_led 100 
const uint led_R = 13;
const uint botA = 5;
const uint botB = 6;
int leitura = 0;

static void gpio_irq_handler(uint gpio,uint32_t events);
static volatile uint32_t last_time = 0;
void acionar_led_vermelho() 
{ 
    gpio_put(led_R, 1);
    sleep_ms(Tempo_led);
    gpio_put(led_R, 0);
    sleep_ms(Tempo_led);
}
void gpio_irq_handler(uint gpio,uint32_t events)
    {
        uint32_t current_time = to_us_since_boot(get_absolute_time());
        if(current_time - last_time > 200000) // 200 ms de debouncing
        {
            last_time = current_time;
            if(gpio == 5 && leitura < 9){
                leitura++;
            }
            if (gpio == 6 && leitura > 0)
            {
                leitura--;
            }
        }

    }
int main()
{
    PIO pio = pio0;
    uint sm = configurar_matriz(pio);

    gpio_init(led_R);
    gpio_set_dir(led_R, GPIO_OUT);

    gpio_init(botA);
    gpio_set_dir(botA, GPIO_IN);
    gpio_pull_up(botA);

    gpio_init(botB);
    gpio_set_dir(botB, GPIO_IN);
    gpio_pull_up(botB);

    gpio_set_irq_enabled_with_callback(botA,GPIO_IRQ_EDGE_FALL,true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(botB,GPIO_IRQ_EDGE_FALL,true, &gpio_irq_handler);
    while (true)
    {
        acionar_led_vermelho();
        switch(leitura)
        {
            case 0 :
                num0(pio, sm); // número 0
                break;
            case 1 :
                num1(pio, sm);// número 1
                break;
            case 2 :
                num2(pio, sm); // número 2
                break;
            case 3 :
                num3(pio, sm); // número 3
                break;
            case 4 :
                num4(pio,sm); // número 4
                break;
            case 5 :
                num5(pio, sm); // número 5
                break;
            case 6 :
                num6(pio, sm); // número 6
                break;
            case 7 :
                num7(pio, sm); // número 7
                break;
            case 8 :
                num8(pio, sm); // número 8
                break;
            case 9 :
                num9(pio, sm); // número 9
                break;

        }
    }
}
