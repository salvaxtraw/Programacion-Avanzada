from machine import Pin, I2C # Machine es la libreria base
import time # Para los delays
import ssd1306

led1 = Pin(4, Pin.OUT)
push1 = Pin(33, Pin.IN, Pin.PULL_UP)
i2c = I2C(0, sda = Pin(21), scl = Pin(22), freq = 400000)
oled = ssd1306.SSD1306_I2C(128, 64, i2c)
ultact = time.ticks_ms()
pantalla = False
timeoutms = 2000

while True:
    if push1.value() == 0:
        if not pantalla:
            oled.fill(0)
            oled.text("Hola mundo", 25, 25)
            oled.show()
            pantalla = True
        ultact = time.ticks_ms()
        time.sleep_ms(50)
    else:
        reloj = time.ticks_diff(time.ticks_ms(), ultact)
        if pantalla and reloj > timeoutms:
            oled.fill(0)
            oled.show()
            pantalla = False