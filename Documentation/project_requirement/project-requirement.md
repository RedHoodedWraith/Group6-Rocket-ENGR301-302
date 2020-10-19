environmental# ENGR 301: Project Requirements Document

The aim of this document is to specify the requirements of the system your group is to build. The focus of a requirements document is the problem you are attempting to solve:  not a first attempt at a solution to that problem. This document should communicate clearly to the supervisor, client and course coordinator what the system you build is going to do, and what constraints it must meet while doing so.

The document should also demonstrate your understanding of the main analysis principles and quality guidelines, and applicable standards, using tools and notations as necessary to communicate the requirements precisely, unambiguously and clearly in a written technical document. Page specifications below are *limits not targets* and refer to the pages in the PDF generated from the markdown. Because the size of your document is necessarily limited, you should ensure that you focus your efforts on those requirements that are most important to completing a successful system: if sections are at their page limit, indicate how many items would be expected in a complete specification.

The ENGR 301 project proposal and requirements document should be based on the standard ISO/IEC/IEEE 29148:2011(E), primarily sections 8.4 and 9.5, plus section 9.4 for projects involving hardware and ISO 25010 SQuaRE for systemic requirements. While excerpts from the standard have been quoted within the template, to understand what is required it will be necessary to read earlier sections of the standards themselves. A supplementary treatment of requirements gathering in engineering projects may be found in [Requirements in Engineering Projects](https://victoria.rl.talis.com/items/F166DA94-DAD8-FBDB-0785-7A63C9BA3603.html?referrer=%2Flists%2F5886F297-2506-1F17-45D9-7F04CEE284EE.html%23item-F166DA94-DAD8-FBDB-0785-7A63C9BA3603) (Talis). The requirements document should contain the sections listed below, and conform to the formatting rules listed at the end of this brief.

All team members are expected to contribute equally to the document and list their contributions in section 6 of the document. You should work on your document in your team's GitLab repository. While collective contributions are expected to be the exception rather than the rule, if more than one team member has contributed to a particular commit then all those team member IDs should be included in the first line of the git commit message. `git blame`, `git diff`, file histories, etc. will be tools used to assess individual contributions, so everyone is encouraged to contribute individually, commit early and commit often. Any team wishing to separate individually contributed sections into a single file before collation into the single proposal document for submission is welcome to do so.

---

<div style="page-break-after: always;"></div>

# ENGR 301 Project *NN* Project Proposal and Requirements Document
#### Author list, a comma-separated list of the names of each member of the team.

## 1. Introduction


### Client

The Client for this project is Andre Geldhuis, and can be contacted by andre.geldenhuis@vuw.ac.nz or through Mattermost.

### 1.1 Purpose

The purpose of this system is to build off an existing rocket system and to improve its avionics and flight control.

### 1.2 Scope

The rocket being made for the client(s) listed above needs to be able to do the following:
*  Thrust itself from ground in order to launch itself into the air
*  Continue to propel itself in a largely vertical direction
*  Self-adjust propellant to its nozzle(s) in order to continue travelling in a controlled upwards direction
*  Travel upwards at a velocity that demonstrates the rocket is being controlled by its on-board control systems

The development of this rocket will happen in 3 core stages. Hardware design stage, software design stage and trial testing.
The Hardware Design Stage will focus on the physical build and design of the rocket, incorporating all the necessary components,
maximising travel efficiency and minimising the physical obstacles. The Software Design Stage will focus on programming the
on-board micro-controller to automatically adjust the rocket's propellants to self-correct the rocket's travel. Trial testing will
involve launching test rockets to observe how it performs in-situ and to return back to either design stages to modify the design to
 its performance. This project's development is limited by a variety of factors, most notably access to the internet and the civil restrictions in place due to the COVID-19 pandemic.
This heavily limits the availability to source parts for the rocket and opportunities to test the physical rocket prototype in-situ.

### 1.3 Product overview
#### 1.3.1 Product perspective

The project, in its entirety, is expected to address and solve the general issue of producing a controlled rocket using open-source software and open-hardware. The intended use for this rocket will primarily be for private operation but carries the potential for extended development and commercial use through being open-source.

The avionics element of the project must imitate the functionalities of a contemporary, off-the-shelf version and provide control features for the rocket as well. In particular, the system is required to manage various components of the rocket that ensure controlled flight such as, sensors, servos motors and transmitters.

In terms of the hardware component, the physical rocket model will be constructed from scratch, adapting the template of a basic hobby rocket that incorporates a gimballing motor for control. Additionally, an avionics board is to be assembled so that data can be remotely collected from the rocket and sensors. The software component will be developed to contribute in designing the control parameters for the avionics board.

The hardware and software components of the avionics package are required to seamlessly communicate with the mission control and simulation segments of the project to ensure a successful launch and flight for the rocket.

The avionics package will communicate with mission control to report its current pre-launch, launch and in-flight status. The simulation software will be used to aid in designing the rocket and determining estimates for the rocket control parameters. In this case, the software model of the control code developed in the avionics package will be required for simulation.


#### 1.3.2 Product functions

One page summary of the main functions of the product (9.5.4), briefly characterising the minimum viable product.

The minimum requirements for this avionics system will consist of the following:
- Record all sensor data which should collect data on a variety of benchmark measurements that include but are not limited to: stability, altitude, deviation, and critical components.
- Achieve an aerodynamically stable and consistent launch
- A demonstration of mission control's ability to adjust flight trajectory post-liftoff by instructing the gimble to turn, performing a kickover.
- After the motor has completed its burn, broadcast telemetry (location) over LoRa modules to a base station on the ground.
- An avionics package that is easy to install and uninstall.
- A hardware "On" and/or "Reset" switch that initialises launch in the event of a software launch failure.
- "Fast" hardware and software setup. Ideally, 10 minutes or less.
- Utilise onboard sensors and tuned error control to prolong vertical traversal. 
- Provide a compatible interface to be used in conjunction with a mission control system.
- Provide a compatible interface utilise simulation data for calibration ahead of time.

Ideally, the finalised package will incorporate the following:
- Support for parachute deployment.
- Provide control for aerodynamically stable launches without a rail.



#### 1.3.3 User characteristics   

The avionics package will be open-source meaning anyone can access it. However, the intended main class of users for this project is the wider model rocketry/high power rocketry community. And so general user characteristics which are expected include:

- An understanding of rocket avionics
- Technical expertise when installing different components of the rocket
- An understanding of those components and how they function within the system
- Technical expertise in telemetry systems
- An understanding of how the software will interact with the hardware
- Experience in operating aircraft applications
- Knowledge in Civil Aviation Authority (CAA) regulations

Due to health and safety concerns users testing the rocket in the field should not have any physical and or mental disabilities that would put them at risk.


#### 1.3.4 Limitations
Within project limitations, the team is faced with several limitations such as;
- Current worldwide affect(COVID-19): COVID-19 has resulted in a nationwide lockdown. This has limited the group options and approach towards the  current project. Certain aspects of the project will be adjusted from the original plan. The use of communication tools like Mattermost and  Zoom  will be crucial to the group.

- Budget: The team has a very limited budget of approximately $333.00 NZD. The budget has designed to be spent on components for the hardware as well as 3D printing for the rocket body.   

- Hardware accessibility: Due to the effect COVID-19 has had on the university, our hardware accessibility is been very limited. The extension of the hardware is improving on the control system of a previous team and on using *Onshape* to improve the design of the body of the rocket. 

- Software: The software aspect of the project is not very limited from the lockdown. The software aspect will consist of improving code from a previous team and ensuring it is functional and efficient.  

- Testing facilities: Due to COVID-19 lockdown, it will be unlikely that a testing facility is available for the group to use. The next step is to do testing via simulation. Working with a simulation team will be required. If circumstances change and access to testing facilities become available then the group will have to discuss the possible option.

- Time: This project runs over two papers ENGR 301 and ENGR 302. This gives the group 30 weeks, however with the first few weeks being introductions realistically the group has about ~27-26 weeks. The lockdown has resulted in a reconstruction of the academic year of Victoria            University of Wellington. This could result in less time.    

- Control & policies: When testing the rocket system we have designed, we need to ensure it is in a controlled environment. We can not breach any laws and restrictions that have been imposed by the government due to COVID-19 and we need follow The NZ Rocketry Association rules and regulations.  

- Team interactions: The main form of communication will be through Zoom and Mattermost due to the level 4 lockdown. Zoom meetings are held every Friday and Monday, and Mattermost chat is constant.

- Personal limitations: All members have personal limitations that should be taken into consideration. This will ensure all members of the group are treated fairly. Other members of the group as well, take other papers. Due dates of important assignments and test will be taken into account, this is design to reduce stress levels of the group.


## 2. References
[1] Civil Aviation Authority of New Zealand, “Civil Aviation Rules, Part 101 Gyrogliders and Parasails, Unmanned Aircraft (including Balloons), Kites, and Rockets Operating Rules” December 31st, 2018 [Online]. 
Available: https://www.aviation.govt.nz/assets/rules/consolidations/Part_101_Consolidation.pdf [Accessed: May 13th, 2020]. 

[2] National Aeronautics and Space Administration, Vectored Thrust, Glenn Research Center, Nancy Hall, 05 May 2015.
https://www.grc.nasa.gov/WWW/K-12/airplane/vecthrst.html

[3] New Zealand Legislation, Radiocommunications Regulations 2001, 10 September 2001. 
http://www.legislation.govt.nz/regulation/public/2001/0240/latest/DLM71513.html. 

[4] The Model Rocket, Model Rocket Engine Sizes and Classifications, Charlie Gasmire, 2020.
https://themodelrocket.com/model-rocket-engine-sizes-and-classifications/

[5] New Zealand Rocketry Association, “Rocket Safety, Model Rocketry Safety Code” [Online]. 
Available: https://www.nzrocketry.org.nz/rocketry/rocket-safety [Accessed: May 13th, 2020]



References to other documents or standards. Follow the IEEE Citation  Reference scheme, available from the [IEEE website](https://www.ieee.org/) (please use the search box). (1 page, longer if required)

## 3. Specific requirements  

This section describes the external interfaces, functions, usability requirements, performance requirements, logical database requirements, design constraints, non-functional system attributes, physical and environment requirements and supporting information.



### 3.1 External interfaces

#### Sensors - Inertial Measurement Unit

The inertial measurement unit (IMU) is an electronic device that measures acceleration, gyroscopic and magnetism data on the avionics package, each in 3 dimensions. This will be used to specifically measure the changes in the linear acceleration, velocity, and orientation of the rocket. The data from this unit will be outputted onto the SD card onboard where the Teensy will also process this information and control the position of the gimbal. This component of the system will require good accuracy plus tolerance as it is vital for the control of the rocket and will need to have a measurable acceleration range suitable for the rocket. The orientation and position of the rocket will be measured on 3 dimensions, in units of metres and degrees respectively. This will be present as part of the onboard avionics package.

#### Data Storage/Transfer - SD Card

An SD card is required to store data that is produced from the IMU, radio antenna, GPS and any other potential sensors. This information is to be processed for control and to be later used for the analysis of the performance of the system. The onboard system will need to be able to write to the SD card at a rate equivalent to the rocket's control loop. This rate will be required to be optimized so that it does not affect processing speed significantly while maintaining maximum control. The SD card must also be large enough to store all the potential data in a test run, with the data being stored in a .txt or .csv file.

#### Communication - Radio Antenna

The radio antenna is required for limited communication of data from the avionics package, using LoRa, to a nearby external computer for monitoring the data and minor adjustments/tuning. The antenna will receive signals from the avionics package and will output transmissions for a receiver antenna. The data sent will be required to be accurate enough to determine the state of the system in real-time and so it can be located easily using the satellite positioning system, GPS, in the case that it is lost. Data transferred during the launch will need to be essential data only as communication should not compromise performance of the control system.  The units of measure for this data will all be SI units and degrees/minutes/seconds for the longitude and latitude. This will play an important role for mission control in the field.

#### Mechanical - Gimbal

The rocket's gimbal will control the angle of the thrust relative to the centre of mass, thus stabilising and controlling the direction of the rocket's propulsion through the launch. This process is known as thrust vectoring. The gimbal will be controlled by the software on the avionics package which will adjust servos, altering the pitch and yaw. This will require a closed-loop control such as a Proportional-Integral-Derivative system, input from the IMU and outputting to the Gimbal.

#### Control Hardware - Servos

Two servo motors will be required to control the gimbal, that is controlled by an electric signal which determines the movement/angle of the shaft. This will be controlled from the avionics package and will alter the orientation of the gimbal. The servo's shaft rotation will be measured in degrees. The two motors will work individually, one to control the pitch and the other yaw. The timing response of this part is required to be minimised so that the rockets projection control can be as close to instantaneous as possible.

#### Ejection Ignition

The rocket will require a system to fire small igniters, which serve as ejection charges for the parachute. These are to be set off at a predetermined height for the descent of the rocket. This will receive its signal from the avionics package, which determines the height using the onboard barometer sensor. Some precaution is also required for the development of this component, as it will need to be ensured that it won't fire while the rocket is being handled.

#### Motor

The motor is a single-use component to produce the thrust for the rocket during the launch, by burning through a propellant which is released through a nozzle to produce powered flight. The ignition is required to be controlled by an electric igniter externally from the rocket for safety. This motor is to be connected to the gimbal, which will control the rocket. Motors vary in size depending on their total impulse, measured in Newton Seconds. This rocket will be required to use motors in the range of classes from C to G, ranging from 5-160 Ns. These motors likely to have a diameter of 24mm, and some of the smaller ones being 18mm.


### 3.2 Functions

> List up to fifty use cases (in order of priority for development),



#### Stakeholder Requirements:
- Avionics package must entirely fit inside the rocket's shell.
- Avionics package must interface with the gimbal.
- Avionics package must guide rocket on course.
- Avionics package must stabilise the rocket so it stands in an upright position while preparing for launch.
- Avionics package logical database will be comprehensible in the form of a text file.
- Avionics package should be comprised of fixated and durable components.
- Avionics package in the rocket must interface intuitively with the base station.
- Avionics package must ensure onboard power management can cope with each stage of the rocket's execution.

#### Use Cases:
Upon delivery to the primary client (Andre), the extended branch of stakeholders will include open-source hobbyists.
The purpose of this avionics package is to provide control and guidance for the rocket.
To do so, it needs to be installed, configured and calibrated prior to launch.
The user(s) should be able to expect recorded data from the flight.
The typical usage of the avionics package would look like:
Installation, calibration, launch, and post-flight analysis.

##### Installation
For ease of installation and reinstallation, the avionics package will uphold the following:
- Minimal physical footprint to mitigate spatial occupation and excess weight.
- Ensure as many components are fixated on a single unit rather than having components loose and untethered.
- Trouble-free pairing with the base station.

##### Configuration and Calibration
- The avionics package should be easy to configure for all intended stakeholders.
- The finished package should not require re-engineering to interface with control software during launch setup.
- Calibration data from simulations should be preloaded and initialised onto the avionics package prior to launch. Calibration is crucial as the standalone error control is likely not adequately fast enough to ensure stable control of the rocket.
- The calibration data will be stored on the SD card onboard the avionics package.
##### Launch
Once the rocket is launched into powered flight, the rocket will be remotely controlled via the gimbal to sustain vertical trajectory.
Vital flight data will be communicated with the base station in real time.
At the stage of burnout, the avionics package will be automated to deploy the parachute as a step to mitigate risk during the process of landing.
##### Analysis
The avionics package should broadcast vital data via its wireless antenna to the base station during flight. <br></br>
When the active flight is over, all logged data (measurements, instructions and gimbal positions) should be stored to the SD card, as a text file in a human-readable format.
If the avionics package is still in range of the wireless signal, it will attempt to broadcast the data to mission control. All data broadcasted to mission control must comply with the standards (units, parsing methods, encryption etc) of the mission control software.

### 3.3 Usability Requirements

The avionics package is usable if it is efficient and can successfully be operated and applied by no less than a rocket hobbyist. Therefore, the goal is to create an open-source avionics package that is accessible to the wider avionics community and applicable in all types of rocket-related use. The rocket should also be able to perform and endure through various external factors such as wind. This means that it is important to build a versatile avionics package that can withstand the external factors and mitigate the risks that follow.

In context, the avionics package will be used as a major component of a controlled rocket launch system. The effectiveness of the avionics package is measurable by its performance, which is contingent upon the success rate of a favourable launch and flight.

This is achieved by performing frequent in-flight correction of the gimbal position to ensure high efficiency and furthermore high performance. The software model of the avionics package will need to be designed in a way where it can easily be applied by the simulation segment of the larger system. As a result, this will contribute to improving the performance of the rocket gimbal.

Additionally, the software model should ideally be written using a common programming language used in avionics such as C to further improve its usability in the future. This will ensure that the software can be understood and applied by the regular avionics user.

In terms of the hardware component, it is essential that the avionics package is constructed in a way that is adaptable to changes that can occur at any point in time. The manual controls on the rocket should also be easily accessible to the user even after construction is completed.


**Uses**

Launch:

The rocket must be ready for launch within a set period of time following system activation.

In-flight:
- Diagnostics: The data from the rocket and sensors are remotely collected. This will diagnose any in-flight issues with the rocket.
- Recovery Mode: Once the motor burns out, recovery mode is enabled and the parachute is ejected.  

### 3.4 Performance requirements

This section defines the expectations of the rocket's functions and qualities, what the product should demonstrate to the user on a quantitative and qualitative level. The rocket will be constructed of many different functioning components, establishing a range of software and hardware performance requirements along with the rocket's general performance itself.

A key requirement of the rocket's performance is that it has a strong structural integrity, so that it is able to withstand stress, acceleration, velocity, vibration and heat that will be present during launch. This will ensure functionality and longevity of the rocket. It is required that the system can be tested at least 10 times, with any deficient parts after that to be easily replaced. The environment has a strong impact on the performance of the rocket, the most critical factor being the wind. Ideally the rocket will launch when there is minimal wind however this can be expected to increase with altitude. The system will be required to control the rocket in wind speeds up to 15 m/s. The general performance of the system is required to have a vertical-to-horizontal distance travelled ratio exceeding 90% at the completion of climbing flight.

The performance of the software will have a strong influence on the rocket's control so the system will require minimum delay between sensors and actuators. This delay will be determined by the maximum operating speeds of the components, such as the servos and the IMU. Another key aspect of the software performance is the communication of data through out each stage of the launch. It is essential that information to mission control is continuous. It is important to note that however this load will vary depending on the stage. The required data is the state of the rocket, the location and potentially some kinetic data. An additional software requirement is for a fast data rate on to the SD card, which will need to be taking readings from the sensors at least every 50ms more good analysis of the flight.


The core part of the systems performance is dependent on a power supply which makes the batteries performance vital. It is required that the system does not deplete more than 50% of the capacity throughout the launch process, leaving the remaining power for initiation and retrieval. This will be later detailed with more knowledge of the power consumption and specifications. It is also required that the servos are performing at a rotational speed sufficient enough to emulate the control system and also strong enough to manipulate gimbal. The geographical location of the rocket is important for finding it after launch so the GPS is required to perform within an error of 10 metres. To ensure communication during this stage the LoRa radio system will be required to transmit and receive up to 2 kilometres away, so the rocket may be retrieved if it was to travel far during descent. Like the structural integrity of the rocket, the individual components will need be able to with stand the induced environment factors during launch for longevity, this will require strong connections and a good quality of wiring. A vital part of the systems performance is that it is required to eject a parachute at the top of ascent, this needs to be certain so tests will be required to be implemented.




### 3.5 Logical database requirements

In order to analyse the system that will be implemented, the use of a domain model for the purpose of demonstrating the logical database requirements would be useful. For the purposes of this design, elements that will be implemented include the use of inertial motion unit (IMU) that are the sensors that collect the data that will be provided for the use of the overall system, including the controller. Additionally, this data will be fed into a microcontroller. Additional data that will be fed into the microcontroller is the GPS data. However, this data will not be used for the actual control of the system. Furthermore, data from the microcontroller will be sent to the SD Card Data Writer for the purpose of locally saving the flight data. And finally, there will be a radio module that will be used to broadcast the data to mission control remotely.

@startuml

title Relationships - Class Diagram


class IMU {
  +Gyrometer
  +Acceleromter
  +Magnetometer
}

class Microcontroller
class RadioModule
class GPSModule
class SDCardWriter

IMU --> Microcontroller
GPSModule --> Microcontroller
Microcontroller --> SDCardWriter
Microcontroller --> RadioModule

@enduml

**Gyroscope**

A gyroscope will collect data with reference to the potential rotation of the rocket with reference to the ground. This will be a key data point for the determination by the microcontroller on if or when any changes need to be made with respect to the gimble. Rotational energy that deviates outside of an expected range could lead to the rocket flying fully off course or even catastrophic failure.

**Accelerometer**

This device will measure the change in velocity and acceleration with reference to the acceleration of gravity. This data can be used to determine altitude which will be  a key point for the determination of apogee and the initialisation of any recovery hardware.

**Magnetometer**

A magnetometer in this device can be used for the purpose of designing a form of a digital compass that can determine which side of the rocket is facing a given cardinal direction with respect to the magnetic north pole. This data would be useful for the purpose of the microcontroller to determine if any gimbal adjustments need to be made if there is an imbalance in the rocket. Or, in other words, the mass of the rocket is not centred around a centre point of a cylindrical shape.

**GPS Module**

The device will be used to collect positional data at the cessation of the rocket launch to determine where the rocket's landing area is. This is particularly useful if there is an extreme deviation of the rocket landing area from the rocket launch area.

**Microcontroller**

The microcontroller will handle the general integration of all the IMU componenets. This collective data will be interpreted by the microcontroller to determine if any positional changes to the control gimble will need to be made. Accurate and calibrated data collection is essential for any practical use of the microcontroller for this system.

**SD Card Writer**

The SD card writer will be the component that keeps the log of all the data collected during the flight from the IMUs. Furthermore, it will log any changes made to gimble positions. Furthermore, these can be timestamped to correspond with specific values from the IMUs including any data that is calculated by the microcontroller for the purpose of determining flight changes. These could include altitude, reduction in acceleration, positional data, etc. 

**Radio Module**
The radio module will retain the purpose of being able to send radio data (including that which would be written to the SD card) to mission control. The collection of this data during flight would allow for mission control to determine if any manual changes need to be made that override the microcontroller. As such, this radio module would also need to be able to receive signals from mission control. 

You should use right tools, preferably PlantUML, to draw your URL diagrams which can be easily embedded into a Markdown file (PlantUML is also supported by GitLab and Foswiki).

### 3.6 Design constraints

**Software - Open Source**

For the final avionics package to qualify as open-source, only open-source resources may be used throughout its development. The open-source resources used must be well documented and credited, where needed, in the package release. Softwares, which are not open-source, may only be used if absolutely necessary and has been consented by the client. Once finished all source code for the package must be released in accordance with the open source definition.

**Software - API**

For consistency and compatibility across the three different sections, system engineering, mission control and rocket simulations, the same API should be used. Using the same API also ensures that the final avionics package will work as a whole.

**Hardware - Radio Antenna and the Satellite Navigation System Unit**

The radio antenna must follow the New Zealand Legislation, Regulation 9 of the Radiocommunications Regulations 2001 and only use the legally available frequencies with the rockets and solely for their intended purpose [3].

Similarly, the satellite navigation system unit used must also follow the New Zealand Legislation, Regulation 9 of the Radiocommunications Regulations 2001 and only use the legally available satellite navigation frequencies for New Zealand [3].

To avoid interference with nearby devices the radio antenna must use frequencies with the least use. Interference with other devices may result in corrupted data, which in turn could affect the satellite navigation system location of the rocket.

**Hardware - Physical Construction**

In accordance with the New Zealand Civil Aviation Authority and the New Zealand Rocketry Association, the rocket at its maximum size must satisfy the following criteria [1][5]:

- The rocket cannot use more than 125g of propellant
- The rocket cannot produce more than 320 Newton seconds of total impulse
- The rocket must use a slow-burning propellant
- The rocket is made from lightweight materials such as paper, wood, rubber and or plastic
- The rocket must not have the nose cone, fins or body fabricated from metal
- The rocket must not exceed a gross mass (i.e. including the propellant) of 1.5kg
- The rocket must not use an aerial firework as an ingredient to form its own jet
- The rocket must only use certified commercially-made model rocket motors
- The rocket motors must only be used in line with the manufacturer's recommendations (i.e. no tampering)
- The rocket must be launched with an electrical launch system and electrical motor igniters

The physical construction of the rocket will also be limited to our budget, what we have access to in the labs and (due to Covid-19) when. Similarly delays in shipments because of the virus will also limit us in what parts we can order online.


### 3.7 Nonfunctional system attributes

Present the systemic (aka nonfunctional) requirements of the product (see ISO/IEC 25010).
List up to twenty systemic requirements / attributes.
Write a short natural language description of the top nonfunctional requirements (approx. five pages).

1. Safety
   - The rocket's operations must not cause nor contribute to harm or death to people or animals, including but not limited to its operators, nearby bystanders, pets and the local biodiversity.
   - The rocket's operations must not cause damage to property nor the local environment external to its operational scope. Example: Burnt Fuel Residue to the launchpad is accepted as it is expected as part of its operation. Cracking the windscreen of a nearby vehicle is not acceptable.
   - Operators must be able to know sufficient real time information with regards to the condition, location and effects of the rocket during its operation.

1. Flight
   - The rocket needs to be able to thrust itself from the launchpad.
   - The rocket needs to be able to continue to propel itself upward when it is expected to do so.
   - The force exerted by the propellant needs to exceed the opposing forces, such as the force of gravity onto the rocket's mass and air resistance.

1. Robustness
   - The essential systems contributing to the rocket's flight must remain sufficiently intact during the rocket's operation.
   - Obstacles must not compromise the rocket's essential system processes that allows it to function.
   - The essential systems that contribute to the rocket's flight must be able to continue functioning when performing its task.
   - Essential system operations must not compromise each other system's functionality during their operations.

1. Control
   - The rocket's operation (during flight) must be sufficiently controlled by its operators.
   - Any unintended effects from the rocket's operation must be able to brought back into the control of the operators.
   - The rocket must be able to be controllable in order to increase Safety.
   - The rocket must be able to be brought back to a stationary or non-functioning state when expect it is expected to.
   - The rocket must be able to travel along the intended flight path of the operators' choosing.

1. Trackability
   - At minimum, sufficient data of the rocket's operation must be available to rocket's operators during its operation. This means data expected to be delivered in real time during the rocket's operation must be delivered in real time.
   - The rocket's location must be able to be monitored and known at all times during its operation, as per the requirement of Saftey and the Client's requirement.
   - Essential data that is not expected to be collected in real-time, must be able to be retrieved after the rocket's operation has ended.

1. Legal
   - This project must be performed legally and with the permission of the applicable property owner(s).
   - What we make and test must adhere to the rules and regulations of the relevant local authorities


### 3.8 Physical and Environmental Requirements
The system Hardware components:
- microcontroller(Teensy 3.6)
- gyroscope/accelerometer sensor
- sensor module(IMU)
- wireless antenna
- rocket motors
- servos
- gimble
- parachute + ejection charge
- rocket body
- launch pad (this includes, barometer, gps and the base station)

The hardware components must be able to still function within the environment that the rocket will be tested in, this means that the rocket will need to function under certain enviromental condition(s) that are present in the testing environment. The current testing environment is a wide-open park located in Upper Hutt, Wellington. A certain environmental condition is the wind. Wind levels are never constant and can vary extremely (especially in our testing environment of Upper Hutt Wellington). This means hardware of the rocket must be functioning under considerable wind levels. 

The largest effect wind has on the rocket is displacement. The wind is able to tilt (or even move) the rocket off its current trajectory. This means that hardware of the rocket must be to account for this issue. Combination of the electronic components (microcontroller, gyroscope and sensor module) and the gimble are involved in accounting for the displacement. Using the sensor(s) to detect the displacement, then micro-controller communicates to the gimble to make an adjustment for the displacement.

The rocket body design is also important to account for wind. A more aerodynamic design will mean that the wind drag will have less of the effect of the rocket. Meaning a more aerodynamic design will result in a smaller displacement.

Wind will also greatly affect the rocket while the rocket is coming down. The rocket slowly descend due to the parachute being deployed. However, with the parachute deployed the rocket is very susceptible to wind drag. Which means that the rocket might be displaced a large distance from the launch site. A GPS connected to the micro-controller will allow us to track where the rocket lands. Also, modelling of the rockets launch will be done to estimate where the rocket could land.

Another environmental condition that will need to be taken into account is radio frequency (RF) noise. To communicate to the rocket microcontroller we use a signal in the microwave frequency. So before we can launch the rocket, we will need to check the level of RF noise. If the level of RF noise is too high the launch of the rocket will be postpone, there is no solution where we launch the rocket in high RF noise. If the rocket is launch in during high RF noise we could lose communication with the rocket.

Certain envionmental conditions like rain, high cloud coverage and extreme temperatures will mean that the rocket launch won’t be able to happen. However, these conditions can be prevented by choosing a day launch where these conditions aren’t present. Finally the rocket should not be launch at night time.


### 3.9 Supporting information
The purpose project is to improve and partial redesign a previous module rocket, which includes an improved design of the avionics system, to ensure working and efficient code and possibly redesign the rocket hull to make it more aerodynamic. The end goal is to ensure a well develop rocket that is able to launch. Firstly we need to test the rocket via simulation, then working with mission control to physically test with a flight. 

By improving and developing this open-source rocket project we are able to present the rocket community with a possible new product. This resulting in new knowledge added to the model rocket community. This will hopefully lead to a better design module rocket.
## 4. Verification

3 pages outlining how you will verify that the product meets the most important specific requirements. The format of this section should parallel section 3 of your document (see 9.5.18). Wherever possible (especially systemic requirements) you should indicate testable acceptance criteria.

### 4.1 Verification External Interfaces
To verify the external interfaces of the system are meeting the specified requirements they will be tested in environmental conditions to simulate the launch, where their qualities can be formally verified. During these simulations it will be determined if the interfaces are fitting their purpose, working in the desired range, accuracy and/or tolerance, functioning with other interfaces, in the correct formats and meeting functioning specifications.

The IMU component will be verified by analysing the data and making sure it corresponds with the rocket's kinematics, this will also be reflected in the control system. The data transfer between the system and the SD card is verified after/or during a simulation or launch by reading the SD card and checks that it meets expectations. Wireless radio communication will be verified as the connection is tested over the potential distance range. The gimbal and servos performance requirements will be verified by meeting the specifications; moving in the full range of accurate angles, exerting enough force, and adequate response times. All these attributes will be measured. The ejection ignition interface will be verified by testing its response to input signals, and observing the outputs. Additionally doing a test run would be ideal. Since the motor is being outsourced, the only aspects of it to be verified is that it is the correct size and that the ignition operates.
	

### 4.2 Verification Functions

To meet the requirements of easy installation, the avionics package must be assembled into a single unit, with the exception of the battery unit. The avionics package must also be fixated with the rocket housing without any wobble.

To meet the requirements of intuitive configuration and calibration, the avionics package should be able to interface directly with the base station without having to re-engineer the hardware of software on either, the avionics package or mission control. Calibration data from the simulation teams must be transferred in a user-friendly manner, such as either directly writing to SD card or wirelessly via the base station. The software on the avionics package should not have to be manually recompiled from the toolchain.

To meet the requirements of the launch and flight phase, the rocket must launch and sustain vertical trajectory, even under mild weather interference. The avionics package must also allow mission control to remotely tilt the trajectory of the rocket in-flight. The rocket is also expected to land without taking on critical damage, though cosmetic wear is excusable. Throughout the launch and flight phase, power management must ensure a stable power supply system-wide meaning no components should malfunction due to inadequate power.

The analysis and diagnosis stage of the rocket's flight also has to meet requirements. Live data such as gyroscope and accelerometer readings must be broadcasted to mission control in real-time. By the end of the flight, the SD card must have all logged flight data recorded as a text file in a comprehensible format. The avionics package should also be able to broadcast all the logged data if still in wireless range. Mission control should be able to parse all broadcasted data.

### 4.3 Verification Usability Requirements

In order to meet the usability requirements, the avionics package must firstly achieve a successful launch and flight regardless of the external factors that may affect its performance. This can be measured by testing the rocket on different days in varied environmental conditions. If the rocket endures all tests with a satisfactory performance, the usability requirements have been passed. 

In terms of hardware, it is required that the avionics package be constructed in a way that is adaptable to change. This requirement is fulfilled when if at any stage of the development process modifications are required, the rocket will be able to adjust without complete deconstruction. 

Additionally, the software component should be open source and written applying a commonly-used programming language in avionics. The software model should also be programmed in a way that is understandable for other users. This can be shown by using effective code commenting and other types of documentation methods. In the context of this project, the software model of the source code should be accessible to the simulation developers and easily adaptable in order to aid in accurately estimating the PID control parameters. 

### 4.4 Verification Performance Requirements

The general performance of the rocket will be verified by inducing the environment conditions, software simulations of the launch and test flights. The structural integrity of the rocket will be verified by using simulation software and from there test flights. Also, visual inspection has the potential to show weaker parts. To verify the longevity of the rocket the system will need to have at least 10 test flights to be confident. The performance of the rocket's ascent will be verified by measuring the vertical climb and the GPS location to compute the vertical-to-horizontal distance travelled relationship.

The software's performance requirements will be more simple to verify as they should not require any physical flights. The delay between the sensors and actuators can be verified in the laboratory to get precise response times. Communication between the rocket and base station can be verified by simulating the rocket and using artificial data. The data rate and sample rates of the system can also be easily verified without test flights, using signal generators and comparing the data.

To verify the power consumption and supply performance requirements the systems will be tested multiple times over some time to see what the effect it has on the supply. This process can be broken down to determine the specific power consumption of each component. The performance of the servos will be verified in the laboratory by measuring their response to varying inputs similar to those expected in practice. The GPS performance can be verified by varying the location of the system and analysing the accuracy of the data according to how the system was moved. The radio communication can be tested by inducing the maximum transmission distance expected in similar terrain and reflecting on its performance. The structural integrity of the individual components will be verified during test flights and also a visual inspection. The final part of the hardware to be verified is the parachute ejection interface which can be tested without a flight to confirm functionality.


### 4.5 Verification Logical Database Requirements

As shown in section 3.5 of the UML class diagram, the relationship of how each abstracted component is interfaced is likely to hold consistent. 

From the perspective of the end user, the abstracted relationship of components plays no relevant role in the verification of the final product's performance. 

What will be required is that the documentation submitted has no conflicting design patterns and details with the finalised avionics package.

### 4.6 Verification Design Constraints

To meet the requirements of open-source for the software side of the avionics package, only open-source resources will be used throughout. Software that is not open-source may only be used with client consent.

To meet the requirements of a consistent API, the use and implementation of the same API will be discussed with the two other teams, mission control and rocket simulations. And then put into action accordingly.

To meet the requirements of the New Zealand regulations on the radio Antenna and the satellite navigation system unit the Radiocommunications Regulations 2001, Regulation 9 will be closely followed [3].

To meet the requirements of the New Zealand Civil Aviation Authority and the New Zealand Rocketry Association, on the rocket's physical construction, the design constraints laid out will be strictly followed [1][5]. 

To meet the requirements of our budget and deadline, rocket parts bought overseas will be limited to our budget and also to their shipment times.

### 4.7 Verification Nonfunctional System Attributes

1. Safety
   * Ensure there is adequate distance between people and the launch site.
   * Have a functioning fire extinguisher ready and on-hand during testing.
   * Choosing a wide-open space environment outdoors to perform the test it.
   * Cordon off the test area if need be.
   * Have someone watch where the rocket flies to and where it is falling.
   * Ensure that the rocket does not fly high enough it could hurt someone if it free fell.
   * Use of a parachute for freefall events.
   * Ensure there is a shutoff mechanism where applicable.

1. Flight
   * Testing the rocket with fuel.
   * Performing some calculations to figure out how much force should be exerted to lift the rocket and using sufficient amount rocket fuel.
   * Ensure the physical design is catered to follow the intended flight path.

1. Robustness
   * Testing each system before combining them.
   * Performing the tests on a small scale or in a simulated environment.
   * Deciding what the core systems are, checking if there are any process conflicts and amending the design to not conflict if there are conflicts (example of a conflict: a mechanism dislodges another mechanism).

1. Control
   * Have someone watch where the rocket flies to and where it is falling at all times during the test.
   * Ensure the physical design is catered to follow the intended flight path.
   * Ensure the rocket fuel is only loaded sufficient to its maximum intended use. Do not put in extra fuel if it's not planned to be used.
   * Ensure the correct amount of rocket fuel is ignited at the correct times.
   * Use of a parachute if a freefall is expected.
   * Ensure the rocket can communicate to mission control within a timely manner.

1. Trackability
   * Use of a GPS Receiver and a radio transmitter for data transmission for mission control to receive location data.
   * Have someone watch where the rocket flies to and where it is falling.
   * Have the rocket locally store desired and essential data, such as on an SD card, regardless of if it can be transmitted back to mission control.

1. Legal
   * Reviewing Civil Aviation Authority's rules and regulation for objects in flight.
   * Ensure the rocket does not fly high enough for other regulations to need to be applied.
   * Ensure the scope of the project keeps to the bounds of a hobbyist level activity.
   * Ensuring we have permission to use the land for testing from its property owner. If it is a park and the council permits the use of flying hobbyist level aircraft as part of their bylaw, this could be regarded as permission granted.

### 4.8 Verification Physical and Environmental Requirements
At this point of time, it is currently unclear of what hardware component can be sourced, and which need to be bought. The only known physical component that can be sourced is the 3D printed parts i.e the body of the rocket. These can be constructed and printed within the university. The hardware system which that makes up the avionics package (Teensy 3.6 microcontroller, gyroscope, IMU and the wireless antenna) will need to fit into the body of the rocket with the parachute and ejection charge. This needs to fit into a cone-like shape of 9X13 cm (9cm in height and 13cm in width).

The current testing location is a large park located in Upper Hutt, Wellington (the specific park is currently unknown). The day of launch will be planned ahead, meaning that weather conditions will be known in advanced. The optimum goal is to launch the rocket on a clear day (with very little to no wind). It possible for the weather to change or over environmental conditions to happen. Environmental conditions that prevent launch from happening are:
- rain/hail
- temperatures below 5 degrees celsius
- cloud coverage greater than 4 oktas
- high amounts of radiofrequency noise (enough to interfere with rocket communication)
- wind speeds greater than 30 km/h 


During rocket launch all requirements and regulations of both physical system and the Environment. The requirements and regulations must be able to be in line with the following organisations:
- NZ Rocketry Association
- Civil Aviation 
- Wellington region and local council  
- Victoria University of Wellington Faculty of Engineering and Computer Science 



## 5. Development schedule.

### 5.1 Schedule

#### Architectural prototype
The architectural prototype will be finalised by early April, and further developed. A more specific date is yet to be confirmed.
#### Minimum viable product
Due to Covid-19, the future of this project is very unclear, as a product may never physically be developed. However, being optimistic the minimum viable product would be available in late June. Also, to be confirmed in the near future with more information.
#### Further releases
The final prototype of the design will be completed by November 8th 2020 at the latest, being at the end of 2nd university trimester.

#### Delivery Method
Sections of work will be planned to be completed every 2 weeks in sprints. The content of these sections will be determined every fortnight on Monday and previous sprint will be reflected on.

### 5.2 Budget
Currently known components:

| Component        |      Purpose                            |  Price(NZD) |
|------------------|-----------------------------------------|-------------|
| Teensy 3.6 board | Microcontroller for base station        | $47.75      |
| Teensy 3.2 board | Microcontroller for rocket              | $32.48      |
| 3D printing      | Parts for rocket                        | depending   |
| PCB              | Cicuitry for rocket and/or base station | depending   |
| Batteries        | To power rocket                         | depending   | 


Specific components to be confirmed: 

| Component         | Previous team specific component | Price(NZD)          |
|-------------------|----------------------------------|---------------------|
| Radio transceiver |  RFM90                           | ~$28                |
| GPS               |  MPA‑154‑ANT L1 GPS              | $9.45               |
| Servo             | HK-282A                          | $8.21               |
| Servo             | HC2422T 7.5kg                    | No longer continued |
| Signal receiver   | FUNcube dongle                   | $33.83              |
| Voltage regulator | L7805                            | $2.25               |
### 5.3 Risks

This table identifies the most important risks to achieving project goals. The majority of these risks comes down to product testing. The likelihood and impact for each of these risks have been rated on a value from 1-10. Based on how likely is it that it will occur and how much damage this would cause people, product, or development.

| **Risk** | **Risk Type** | **Likelihood** | **Impact** | **Mitigation Strategies** |
| ------ | ------ | ------ | ------ | ------ | 
| Premature motor ignition causing burns or injury  | Health & Safety | 4 | 5 | Hardware and software safety interlocks to reduce the chance of premature ignition. Keeping the motor away from heat sources or other potential igniters.|
| Premature Parachute Ignition causing burns or injury | Health & Safety  | 3 | 5 | Hardware and software safety interlocks will be required and also keeping the pyrotechnic charge away from heat sources or other potential igniters. |
| Flammable Surfaces during launch and landing | Environment Damage | 3 | 4 | The launch site will be required to have an absence of flammable material, such as dry grass. In addition, a fire extinguisher will be on hand ready for use. Also, emergency services may be called if needed. |
| High Winds/Excessive Drift causing damage to a person or property | Health & Safety/Environmental Damage | 5 | 4 | The forecast will be analysed prior to launch, and wind measurements exceeding the determined will result in cancelling the launch. Wind speeds at various altitudes will be taken into account. |
| Descending Rocket falling onto persons or property | Health & Safety/Environmental Damage | 4 | 6 | All participants will remain at least 10 meters from the launch site during launch and flight. All nearby public will be warned and the launch will only take place if the site is not busy, if the site does not exceed 10 people. The launch site will not be close to any private property or populated areas.|
| Descending debris falling onto persons or property | Health & Safety/Environmental Damage | 3 | 5 | The structural integrity of the rocket will be required to be very sturdy. All nearby public will be warned and the launch will only take place if the site is not busy, if the site does not exceed 10 people. The launch site will not be close to any private property or populated areas. |
| Intercepting other aircraft | Health & Safety | 2 | 7 | The maximum possible height will be determined and if this exceeds the minimum height for an aircraft, a NOTAM will be made to meet CAA regulations. In addition, the launch site will not be near any aerodrome to minimalise potential hazards. |
| Uncontrollable flight during launch | Health & Safety/Environmental Damage | 4 | 6 | All participants will remain at least 10 meters from the launch site during launch and flight. All nearby public will be warned and the launch will only take place if the site is not busy, if the site does not exceed 10 people. The launch site will not be close to any private property or populated areas. |
| Pandemic outbreak due to Covid-19 | Health & Safety/Development | 3 | 7 | Strategies to mitigate this problem vary with the state of Country. If an alert Level 2 or greater is in place, social distance will be implaced which will mean at home communication and development. |
| Crashing landing during test flights | Product Prototype | 2 | 5| To ensure the protoype is not damaged during test flights, vigorous tests will be implaced to make sure crucial elements are performing e.g parachute. |


### 5.4 Health and Safety

Document here project requirements for Health and Safety. All teams must state in this section:

1. How teams will manage computer-related risks such as Occupational Over Use, Cable management, etc.  

2. Whether project work requires work or testing at any external (off-campus) workplaces/sites. If so, state the team's plans for receiving a Health and Safety induction for the external workplaces/sites. If the team has already received such an induction, state the date it was received.

3. Whether project work requires the team test with human or animal subjects? If so, explain why there is no option but for the team to perform this testing, and state the team's plans for receiving Ethics Approval _prior_ to testing.

Also document in this section any additional discussions with the School Safety Officer regarding Health and Safety risks. Give any further information on relevant health and safety regulations, risks, and mitigations, etc.


#### 5.4.1 Safety Plans

Safety Plans may be required for some projects, depending on project requirements.
<br>
<br>Two questions all teams must answer are:

**Do project requirements involve anything that can cause serious harm or death?**  
Examples: building/modifying devices using voltages > 60 V, chemicals, large moving machinery, flying devices, bodies of water.

If so, you will have to write a separate Safety Plan as part of project requirements, and the Safety Plan must be referenced in this section. For health and safety risks involving serious harm or death, you must first contact the School Safety Officer and Course Coordinator first to discuss the Safety Plan and project requirements.

**Do project requirements involve anything that can cause harm or injury?**  
Examples: building/modifying things with voltages <= 60V, small moving machinery, wearable devices.

If so, you will have to write a separate Safety Plan as part of project requirements, and the Safety Plan must be referenced in this section. For health and safety risks involving harm or injury, you should write a draft of the Safety Plan before contacting the School Safety Officer and Course Coordinator to discuss the Safety Plan and project requirements.

If a safety plan is required, list in this section the date the School Safety officer accepted your Health and Safety plan (if accepted by submission date).


The project requirements may involve the risk of death, serious harm or injury to participants and members of the public. A safety plan is required to ensure all risks are addressed and planned for as the construction of the rocket progresses.  



## 6. Appendices
### 6.1 Assumptions and dependencies


### 6.2 Acronyms and abbreviations

CAA (Civil Aviation Authority): The Civil Aviation Authority of New Zealand is the government agency tasked with establishing civil aviation safety and security standards in New Zealand.

IMU (Inertial Measurement Unit): An inertial measurement unit is an electronic device that uses a combination of magnetometers, gyroscopes and accelerometers to measure the change of forces and movement.

NOTAM (Notice to Airmen): A notice to airmen is a notice filed with an aviation authority to alert aircraft pilots of potential hazards along a flight route or at a location that could affect the safety of the flight. 

IEEE (Institute of Electrical and Electronics Engineers): This is a professional association for electronic engineering and electrical engineering.

GPS (Global Positioning System): A GPS unit is actually a receiver that collects signals from satellites to determine location around the globe.


## 7. Contributions

| Name | Contribution/Section |
| ---- | ---- |
| Dylan Sukha | 3.2, 3.5, 4.2, 4.5 |
| Jason McCormick | 1.3.2, 3.5, 4.5|
| Ketaki Bagal | 1.3.3, 2, 3.6, 4.6, 5.4 |
| Penny Peneueta | 1.3.1, 3.3, 4.3, 5.4.1,  |
| Robert Reid | Project Charter, 2, 3.1, 3.4, 4.4, 4.1, 5.1, 5.3, 6.2, 7|
| Rowan Rathod |1.1, 1.2, 3.7, 4.7|
| Sean Osborne-Curtis |1.3.4, 3.8, 3.9, 4.8, 5.2|






---

## Formatting Rules

 * Write your document using [Markdown](https://gitlab.ecs.vuw.ac.nz/help/user/markdown#gitlab-flavored-markdown-gfm) and ensure you commit your work to your team's GitLab repository.
 * Major sections should be separated by a horizontal rule.


## Assessment  

The goal of a requirements document is the problem you are attempting to solve:  not a first attempt at a solution to that problem. The most important factor in the assessmernt of the document is how will it meet that goal. The document will be assessed for both presentation and content.

The presentation will be based on how easy it is to read, correct spelling, grammar, punctuation, clear diagrams, and so on.

The content will be assessed according to its clarity, consistency, relevance, critical engagement and a demonstrated understanding of the material in the course. We look for evidence these traits are represented and assess the level of performance against these traits. While being comprehensive and easy to understand, this document must be reasonably concise too. You will be affected negatively by writing a report with too many pages (far more than what has been suggested for each section above).

We aim to evaluate ENGR301 documents and projects as if they were real projects rather than academic exercises &mdash; especially as they are real projects with real clients. The best way to get a good mark in a document is to do the right thing for your project, your client, and your team. We encourage you to raise questions with your tutor or course staff, as soon as possible, so you can incorporate their feedback into your work.

---
