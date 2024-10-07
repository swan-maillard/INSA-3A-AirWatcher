# AirWatcher

## Description

This application developed in C++ processes air quality sensor data to provide statistics on geographical areas, detect faulty sensors, and much more.

We followed a Test-Driven Development methodology throughout the implementation of this project.

## Features

Here is a list of the main features of the application:

1. **Identification of Faulty Sensors**: Analyzes sensors to detect anomalies based on the mean and standard deviation of the data from surrounding sensors. Accessible only to the government.
   
2. **Statistical Generation**: Calculates air quality and various ATMO indices for sensors in a circular area or at a specific point.
   
3. **Analysis of Air Quality at a Specific Point**: Triangulates data from the nearest sensors to determine air quality.
   
4. **Search for Similar Sensors**: Identifies sensors with similar air quality characteristics within a given timeframe, accessible only to the government.
   
5. **Verification of Sensor Reliability**: Validates private sensor data by comparing it to that of neighboring sensors.
   
6. **Evaluation of Air Purifier Effectiveness**: Compares data before and after the installation of air purifiers.

## User Interface

The application features a console interface where users can log in and access various functionalities through interactive menus.

## Compilation

---
**Commands to be executed with MakeFile:**

**$ `make`** to compile and link.

**$ `make run`** to compile, link, and execute `./app`.

**$ `make debug`** to compile in development mode and link.

**$ `make fclean`** to remove object files and the executable.

**$ `make help`** to get more information about available commands.

## Execution

To launch the application, use the following command from the root of the project:

```bash
./app
```

The application supports the following options:

- **`-t`**: Enables tracing mode to display the execution time of different functions. This can be useful for debugging and performance optimization.

### Testing

Tests should be run regularly to ensure that new features do not introduce errors into existing functionality.

**Running the tests:**
- Navigate to the **`tests/`** directory.
- Execute **$ `./mktest.sh`**.

### Project Structure

- **data/**: Contains .csv files of sensor data, etc.
- **include/**: Contains C++ header files.
- **src/**: Contains C++ source files.
- **tests/**: Contains the test script.
- **Makefile**: Configuration file for compiling and running the application.

## Authors

- Alexandre Biaud (alexandre.biaud@insa-lyon.fr)
- Clément Giraudon (clement.giraudon@insa-lyon.fr)
- Swan Maillard (maillard.swan@gmail.com)
- Hugo Warin (hugo.warin@insa-lyon.fr)

## License

This project is licensed under the MIT License. Please refer to the `LICENSE` file for more information.
