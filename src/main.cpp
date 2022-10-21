#include "common.h"
#include "test_tft_espi.h"
#include "test_lvgl.h"
#include "driver/imu.h"

int test_num = 0;
IMU mpu;
Imu_Action *act_info; // 存放mpu6050返回的数据

void printHeadInfo();
void testlib();
void testlibInit();

void setup()
{

  delay(3000);

  // put your setup code here, to run once:
  // Sets the data rate in bits per second(baud) for Serial data transmission
  Serial.begin(115200);
  printHeadInfo();
  config_read(NULL, &g_cfg); // read Flash paramaeters in pres

  /*** Init screen ***/
  screen.init();

  /*** Init IMU as input device ***/
  mpu.init();

  // need put down setup for init
  // SPIFFS is ESP32 Own FFS

  // ------------- for test
  // testlibInit();
}

void loop()
{
  // put your main code here, to run repeatedly:

  // while (1)
  // {
  //   delay(1000);
  //   Serial.print(test_num++);
  //   Serial.print(" ");
  //   // testlib();

  // }
  screen.routine();
  act_info = mpu.update(300);
}

/* -------------------for test----------------------- */

void printHeadInfo()
{
  // https://arduinogetstarted.com/faq/what-is-serial.println-f
  // The F() macro helps save SRAM memory by moving the constant string from SRAM to FLASH memory.  一级缓存 --> 内存 --> 硬盘 (SRAM --> DRAM --> FLASH)
  Serial.println(F("\nAIO (All in one) version " AIO_VERSION "\n"));

  // MAC ID可用作芯片唯一标识
  Serial.print(F("ChipID(EfuseMac): "));
  Serial.println(ESP.getEfuseMac());

  Serial.print(F("CpuFreqMHz: "));
  Serial.println(ESP.getCpuFreqMHz());

  Serial.print(F("FlashChipMode: "));
  Serial.println(ESP.getFlashChipMode());
  Serial.println(F("FlashChipMode value: FM_QIO = 0, FM_QOUT = 1, FM_DIO = 2, FM_DOUT = 3, FM_FAST_READ = 4, FM_SLOW_READ = 5, FM_UNKNOWN = 255"));
}

void testlib()
{
  // Serial.println(F("TEST ALL LIB IS OK:  --------- START"));

  // test_TFT_ESPI();
  // show_String(test_num);
  // show_Number(test_num);
  // show_xbm();
  // show_chinese();
  // lv_task_handler(); // 这个代码必现加, 不然不能显示
  lv_timer_handler(); // 这个代码必现加, 不然不能显示
  // setWidgetState(test_num);
  // Serial.println(F("TEST ALL LIB IS OK:  --------- END"));
}

void testlibInit()
{
  /* ------------- test TFT_ESPI start ------------- */
  // test_TFT_ESPI_init();
  // test_TFT_ESPI();
  // // show_img();
  /* -------------  test TFT_ESPI end ------------- */

  /* ------------- test lvgl start ------------- */
  test_lvgl_init();
  test_lvgl_button();
  /* ------------- test lvgl end ------------- */
}