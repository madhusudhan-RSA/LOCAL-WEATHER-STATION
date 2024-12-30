# Arduino Weather Station

This is a simple **Arduino-based Weather Station** that monitors and displays environmental conditions such as temperature, humidity, and atmospheric pressure. The data is displayed on a 16x2 I2C LCD, and it can also be monitored via Bluetooth.

## Features

- **Temperature and Humidity Monitoring**: Measures temperature and humidity using the DHT11 sensor.
- **Atmospheric Pressure Measurement**: Monitors pressure with the BMP280 sensor.
- **Real-Time Display**: Displays data on a 16x2 I2C LCD.
- **Bluetooth Connectivity**: Transmits data to a Bluetooth-enabled device for remote monitoring.

## Applications

1. **Home Automation**: Use weather data to control HVAC systems or water sprinklers automatically.
2. **Agriculture**: Monitor field conditions to optimize irrigation and crop care.
3. **Educational Projects**: Teach students about IoT, sensors, and Arduino programming.
4. **Outdoor Installations**: Use in gardens, greenhouses, or parks to monitor environmental conditions.
5. **Weather Research**: Gather local environmental data for research and analysis.

## Hardware Requirements

| Component            | Description                           |
|----------------------|---------------------------------------|
| Arduino Board         | Compatible with Uno, Mega, etc.      |
| DHT11 Sensor          | Measures temperature and humidity.   |
| BMP280 Sensor         | Measures atmospheric pressure.       |
| I2C LCD (16x2)        | Displays data in real-time.          |
| Bluetooth Module      | HC-05 or HC-06 for wireless data.    |
| Jumper Wires & Breadboard | For connections.                 |

## Wiring Details

| Component         | Arduino Pin      | Notes                         |
|-------------------|------------------|-------------------------------|
| DHT11 Data Pin    | 2                | Digital pin (DHTPIN).         |
| BMP280 SDA        | A4 (Uno) / 20 (Mega) | I2C Data pin.              |
| BMP280 SCL        | A5 (Uno) / 21 (Mega) | I2C Clock pin.             |
| I2C LCD SDA       | A4 (Uno) / 20 (Mega) | Shared with BMP280 SDA.    |
| I2C LCD SCL       | A5 (Uno) / 21 (Mega) | Shared with BMP280 SCL.    |
| Bluetooth TX      | RX1 (Mega)       | Adjust for your Arduino model.|
| Bluetooth RX      | TX1 (Mega)       | Adjust for your Arduino model. |

## Software Requirements

1. Install the **Arduino IDE** ([Download Here](https://www.arduino.cc/en/software)).
2. Install the following libraries via the Library Manager:
   - `Adafruit_Sensor`
   - `Adafruit_BMP280`
   - `DHT`
   - `LiquidCrystal_I2C`

## How to Use

### 1. Assemble the Hardware
- Connect all components as per the wiring table above.
- Ensure the sensors and modules are connected securely.

### 2. Set Up the Software
- Open the Arduino IDE on your computer.
- Install the required libraries from the **Library Manager** (see **Software Requirements** section).
- Copy and paste the provided code into the Arduino IDE.

### 3. Upload the Code
- Connect your Arduino board to your computer via USB.
- Select the correct board and COM port from the **Tools** menu in the Arduino IDE.
- Click the **Upload** button to upload the code.

### 4. Monitor Data
- **Serial Monitor**: Open the Serial Monitor in the Arduino IDE to view the sensor readings (set the baud rate to 9600).
- **LCD Display**: Observe real-time data on the I2C LCD.
- **Bluetooth**: Use a Bluetooth terminal app on your smartphone or computer to view real-time data remotely.
  - Pair your device with the Bluetooth module (default pin: `1234` or `0000`).
  - Open the app and set the baud rate to 9600.
