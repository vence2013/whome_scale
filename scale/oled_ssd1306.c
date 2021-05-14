#include "sl_i2cspm_instances.h"


#define OLED_I2C_ADDRESS                                         0X78


void delay(int x)
{
  int i, j;

  for (i = 0; i < x; i++)
    for (j = 0; j < 1000; j++) ;
}


/* cmd: 命令
 * para: 参数
 * len : 参数字节数
 */
int i2c_cmd(char cmd, char* para, char len)
{
  uint8_t i, bytes[10], ctl[] = {0};
  I2C_TransferSeq_TypeDef seq = {
      .addr  = OLED_I2C_ADDRESS,
      .flags = I2C_FLAG_WRITE_WRITE,
      .buf   = {
          {.data = ctl,   .len = 1},
          {.data = bytes, .len = 1+len}
      }
  };

  bytes[0] = cmd;
  for (i = 0; i < len; i++)
    bytes[i+1] = para[i];

  return (int)I2CSPM_Transfer(sl_i2cspm_oled_i2c, &seq);
}

int i2c_data(char dat)
{
  uint8_t ctl[] = {0x40}, bytes[] = {0};
  I2C_TransferSeq_TypeDef seq = {
      .addr  = OLED_I2C_ADDRESS,
      .flags = I2C_FLAG_WRITE_WRITE,
      .buf   = {
          {.data = ctl,   .len = 1},
          {.data = bytes, .len = 1}
      }
  };

  bytes[0] = dat;
  return (int)I2CSPM_Transfer(sl_i2cspm_oled_i2c, &seq);
}


void ssd1306_clear( void )
{
  int i, j;

  for (i = 0; i < 8; i++) // page
  {
      i2c_cmd(0xb0+i, 0, 0);  // 设置页地址
      i2c_cmd(0x00, 0, 0);
      i2c_cmd(0x10, 0, 0);

      for (j = 0; j < 128; j++)
        i2c_data(0x5);
  }
}

/* 1. 配置驱动的行数
 * 2. 测试打开整个显示屏
 * */
void cfg_all_on( void )
{
  char para[4];

  // 设置驱动的路数，0.91寸的显示屏最大好像是32
  para[0] = 0x20;
  i2c_cmd(0XA8, para, 1);

  // 不管显示内存RAM的内容，直接打开整个显示
  i2c_cmd(0xA5, 0, 0);
}

void cfg_normal( void )
{
  char para[4];

  // 设置驱动的路数，0.91寸的显示屏最大好像是32
  para[0] = 0x20;
  i2c_cmd(0XA8, para, 1);

  // 不管显示内存RAM的内容，直接打开整个显示
  i2c_cmd(0xA4, 0, 0);
}

void oled_ssd1306_init( void )
{
  delay(100);
  // 关闭显示
  i2c_cmd(0xAE, 0, 0);

  // cfg_all_on();
  cfg_normal();
  ssd1306_clear();

  // 打开显示
  i2c_cmd(0XAF, 0, 0);
}
