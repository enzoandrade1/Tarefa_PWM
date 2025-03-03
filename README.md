# Controle de Servomotor via PWM no Raspberry Pi Pico W

Este projeto demonstra o controle de um servomotor utilizando o módulo PWM do microcontrolador Raspberry Pi Pico W. O código foi desenvolvido com o Pico SDK e simula o controle do ângulo de um servomotor padrão, como o disponível no simulador de eletrônica online Wokwi.

## 📌 Descrição do Projeto
O projeto utiliza o módulo PWM do RP2040 para gerar sinais de controle para um servomotor. O sinal PWM é configurado para uma frequência de **50Hz (período de 20ms)**, que é a frequência padrão para a maioria dos servomotores. O ciclo ativo do sinal PWM é ajustado para posicionar o servomotor em diferentes ângulos (**0°, 90° e 180°**). Após posicionar o servomotor nessas posições, o código realiza uma movimentação suave e periódica do braço do servomotor entre **0° e 180°**.

## 🔧 Componentes Utilizados
- **Microcontrolador**: Raspberry Pi Pico W.
- **Servomotor**: Motor micro servo padrão (simulado no Wokwi).
- **LED RGB**: Utilizado para observação do comportamento do PWM (**GPIO 12**).

## 📌 Requisitos do Projeto
### Configuração do PWM:
- Frequência de **50Hz** (período de 20ms).
- **GPIO 22** configurada como saída PWM.

### Posicionamento do Servomotor:
- **180°**: Ciclo ativo de **2400µs (12% do ciclo).**
- **90°**: Ciclo ativo de **1470µs (7.35% do ciclo).**
- **0°**: Ciclo ativo de **500µs (2.5% do ciclo).**
- Cada posição é mantida por **5 segundos**.

### Movimento Suave:
- O braço do servomotor se move suavemente entre **0° e 180°**.
- Incremento de ciclo ativo de **±5µs** com um atraso de **10ms** entre cada ajuste.

### Comportamento do LED RGB:
- O **LED RGB (GPIO 12)** pisca ritmicamente durante o movimento do servomotor, demonstrando a correlação entre o sinal PWM e o controle do servo.

### Simulação no Wokwi:
1. Utilize o simulador **Wokwi** para testar o circuito com o servomotor padrão.
2. Conecte o **GPIO 22** ao sinal de controle do servomotor e o **GPIO 12** ao LED RGB.

### Execução:
- O servomotor começará a se mover entre as posições de **0°, 90° e 180°**, com uma pausa de **5 segundos** em cada posição.
- Após isso, o servomotor realizará uma **movimentação suave e periódica** entre **0° e 180°**.

## 💾 Código
O código-fonte está disponível no arquivo **`Tarefa_PWM.c`**. Ele inclui:
- Configuração do PWM para **50Hz**.
- Funções para **posicionar o servomotor** em ângulos específicos.
- Rotina para **movimentação suave** do servomotor.
- Controle do **LED RGB** para observação do comportamento do PWM.

## 📂 Estrutura do Projeto
```bash
Tarefa_PWM/
├── CMakeLists.txt
├── Tarefa_PWM.c
├── README.md
└── LICENSE
```

## 🔗 Links Úteis
- [Documentação do Pico SDK](https://github.com/raspberrypi/pico-sdk)
- [Simulador Wokwi](https://wokwi.com/)
- [Vídeo explicativo do projeto](https://drive.google.com/file/d/1doW__EMbBZ9JCCVLZlXGkBsbsMOe_ZrL/view)