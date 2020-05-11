
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `Adafruit_BMP280` class instance
    auto sensor = getValue<input_DEV>(ctx);
    uint8_t mode = getValue<input_MODE>(ctx);
    uint8_t temp = getValue<input_TEMP>(ctx);
    uint8_t pressure = getValue<input_PRESS>(ctx);
    uint8_t filter = getValue<input_FILT>(ctx);
    uint8_t standby = getValue<input_STDBY>(ctx);
    sensor -> setSampling(mode, temp, pressure, filter, standby);
    emitValue<output_DONE>(ctx, 1);
}
