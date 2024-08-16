#include <stdio.h>
#include "drivers/hardware_spi.h"
#include "drivers/st7735.h"  // 假设你使用ST7735屏幕

// TFT配置
#define TFT_WIDTH  128
#define TFT_HEIGHT 160

// SPI和TFT引脚定义
#define TFT_CS_PIN   GP23  // 示例引脚定义
#define TFT_DC_PIN   GP18
#define TFT_RST_PIN  GP19

// 创建TFT实例
st7735_config_t tft_config = {
    .cs_pin = TFT_CS_PIN,
    .dc_pin = TFT_DC_PIN,
    .rst_pin = TFT_RST_PIN,
    .spi_instance = &spi1_inst,  // RP2040使用的SPI实例
    .width = TFT_WIDTH,
    .height = TFT_HEIGHT,
};

st7735_t tft;

void keyboard_post_init_user(void) {
    // 初始化SPI
    hardware_spi_init();
    
    // 初始化TFT屏幕
    st7735_init(&tft, &tft_config);
    
    // 清屏
    st7735_fill_screen(&tft, ST7735_BLACK);
    
    // 显示一些文本
    st7735_draw_text(&tft, 0, 0, "Hello, QMK!", ST7735_WHITE, ST7735_BLACK);
}
