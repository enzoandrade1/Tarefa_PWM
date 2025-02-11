#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22
#define LED_PIN 12

void setup_pwm_servo() {
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);
    
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 125.f);      // Clock divisor para 1MHz
    pwm_config_set_wrap(&config, 19999);        // Período de 20ms (50Hz)
    pwm_init(slice_num, &config, true);
}

void set_servo_angle(uint pulse_us) {
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);
    uint channel = pwm_gpio_to_channel(SERVO_PIN);
    pwm_set_chan_level(slice_num, channel, pulse_us);
}

int main() {
    stdio_init_all();
    setup_pwm_servo();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Sequência de posicionamento
    set_servo_angle(2400);     // 180°
    gpio_put(LED_PIN, 1);
    sleep_ms(5000);
    
    set_servo_angle(1470);     // 90°
    gpio_put(LED_PIN, 0);
    sleep_ms(5000);
    
    set_servo_angle(500);      // 0°
    gpio_put(LED_PIN, 1);
    sleep_ms(5000);

    // Movimento contínuo suave
    uint16_t pulse = 500;
    int8_t step = 5;
    
    while(true) {
        pulse += step;
        if(pulse >= 2400 || pulse <= 500) step *= -1;
        
        set_servo_angle(pulse);
        gpio_put(LED_PIN, pulse % 100 < 50); // Piscar com PWM
        sleep_ms(10);
    }
}