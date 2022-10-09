#include "common.h"

int test_num = 0;

void printHeadInfo();

void setup()
{

  delay(3000);

  // put your setup code here, to run once:
  // Sets the data rate in bits per second(baud) for Serial data transmission
  Serial.begin(115200);

  printHeadInfo();

  // need put down setup for init
  // SPIFFS is ESP32 Own FFS
}

void loop()
{
  // put your main code here, to run repeatedly:
  delay(1000);
  Serial.print(test_num++);
  Serial.print(" ");
}

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