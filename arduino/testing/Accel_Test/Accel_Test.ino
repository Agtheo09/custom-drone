#include <Adafruit_LSM6DS33.h>
Adafruit_LSM6DS33 meter;
sensors_event_t accel;
sensors_event_t gyro;
sensors_event_t temp;

// SPI Pins
#define ICM_CS 10
#define ICM_SCK 13
#define ICM_MISO 12
#define ICM_MOSI 11

double Ax, Ay, Az, yaw, pitch, roll;

void setup() {
  Serial.begin(9600);
  icm.begin_SPI(ICM_CS, ICM_SCK, ICM_MISO, ICM_MOSI
}

void loop() {
    meter.getEvent(&accel, &gyro, &temp);

    Ax = accel.acceleration.x;
    Ay = accel.acceleration.y;
    Az = accel.acceleration.z;

    pitch = atan2(Ax, sqrt(pow(Ay, 2) + pow(Az, 2)));
    roll = atan2(Ay, sqrt(pow(Ax, 2) + pow(Az, 2)));
    yaw = atan2(sqrt(pow(Ax, 2) + pow(Ay, 2)), Az);

    Serial.print("Pitch: ");
    Serial.println(pitch);
    Serial.print("Roll: ");
    Serial.println(roll);
    Serial.print("Yaw: ");
    Serial.println(yaw);
}