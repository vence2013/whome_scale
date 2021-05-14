
1. 添加I2CSPM组件
2. 配置组件。
使用I2C1，管脚复用功能为：SCL/PD0, SDA/PD01。
添加的代码在：gecko_sdk_3.1.1/platform/driver/i2cspm。




[SiliconLabs / peripheral_examples](https://github.com/SiliconLabs/peripheral_examples/blob/master/series1/i2c/i2c/src/main_efr.c)








------------------
SSD1306控制过程
1. 0XAE：关闭显示



0X40/B0设置列地址的低字节/高字节
