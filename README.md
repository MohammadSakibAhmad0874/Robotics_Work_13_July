# Robotics_Work_13_July
Friday work using 2 ir sensor with one buzzer
# Arduino Distance Detection System
![Exquisite Esboo (1)](https://github.com/user-attachments/assets/cc77b104-b86d-49ae-9e87-343074c8a6fa)


## Overview
This project implements a distance detection system using an Arduino Uno that reads signals from two input sensors and provides different responses based on the combination of sensor states. The system categorizes distances into four levels and controls an output device accordingly.

## Circuit Diagram
The circuit consists of:
- Arduino Uno microcontroller
- Two input sensors connected to digital pins 2 and 3
- One output device (LED/buzzer) connected to digital pin 4
- Breadboard for connections
- Connecting wires

## Components Required
- 1x Arduino Uno
- 2x Digital sensors (IR sensors, proximity sensors, or switches)
- 1x LED or Buzzer (output device)
- 1x Breadboard
- Jumper wires
- 1x Resistor (220Ω for LED, if using LED)

## Pin Configuration
| Component | Arduino Pin | Description |
|-----------|-------------|-------------|
| Sensor 1  | Digital Pin 2 | Input sensor (INPUT mode) |
| Sensor 2  | Digital Pin 3 | Input sensor (INPUT mode) |
| Output Device | Digital Pin 4 | LED/Buzzer (OUTPUT mode) |

## Circuit Connections
1. Connect the first sensor's output to Arduino digital pin 2
2. Connect the second sensor's output to Arduino digital pin 3
3. Connect the output device (LED/buzzer) to Arduino digital pin 4
4. Ensure proper power (5V/3.3V) and ground connections for all components
5. If using an LED, connect a 220Ω resistor in series

## Code Functionality
The system operates with four distinct distance states based on the combination of two sensor readings:

### Distance States
| Sensor 1 | Sensor 2 | Distance Level | Output Pin 4 | Serial Output |
|----------|----------|----------------|--------------|---------------|
| LOW (0)  | LOW (0)  | Distance 1     | No change    | "distance 1"  |
| LOW (0)  | HIGH (1) | Distance 2     | No change    | "distance 2"  |
| HIGH (1) | LOW (0)  | Distance 3     | LOW          | "distance 3"  |
| HIGH (1) | HIGH (1) | Distance 4     | HIGH         | "distance 4"  |

### Code Logic
- **Distance 1**: Both sensors inactive (closest range)
- **Distance 2**: Only sensor 2 active (medium-close range)
- **Distance 3**: Only sensor 1 active (medium-far range) - Output device OFF
- **Distance 4**: Both sensors active (farthest range) - Output device ON

## Setup Instructions
1. **Hardware Setup**:
   - Assemble the circuit according to the diagram
   - Double-check all connections
   - Ensure Arduino is properly connected to your computer

2. **Software Setup**:
   - Open Arduino IDE
   - Copy and paste the provided code
   - Select the correct board (Arduino Uno)
   - Select the correct COM port
   - Upload the code to Arduino

3. **Testing**:
   - Open Serial Monitor (Ctrl+Shift+M or Tools > Serial Monitor)
   - Set baud rate to 9600
   - Observe the distance readings as sensors are triggered

## Code Explanation
```cpp
void setup()
{
  Serial.begin(9600);     // Initialize serial communication
  pinMode(2,INPUT);       // Set pin 2 as input for sensor 1
  pinMode(3,INPUT);       // Set pin 3 as input for sensor 2
  pinMode(4,OUTPUT);      // Set pin 4 as output for LED/buzzer
}

void loop(){
  int signal1=digitalRead(2);  // Read sensor 1 state
  int signal2=digitalRead(3);  // Read sensor 2 state
  
  // Check all possible combinations and respond accordingly
  if(signal1==0 && signal2==0){
    Serial.println("distance 1");
  }
  else if(signal1==0 && signal2==1){
    Serial.println("distance 2");
  }
  else if(signal1==1 && signal2==0){
    Serial.println("distance 3");
    digitalWrite(4, LOW);      // Turn off output device
  }
  else if(signal1==1 && signal2==1){
    Serial.println("distance 4");
    digitalWrite(4, HIGH);     // Turn on output device
  }
}
```

## Applications
- Proximity detection systems
- Parking sensors
- Security systems
- Interactive displays
- Robotics obstacle detection

## Troubleshooting
- **No serial output**: Check baud rate (should be 9600)
- **Sensors not responding**: Verify power and ground connections
- **Output device not working**: Check pin 4 connections and device functionality
- **Inconsistent readings**: Add delays or debouncing logic if needed

## Possible Improvements
- Add delay between readings for stability
- Implement sensor debouncing
- Add more sophisticated distance calculations
- Include visual indicators for each distance level
- Add data logging capabilities

## License
This project is open-source and available for educational and personal use.

## Author
Created for Arduino distance detection learning purposes.
