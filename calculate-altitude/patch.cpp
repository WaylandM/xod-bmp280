#pragma XOD dirtieness disable

node {
    void evaluate(Context ctx) {
        float altitude;
        float pressure = getValue<input_PRESS>(ctx);
        float seaLevelhPa = getValue<input_SeaLev>(ctx);
        //pressure /= 100;
        altitude = 44330 * (1.0 - pow(pressure / seaLevelhPa, 0.1903));
        emitValue<output_ALT>(ctx, altitude);
    }
}
