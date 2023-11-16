#include <Pololu3pi>
#include <OrangutanAnalog.h>

Pololu3pi robot;

unsigned int sensorValues[NUM_SENSORS];
unsigned int minSensorValues[NUM_SENSORS];
unsigned int maxSensorValues[NUM_SENSORS];

void calibrateSensors() {
    // Rotate robot over line and record min/max values
    for (int i = 0; i < NUM_CALIBRATION_LOOPS; i++) {
        // Move robot...
        robot.readLineSensors(sensorValues);
        // Update min/max for each sensor...
    }
    // Store calibrated values...
}

unsigned int filteredReadings[NUM_SENSORS];

void filterSensors() {
    // Apply running average filter
    for (int i = 0; i < NUM_SENSORS; i++) {
        filteredReadings[i] = (filteredReadings[i] * (FILTER_WEIGHT - 1) + sensorValues[i]) / FILTER_WEIGHT;
    }
}

void setup() {
    // Initialization code
    calibrateSensors();
}

void loop() {
    // Regular operation
    robot.readLineSensors(sensorValues);
    filterSensors();
    // Use filtered readings for line following logic...
}
