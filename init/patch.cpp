#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_INIT

node {
    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_INIT>(ctx))
            return;

        auto sensor = getValue<input_DEV>(ctx);
        uint8_t i2c_addr = getValue<input_ADDR>(ctx);
        
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
        emitValue<output_OK>(ctx, 1);
    }
}
