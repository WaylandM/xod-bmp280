
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `Adafruit_BMP280` class instance
    auto sensor = getValue<input_DEV>(ctx);
    emitValue<output_PRESS>(ctx, sensor->readTemperature());
    emitValue<output_DONE>(ctx, 1);
}
