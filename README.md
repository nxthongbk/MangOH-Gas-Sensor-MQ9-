# Integrate Grove Gas Sensor with MangoH and Grove IoT Exapansion Card

This project demonstrates how to integrate Grove Gas Sensor with MangoH and Grove IoT Exapansion Card.

## Prerequisites

* A mangOH Red board.
* A Grove IoT Expansion card.
* Gas Gas sensor: See detail of sensor on wiki page: http://wiki.seeedstudio.com/Grove-Alcohol_Sensor/ 


<img src="https://user-images.githubusercontent.com/17214533/57900863-c8bb8d80-788c-11e9-85cd-585dc6027c3d.png" width="350" alt="accessibility text"> 


Grove Gas Sensor
------------------
Grove - Gas Sensor is an Analog output sensor. The output voltage from the Gas sensor increases when the concentration of gas increases. Sensitivity can be adjusted by varying the potentiomete.


Legato Application
------------------
There are 3 legato applications:
* ```GasSensorService```: provides api for reading alcohol sensor.
* ```GasSensorToDatahub```: push alcohol sensor value in period time to datahub.
* ```GasSensorDisplay```: register for notification of value updates, create observation (filter) for gas sensor and display the gas sensor value.



## Setup
1. Insert Grove IoT Expansion card into Mangoh Red
1. Jump 5V Pin on Grove IoT Card
1. Connect Grove Gas Sensor with A0 connector on Grove card



## How To Run

1. Build the GasSensorService app by running ```mkapp -t wp85 gasSensor.adef``` in GasSensorService directory.
1. Run ```instapp gasSensor.wp85.update 192.168.2.2``` to install the app.
1. Build the GasSensorToDatahub app by running ```mkapp -t wp85 GasSensorToDatahub.adef``` in GasSensorToDatahub directory.
1. Run ```instapp AlcoholSensorToDatahub.wp85.update 192.168.2.2``` to install the app.
1. Build the GasSensorDisplay app by running ```mkapp -t wp85 GasSensorDisplay.adef``` in GasSensorDisplay directory.
1. Run ```instapp GasSensorDisplay.wp85.update 192.168.2.2``` to install the app.
