// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/adafruit/Adafruit_Sensor"
#pragma XOD require "https://github.com/adafruit/Adafruit_BMP280_Library"
#pragma XOD require "https://github.com/adafruit/Adafruit_BusIO"

//Include C++ libraries
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

node {
    meta {
        // Define our custom type as a pointer on the class instance.
        using Type = Adafruit_BMP280*;
    }

    uint8_t mem[sizeof(Adafruit_BMP280)];
    
    void evaluate(Context ctx) {
        // It should be evaluated only once on the first (setup) transaction
        if (!isSettingUp())
            return;

        auto wire = getValue<input_I2C>(ctx);
        
        // Create an object of the class Adafruit_BMP280.
        //Adafruit_BMP280 sensor = Adafruit_BMP280(wire);
        Type sensor = new (mem) Adafruit_BMP280(wire);
        emitValue<output_DEV>(ctx, sensor);
    }
}
