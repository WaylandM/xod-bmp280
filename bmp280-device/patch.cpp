// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/adafruit/Adafruit_Sensor"
#pragma XOD require "https://github.com/adafruit/Adafruit_BMP280_Library"
#pragma XOD require "https://github.com/adafruit/Adafruit_BusIO"

//Include C++ libraries
{{#global}}
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
{{/global}}

// Reserve memory to store an instance of the Adafruit_BMP280 class,
// and create the instance later:
struct State {
    uint8_t mem[sizeof(Adafruit_BMP280)];
};

// Define our custom type as a pointer on the class instance.
using Type = Adafruit_BMP280*;

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // It should be evaluated only once on the first (setup) transaction
    if (!isSettingUp())
        return;

    auto state = getState(ctx);
    auto wire = getValue<input_I2C>(ctx);
    uint8_t i2c_addr = getValue<input_ADDR>(ctx);

    // Create a new object in the memory area reserved previously.
    Type sensor = new (state->mem) Adafruit_BMP280(wire);

    if (!sensor->begin(i2c_addr, BMP280_CHIPID)) {
      raiseError(ctx);
      return;
    }
    uint8_t mode = getValue<input_MODE>(ctx);
    uint8_t temp = getValue<input_OST>(ctx);
    uint8_t pressure = getValue<input_OSP>(ctx);
    uint8_t filter = getValue<input_FILT>(ctx);
    uint8_t standby = getValue<input_STDBY>(ctx);
    sensor -> setSampling(mode, temp, pressure, filter, standby);
    emitValue<output_DEV>(ctx, sensor);
}
