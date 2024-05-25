# NEED4STEK: Autonomous Car Project

## Overview
The NEED4STEK project involves designing and implementing an autonomous car that can navigate tracks autonomously without hitting walls or driving off-course. The project uses C programming language and is compiled using a Makefile that includes rules for `re`, `clean`, and `fclean`.

## Requirements
- **Binary Name:** `ai`
- **Language:** C
- **Compilation:** Makefile with `re`, `clean`, and `fclean` rules
- **Authorized Functions:** All functions from the standard C library and math library.

## Tools
- **CoppeliaSim:** A robot simulator by Coppelia Robotics, used for creating and controlling the autonomous car.

## Features
1. **Simulation Management**: The code handles starting and stopping the simulation, ensuring that the environment is active only during the control operations and is safely shut down afterwards.

2. **Car Movement Control**: It directs the car to move forwards or backwards at varying speeds based on environmental data received from sensors.

3. **Steering Control**: The steering direction of the car is adjusted based on sensor inputs which detect obstacles or road conditions directly and to the sides of the car. This helps the car to avoid collisions and maintain its path on the track.

4. **Sensor Data Utilization**: The code uses data from sensors like LIDAR to make real-time decisions about speed and direction.

5. **Continuous Updates and Adjustments**: Through a loop of continuous updates, the car's movements are frequently adjusted based on new sensor readings.

6. **Output and Debugging Information**: The system provides real-time feedback on the operations being performed, such as the current speed and steering angle, which aids in monitoring and debugging the simulation.

Overall, these components work together to simulate an autonomous driving experience where the car must continuously adjust its movements in response to its environment, aiming for smooth navigation without human input.

## Development Environment
Ensure you have the necessary development tools installed, including a C compiler and appropriate libraries. Setup instructions for CoppeliaSim will be provided separately.

## Contributing
Contributions to the project are welcome. Please ensure that any pull requests or patches adhere to the project's standards and submission guidelines.
