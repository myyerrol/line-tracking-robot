#include "RVStarArduino.h"

static const uint32_t GPIO_CLK_ARR[] = {
    RCU_GPIOC,
    RCU_GPIOC,
    RCU_GPIOC,
    RCU_GPIOC,
    RCU_GPIOA,
    RCU_GPIOB,
    RCU_GPIOB,
    RCU_GPIOB,
    RCU_GPIOB,
    RCU_GPIOB,
    RCU_GPIOB,
    RCU_GPIOA,
    RCU_GPIOA,
    RCU_GPIOA,
    RCU_GPIOC,
    RCU_GPIOC,
    RCU_GPIOC,
    RCU_GPIOC,
    RCU_GPIOC,
    RCU_GPIOC
};
static const uint32_t GPIO_PORT_ARR[] = {
    GPIOC,
    GPIOC,
    GPIOC,
    GPIOC,
    GPIOA,
    GPIOB,
    GPIOB,
    GPIOB,
    GPIOB,
    GPIOB,
    GPIOB,
    GPIOA,
    GPIOA,
    GPIOA,
    GPIOC,
    GPIOC,
    GPIOC,
    GPIOC,
    GPIOC,
    GPIOC
};
static const uint32_t GPIO_PIN_ARR[] = {
    GPIO_PIN_11,
    GPIO_PIN_10,
    GPIO_PIN_8,
    GPIO_PIN_9,
    GPIO_PIN_8,
    GPIO_PIN_1,
    GPIO_PIN_0,
    GPIO_PIN_5,
    GPIO_PIN_6,
    GPIO_PIN_8,
    GPIO_PIN_9,
    GPIO_PIN_7,
    GPIO_PIN_6,
    GPIO_PIN_5,
    GPIO_PIN_0,
    GPIO_PIN_1,
    GPIO_PIN_2,
    GPIO_PIN_3,
    GPIO_PIN_4,
    GPIO_PIN_5
};
static const uint8_t GPIO_MODE_ARR[] = {
    GPIO_MODE_IN_FLOATING, // 浮动输入模式 Floating input mode
    GPIO_MODE_OUT_PP,      // 推挽输出模式 Push-pull output mode
    GPIO_MODE_IPU,         // 上拉输入模式 Pull-up input mode
};
// Arduino Pin 3  => RV-STAR TIMER2_CH3
// Arduino Pin 5  => RV-STAR TIMER2_CH3/TIMER0_CH2_ON
// Arduino Pin 6  => RV-STAR TIMER2_CH2
// Arduino Pin 9  => RV-STAR TIMER3_CH2
// Arduino Pin 10 => RV-STAR TIMER3_CH3
// Arduino Pin 11 => RV-STAR TIMER2_CH1/TIMER0_CH0_ON
static const uint32_t TIMER_GPIO_CLK_ARR[] = {
    0,
    0,
    0,
    RCU_GPIOC,
    0,
    RCU_GPIOB,
    RCU_GPIOB,
    0,
    0,
    RCU_GPIOB,
    RCU_GPIOB,
    RCU_GPIOA
};
static const uint32_t TIMER_GPIO_PORT_ARR[] = {
    0,
    0,
    0,
    GPIOC,
    0,
    GPIOB,
    GPIOB,
    0,
    0,
    GPIOB,
    GPIOB,
    GPIOA
};
static const uint32_t TIMER_GPIO_PIN_ARR[] = {
    0,
    0,
    0,
    GPIO_PIN_9,
    0,
    GPIO_PIN_1,
    GPIO_PIN_0,
    0,
    0,
    GPIO_PIN_8,
    GPIO_PIN_9,
    GPIO_PIN_7
};
static const uint32_t TIMER_CLK_ARR[] = {
    0,
    0,
    0,
    RCU_TIMER2,
    0,
    RCU_TIMER0,
    RCU_TIMER2,
    0,
    0,
    RCU_TIMER3,
    RCU_TIMER3,
    RCU_TIMER2
};
static const uint32_t TIMER_ARR[] = {
    0,
    0,
    0,
    TIMER2,
    0,
    TIMER0,
    TIMER2,
    0,
    0,
    TIMER3,
    TIMER3,
    TIMER2
};
static const uint32_t TIMER_CH_ARR[] = {
    0,
    0,
    0,
    TIMER_CH_3,
    0,
    TIMER_CH_3,
    TIMER_CH_2,
    0,
    0,
    TIMER_CH_2,
    TIMER_CH_3,
    TIMER_CH_1
};
static const uint32_t TIMER_FLAG_ARR[] = {
    0,
    0,
    0,
    TIMER_FLAG_CH3,
    0,
    TIMER_FLAG_CH3,
    TIMER_FLAG_CH2,
    0,
    0,
    TIMER_FLAG_CH2,
    TIMER_FLAG_CH3,
    TIMER_FLAG_CH1
};

void initTimerPWMMode(uint8_t pin) {
    uint32_t timer_gpio_clk  = TIMER_GPIO_CLK_ARR[pin];
    uint32_t timer_gpio_port = TIMER_GPIO_PORT_ARR[pin];
    uint32_t timer_gpio_pin  = TIMER_GPIO_PIN_ARR[pin];
    uint32_t timer_clk       = TIMER_CLK_ARR[pin];
    uint32_t timer           = TIMER_ARR[pin];
    uint32_t timer_ch        = TIMER_CH_ARR[pin];

    // 配置定时器端口与备用功能时钟
    // Configure timer pin and alternate function clock
    rcu_periph_clock_enable(timer_gpio_clk);
    rcu_periph_clock_enable(RCU_AF);

    // 初始化定时器GPIO参数
    // Initialize timer gpio parameter
    gpio_init(timer_gpio_port, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ,
              timer_gpio_pin);

    timer_oc_parameter_struct timer_ocinitpara;
    timer_parameter_struct    timer_initpara;

    // 配置定时器时钟并重置定时器
    // Configure timer clock and reset timer
    rcu_periph_clock_enable(timer_clk);
    timer_deinit(timer);

    // 初始化定时器初始参数结构
    // Initialize timer init parameter struct
    timer_struct_para_init(&timer_initpara);
    // 配置定时器初始参数
    // Configure timer init parameter
    timer_initpara.prescaler         = 107;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 254;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(timer, &timer_initpara);

    // 初始化定时器通道输出参数结构
    // Initialize timer channel output parameter struct
    timer_channel_output_struct_para_init(&timer_ocinitpara);
    // 配置定时器通道输出参数（PWM模式）
    // Configure timer channel output parameter(PWM mode)
    timer_ocinitpara.outputstate  = TIMER_CCX_ENABLE;
    timer_ocinitpara.outputnstate = TIMER_CCXN_DISABLE;
    timer_ocinitpara.ocpolarity   = TIMER_OC_POLARITY_HIGH;
    timer_ocinitpara.ocnpolarity  = TIMER_OCN_POLARITY_HIGH;
    timer_ocinitpara.ocidlestate  = TIMER_OC_IDLE_STATE_LOW;
    timer_ocinitpara.ocnidlestate = TIMER_OCN_IDLE_STATE_LOW;

    // 启动定时器通道输出
    // Enable timer output
    timer_channel_output_config(timer, timer_ch, &timer_ocinitpara);

    // 配置定时器通道为PWM0模式
    // Configure timer channel in PWM0 mode
    timer_channel_output_pulse_value_config(timer, timer_ch, 255);
    timer_channel_output_mode_config(timer, timer_ch, TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(timer, timer_ch, TIMER_OC_SHADOW_DISABLE);

    // 启动定时器自动重新加载功能
    // Enable timer auto reload shadow function
    timer_auto_reload_shadow_enable(timer);
    // 启动定时器
    // Enable timer
    timer_enable(timer);
}

// int analogRead(uint8_t pin) {

// }

// void analogReference(uint8_t mode) {

// }

void analogWrite(uint8_t pin, int val) {
    uint32_t timer      = TIMER_ARR[pin];
    uint32_t timer_ch   = TIMER_CH_ARR[pin];
    uint32_t timer_flag = TIMER_FLAG_ARR[pin];

    // 如果定时器通道未初始化，则先初始化定时器通道为PWM模式
    // If timer channel is not initialized, initialize timer channel to PWM mode
    if (timer_flag_get(timer, timer_flag) == RESET) {
        initTimerPWMMode(pin);
    }

    // 配置定时器通道输出脉冲值
    // Configure timer channel output pulse value
    timer_channel_output_pulse_value_config(timer, timer_ch, (255 - val));
}

int digitalRead(uint8_t pin) {
    uint32_t gpio_port = GPIO_PORT_ARR[pin];
    uint32_t gpio_pin  = GPIO_PIN_ARR[pin];
    return gpio_input_bit_get(gpio_port, gpio_pin);
}

void digitalWrite(uint8_t pin, uint8_t val) {
    uint32_t gpio_port = GPIO_PORT_ARR[pin];
    uint32_t gpio_pin  = GPIO_PIN_ARR[pin];
    gpio_bit_write(gpio_port, gpio_pin, val);
}

void pinMode(uint8_t pin, uint8_t mode) {
    uint32_t gpio_clk  = GPIO_CLK_ARR[pin];
    uint32_t gpio_port = GPIO_PORT_ARR[pin];
    uint32_t gpio_pin  = GPIO_PIN_ARR[pin];
    uint8_t  gpio_mode = GPIO_MODE_ARR[mode];

    rcu_periph_clock_enable(gpio_clk);
    gpio_init(gpio_port, gpio_mode, GPIO_OSPEED_50MHZ, gpio_pin);
    gpio_bit_write(gpio_port, gpio_pin, RESET);
}

void delay(unsigned long ms) {
    delay_1ms(ms);
}

void delayMicroseconds(unsigned int us) {
    delay_1ms(us / 1000000);
}
