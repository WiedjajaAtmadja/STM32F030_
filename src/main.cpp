#include <Arduino.h>
#include <STM32FreeRTOS.h>

constexpr uint8_t LED_RED = PB0;
constexpr uint8_t LED_GREEN = PB1;
constexpr uint8_t ANALOG_PIN = PA0;

void taskBlink(void *pvParameters)
{
  (void)pvParameters;
  for (;;)
  {
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, LOW);
    vTaskDelay(pdMS_TO_TICKS(500));
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, HIGH);
    vTaskDelay(pdMS_TO_TICKS(500));
  }
}

void taskAnalogRead(void *pvParameters)
{
  (void)pvParameters;
  for (;;)
  {
    int analogValue = analogRead(ANALOG_PIN);
    Serial.print("Analog value: ");
    Serial.println(analogValue);
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

void setup()
{
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  Serial.begin(9600);

  xTaskCreate(taskBlink, "Blink", 128, NULL, 1, NULL);
  xTaskCreate(taskAnalogRead, "Analog", 256, NULL, 1, NULL);

  vTaskStartScheduler();
}

void loop()
{
  // tidak dipakai, scheduler FreeRTOS yang menjalankan task
}
