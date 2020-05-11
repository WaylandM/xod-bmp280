// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/adafruit/Adafruit_Sensor"
#pragma XOD require "https://github.com/adafruit/Adafruit_BMP280_Library"

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

    // Create a new object in the memory area reserved previously.
    Type sensor = new (state->mem) Adafruit_BMP280();

    if (!sensor->begin()) {
      raiseError(ctx);
      return;
    }

    emitValue<output_DEV>(ctx, sensor);

}
