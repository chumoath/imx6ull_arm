#include "imx6ul.h"
#include "bsp_clk.h"
#include "bsp_delay.h"

/*
# 必须是 内核加载的地址，而不是 uboot 加载的地址
#     因为使用的是 go 命令
#     可以自定义位置，因为已经启动了

  编完必须清除掉，否则修改 imx6ul.lds 不会更新 i2c.elf 和 i2c.bin

  可以考虑将 imx6ul.lds 加入依赖，这样 imx6ul.lds 更新，也会导致 目标更新
*/
void main()
{
    clk_enable();
    delay_init();

//    IOMUXC_SetPinMux(IOMUXC_GPIO1_IO03_GPIO1_IO03,0);
//    IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO03_GPIO1_IO03,0X10B0);
//
//    // 输入
//    GPIO1->GDIR &= ~(1 << 3);

    /*
    // 默认不亮
    GPIO1->DR |= (1 << 3);

    delayms(1000);

    GPIO1->DR &= ~(1 << 3);
    */

    // 将 引出的 uart4_tx pin 复用为  gpio28，即该管脚由 imx6ull 的 gpio28 控制

    //                     若复用为  i2c1_scl，即该管脚由 imx6ull 的 i2c1_scl 控制
    IOMUXC_SetPinMux(IOMUXC_UART4_TX_DATA_GPIO1_IO28,0);
    IOMUXC_SetPinConfig(IOMUXC_UART4_TX_DATA_GPIO1_IO28, 0X10B0);

    // 输出
    GPIO1->GDIR |= (1 << 28);

    // LED0 应该点亮， 因为 uart4_tx 和 gpio3 连在一起
    while (1) {

        // 输出低电平 -> 亮
        GPIO1->DR &= ~(1 << 28);

        delayms(1000);

        // 输出高电平 -> 灭
        GPIO1->DR |= (1 << 28);
    }
}