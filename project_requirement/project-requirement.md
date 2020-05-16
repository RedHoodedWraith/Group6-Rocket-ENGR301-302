# ENGR 301: Project Requirements Document

The aim of this document is to specify the requirements of the system your group is to build. The focus of a requirements document is the problem you are attempting to solve:  not a first attempt at a solution to that problem. This document should communicate clearly to the supervisor, client and course coordinator what the system you build is going to do, and what constraints it must meet while doing so.

The document should also demonstrate your understanding of the main analysis principles and quality guidelines, and applicable standards, using tools and notations as necessary to communicate the requirements precisely, unambiguously and clearly in a written tecgithnical document. Page specifications below are *limits not targets* and refer to the pages in the PDF generated from the markdown. Because the size of your document is necessarily limited, you should ensure that you focus your efforts on those requirements that are most important to completing a successful system: if sections are at their page limit, indicate how many items would be expected in a complete specification. 

The ENGR 301 project proposal and requirements document should be based on the standard ISO/IEC/IEEE 29148:2011(E), primarily sections 8.4 and 9.5, plus section 9.4 for projects involving hardware and ISO 25010 SQuaRE for systemic requirements. While excerpts from the standard have been quoted within the template, to understand what is required it will be necessary to read earlier sections of the standards themselves. A supplementary treatment of requirements gathering in engineering projects may be found in [Requirements in Engineering Projects](https://victoria.rl.talis.com/items/F166DA94-DAD8-FBDB-0785-7A63C9BA3603.html?referrer=%2Flists%2F5886F297-2506-1F17-45D9-7F04CEE284EE.html%23item-F166DA94-DAD8-FBDB-0785-7A63C9BA3603) (Talis). The requirements document should contain the sections listed below, and conform to the formatting rules listed at the end of this brief.

All team members are expected to contribute equally to the document and list their contributions in section 6 of the document. You should work on your document in your team's GitLab repository. While collective contributions are expected to be the exception rather than the rule, if more than one team member has contributed to a particular commit then all those team member IDs should be included in the first line of the git commit message. `git blame`, `git diff`, file histories, etc. will be tools used to assess individual contributions, so everyone is encouraged to contribute individually, commit early and commit often. Any team wishing to separate individually contributed sections into a single file before collation into the single proposal document for submission is welcome to do so.

---

<div style="page-break-after: always;"></div>

# ENGR 301 Project *NN* Project Proposal and Requirements Document
#### Author list, a comma-separated list of the names of each member of the team.

## 1. Introduction

One page overall introduction including sections 1.1 and 1.2.

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

The project, in it's entirety, is expected to address and solve the general issue of producing a controlled rocket using open-source software and open-hardware. The intended use for this rocket will primarily be for private operation but carries the potential for extended development and commercial use through being open-source. 

The avionics element of the project must imitate the functionalities of a contemporary, off-the-shelf version and provide control features for the rocket as well. In particular, the system is required to manage various components of the rocket that ensure controlled flight such as, sensors, servos motors and transmitters. 

In terms of the hardware component, the physical rocket model will be constructed from scratch, adapting the template of a basic hobby rocket that incorporates a gimballing motor for control. Additionally, an avionics board is to be assembled so that data can be remotely collected from the rocket and sensors. The software component will be developed to contribute in designing the control parameters for the avionics board.

The hardware and software components of the avionics package are required to seamlessly communicate with the mission control and simulation segments of the project to ensure a successful launch and flight for the rocket. 

The avionics package will communicate with mission control to report its current pre-launch, launch and in-flight status. The simulation software will be used to aid in designing the rocket and determining estimates for the rocket control parameters. In this case, the software model of the control code developed in the avionics package will be required for simulation. 


> **9.5.3 Product perspective** <br>
> 
> Define the system's relationship to other related products. 
> 
> If the product is an element of a larger system, then relate the requirements of that larger system to the functionality of the product covered by the software requirements specification.
>
> If the product is an element of a larger system, then identify the interfaces between the product covered by the software requirements specification and the larger system of which the product is an element.
>
> A block diagram showing the major elements of the larger system, interconnections, and external interfaces can be helpful.
>
> Describe how the software operates within the following constraints:  
a) System interfaces;  
b) User interfaces;  
c) Hardware interfaces;  
d) Software interfaces;  
e) Communications interfaces;  
f) Memory;  
g) Operations;  
h) Site adaptation requirements.

#### 1.3.2 Product functions

One page summary of the main functions of the product (9.5.4), briefly characterising the minimum viable product.

The minimum requirements for this avionics system will consist of the following:
- Record all sensor data.
- Aerodynamically stable launch.
- To demonstrate mission control can change rocket's path, the gimble will set to full extension in one direction to perform a 'kickover' on final second of motor burn.
- After motor has completed its burn, broadcast telemetry (location) over LoRa modules.

- Utilise onboard sensors and tuned error control to prolong vertical traversal. 
- Provide a compatible interface to be used in conjuction with a mission control system.
- Provide a compatible interface utilise simulation data for calibration ahead of time.

Ideally, the finalised package will incorperate the following:
- Support parachute deployment.
- Provide control for aerodynamically stable launches without a rail.

#### 1.3.3 User characteristics   

One page identifying the main classes of users and their characteristics (9.5.5)

#### 1.3.4 Limitations
Within project limitations, the team is faced with sereval limitations such as; 
- Current worldwide affect(COVID-19): COVID-19 has resulted in a nationwide lockdown. This has limited the group options and approach towards the  current project. Certain aspects of the project will be adjusted from the original plan. The use of communication tools like Mattermost and  Zoom  will be crucial to the group. 

- Budget: The team has a very limited budget of approximately $333.00 NZD. The budget has designed to be spent on components for the hardware as well as 3D printing for the rocket body.   

- Hardware accessibility: Due to the effect COVID-19 has had on the university, our hardware accessibility is been very limited. The extension of the hardware is improving on the control system of a previous team and on using *Onshape* to improve the design of the obtdy of the rocket. 

- Software: The software aspect of the project is not very limited from the lockdown. The software aspect will consist of improving code from a previous team and ensuring it is functional and efficient.  

- Testing facilities: Due to COVID-19 lockdown, it will be unlikely that a testing facility is available for the group to use. The next step is to do testing via simulation. Working with a simulation team will be required. If circumstances change and access to testing facilities become available then the group will have to discuss the possible option. 

- Time: This project runs over two papers ENGR 301 and ENGR 302. This gives the group 30 weeks, however with the first few weeks being introductions realistically the group has about ~27-26 weeks. The lockdown has resulted in a reconstruction of the academic year of Victoria            University of Wellington. This could result in less time.    

- Control & policies: When testing the rocket system we have designed, we need to ensure it is in a controlled environment. We can not breach any laws and restrictions that have been imposed by the goverment due to COVID-19 and we need follow The NZ Rocketry Association rules and regulations.  

- Team interactions: The main form of communication will be through Zoom and Mattermost due to the level 4 lockdown. Zoom meetings are hled every Friday and Monday, and Mattermost chat is constant.

- Personal limitations: All members have personal limitations that should be taken into consideration. This will ensure all members of the group are treated fairly. Other members of the group as well, take other papers. Due dates of important assignments and test will be taken into account, this is design to reduce stress levels of the group. 


## 2. References

References to other documents or standards. Follow the IEEE Citation  Reference scheme, available from the [IEEE website](https://www.ieee.org/) (please use the search box). (1 page, longer if required)

## 3. Specific requirements  

This section describes the external interfaces, functions, usability requirements, performance requirements, logical database requirements, design constraints, nonfunctional system attributes, physical and environment requirements and supporting information.



### 3.1 External interfaces

#### Sensors - Inertial Measurement Unit

The inertial measurement unit (IMU) is an electronic device that measures acceleration, gyroscopic and magnetism data on the avionics package, each in 3 dimensions. This will be used to specifically measure the changes in the linear acceleration, velocity, and orientation of the rocket. The data from this unit will be outputted onto the SD card onboard where the Teensy will also process this information and control the position of the gimbal. This component of the system will require good accuracy plus tolerance as it is vital for the control of the rocket and will need to have a measurable acceleration range suitable for the rocket. The orientation and position of the rocket will be measured on 3 dimensions, in units of metres and degrees respectively. This will be present as part of the onboard avionics package.

#### Data Storage/Transfer - SD Card

An SD card is required to store data that is produced from the IMU, radio antenna, GPS and any other potential sensors. This information is to be processed for control and to be later used for the analysis of the performance of the system. The onboard system will need to be able to write to the SD card at a rate equivalent to the rocket's control loop. This rate will be required to be optimized so that it does not affect processing speed significantly while maintaining maximum control. The SD card must also be large enough to store all the potential data in a test run, with the data being stored in a .txt or .csv file.

#### Communication - Radio Antenna

The radio antenna is required for limited communication of data from the avionics package, using LoRa, to a nearby external computer for monitoring the data and minor adjustments/tuning. The antenna will receive signals from the avionics package and will output transmissions for a receiver antenna. The data sent will be required to be accurate enough to determine the state of the system in real-time and so it can be located easily using the satellite positioning system, GPS, in the case that it is lost. Data transferred during the launch will need to be essential data only as communication should not compromise performace of the control system.  The units of measure for this data will all be SI units and degrees/minutes/seconds for the longitude and latitude. This will play an important role for mission control in the field.

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

See 9.5.12. for most systems this will be around one page.

> **9.5.12 Usability requirements**<br>
> Define usability (quality in use) requirements. Usability requirements and objectives for the software system include measurable effectiveness, efficiency, and satisfaction criteria in specific contexts of use.

### 3.4 Performance requirements

See 9.5.13. for most systems this will be around one page. Hardware projects also see section 9.4.6.

> **9.5.13 Performance requirements** <br>
> Specify both the static and the dynamic numerical requirements placed on the software or on human interaction with the software as a whole.
>
> Static numerical requirements may include the following:
>
> a) The number of terminals to be supported;  
> b) The number of simultaneous users to be supported;  
> c) Amount and type of information to be handled.
>
> Static numerical requirements are sometimes identified under a separate section entitled Capacity.
>
> Dynamic numerical requirements may include, for example, the numbers of transactions and tasks and the amount of data to be processed within certain time periods for both normal and peak workload conditions. The performance requirements should be stated in measurable terms.
>
>  For example, "_95 % of the transactions shall be processed in less than 1 second._" rather than, "An operator shall not have to wait for the transaction to complete."
>
> NOTE Numerical limits applied to one specific function are normally specified as part of the processing subparagraph description of that function.


### 3.5 Logical database requirements

See 9.5.14. for most systems, a focus on d) and e) is appropriate, such as an object-oriented domain analysis. You should provide an overview domain model (e.g.  a UML class diagram of approximately ten classes) and write a brief description of the responsibilities of each class in the model (3 pages).

You should use right tools, preferabley PlantUML, to draw your URL diagrams which can be easily embedded into a Mardown file (PlantUML is also supported by GitLab and Foswiki).

### 3.6 Design constraints

see 9.5.15 and 9.5.16. for most systems, this will be around one page.

> 9.5.15 Design constraints<br>
> Specify constraints on the system design imposed by external standards, regulatory requirements, or project limitations.
>
> 9.5.16 Standards compliance<br>
> Specify the requirements derived from existing standards or regulations, including:
>
> a) Report format;<br>
> b) Data naming;<br>
> c) Accounting procedures;<br>
> d) Audit tracing.
>
> For example, this could specify the requirement for software to trace processing activity. Such traces are needed for some applications to meet minimum regulatory or financial standards. An audit trace requirement may, for example, state that all changes to a payroll database shall be recorded in a trace file with before and after values.

### 3.7 Nonfunctional system attributes

Present the systemic (aka nonfunctional) requirements of the product (see ISO/IEC 25010).
List up to twenty systemic requirements / attributes.
Write a short natural language description of the top nonfunctional requirements (approx. five pages).


### 3.8 Physical and Environmental Requirements

For systems with hardware components, identify the physical characteristics of that hardware (9.4.10) and environment conditions in which it must operate (9.4.11).  Depending on the project, this section may be from one page up to 5 pages.
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

The hardware components must be able to still function within the environment that the rocket will be tested in, this means that the rocket will need to function under certain enviromental condition(s) that are present in the testing environment. The current testing environment is a wide-open park located in Lower Hut Wellington. A certain environmental condition is the wind. Wind levels are never constant and can vairy extremely (especially in our testing environment of Lower Hut Wellington). This means hardware of the rocket must be functioning under considerable wind levels. 

The largest effect wind has on the rocket is displacement. The wind is able to tilt (or even move) the rocket off its current trajectory. This means that hardware of the rocket must be to account for this issue. Combination of the electronic components (microcontroller, gyroscope and sensor module) and the gimble are involved in accounting for the displacement. Using the sensor(s) to detect the displacement, then micro-controller communicates to the gimble to make an adjustment for the displacement. 

The rocket body design is also important to account for wind. A more aerodynamic design will mean that the wind drag will have less of the effect of the rocket. Meaning a more aerodynamic design will result in a smaller displacement. 

Wind will also greatly affect the rocket while the rocket is coming down. The rocket slowly descend due to the parachute being deployed. However, with the parachute deployed the rocket is very susceptible to wind drag. Which means that the rocket might be displaced a large distance from the launch site. A GPS connected to the micro-controller will allow us to track where the rocket lands. Also, modelling of the rockets launch will be done to estimate where the rocket could land. 

Another environmental condition that will need to be taken into account is radio frequency (RF) noise. To communicate to the rocket microcontroller we use a signal in the microwave frequency. So before we can launch the rocket, we will need to check the level of RF noise. If the level of RF noise is too high the launch of the rocket will be postpone, there is no solution where we launch the rocket in high RF noise. If the rocket is launch in during high RF noise we could lose communication with the rocket.

Certain envionmental conditions like rain, high cloud coverage and extreme temperatures will mean that the rocket launch won’t be able to happen. However, these conditions can be prevented by choosing a day launch where these conditions aren’t present. Finally the rocket should not be launch at night time. 


### 3.9 Supporting information

see 9.5.19.

## 4. Verification

3 pages outlining how you will verify that the product meets the most important specific requirements. The format of this section should parallel section 3 of your document (see 9.5.18). Wherever possible (especially systemic requirements) you should indicate testable acceptance criteria.

### 4.1 Verification External Interfaces

### 4.2 Verification Functions

To meet the stakeholder's requirements, ...

To meet the requirements of easy installation, the avioinics package must be assembled into a single unit, with the exception of the battery unit. The avionics package must also be able to fixated with the rocket housing without any wobble.

To meet the requirements of intuitive configuration and calibration, the avionics package should be able to interface directly with the base station without having to re-engineer the hardware of software on either, the avionics package or mission control. Calibration data from simulation teams must be able transfered in a user-friendly manner, such as either directly writing to SD card or wirelessly via the base station. The software on the avionics package should not have to be manually recompiled from the toolchain. 

To meet the requirements of the launch phase, the rocket must launch and sustain vertical trajectory, even under mild weather interference. The avionics package must also allow mission control to remotely tilt the trajectory of the rocket in-flight. The rocket is also expect to land without taking on critical damage, though cosmetic wear is excusable. 

The analysis and diagnosis stage of the rocket's flight also has to meet requirements. Live data such as gyroscope and accelerometer readings must be broadcasted to mission control in real-time. By the end of the flight, the SD card must have all logged flight data recorded as a text file in human-readable format. The avionics package should also be able to broadcast all the logged data if still in wireless range. Mission control should be able to parse all broadcasted data.

### 4.3 Verification Usability Requirements

### 4.4 Verification Performance Requirements

### 4.5 Verification Logical Database Requirements

### 4.6 Verification Design Constraints

### 4.7 Verification Nonfunctional System Attributes

### 4.8 Verification Physical and Environmental Requirements




## 5. Development schedule.

### 5.1 Schedule

Identify dates for key project deliverables:

1. architectural prototype
1. minimum viable product
1. further releases

(1 page).

### 5.2 Budget

Present a budget for the project (table), and justify each budget item (one paragraph per item, one page overall).

### 5.3 Risks

Identify the ten most important project risks to achieving project goals: their type, likelihood, impact, and mitigation strategies (3 pages).

If the project will involve any work outside the ECS laboratories, i.e. off-campus activities, these should be included in the following section.

### 5.4 Health and Safety

Document here project requirements for Health and Safety. All teams must state in this section:

1. How teams will manage computer-related risks such as Occupational Over Use, Cable management, etc.  

2. Whether project work requires work or testing at any external (off-campus) workplaces/sites. If so, state the team's plans for receiving a Health and Safety induction for the external workplaces/sites. If the team has already received such an induction, state the date it was received.

3. Whether project work requires the team test with human or animal subjects? If so, explain why there is no option but for the team to perform this testing, and state the team's plans for receiving Ethics Approval _prior_ to testing.

Also document in this section any additional discussions with the School Safety Officer regarding Health and Safety risks. Give any further information on relevant health and safety regulations, risks, and mitigations, etc.


#### 5.4.1 Safety Plans

Safety Plans may be required for some projects, depending on project requirements. Safety Plan templates are available on the course Health & Safety page. Two questions all teams must answer are:

**Do project requirements involve anything that can cause serious harm or death?**  
Examples: building/modifying devices using voltages > 60 V, chemicals, large moving machinery, flying devices, bodies of water.

If so, you will have to write a separate Safety Plan as part of project requirements, and the Safety Plan must be referenced in this section. For health and safety risks involving serious harm or death, you must first contact the School Safety Officer and Course Coordinator first to discuss the Safety Plan and project requirements.

**Do project requirements involve anything that can cause harm or injury?**  
Examples: building/modifying things with voltages <= 60V, small moving machinery, wearable devices.

If so, you will have to write a separate Safety Plan as part of project requirements, and the Safety Plan must be referenced in this section. For health and safety risks involving harm or injury, you should write a draft of the Safety Plan before contacting the School Safety Officer and Course Coordinator to discuss the Safety Plan and project requirements.

If a safety plan is required, list in this section the date the School Safety officer accepted your Health and Safety plan (if accepted by submission date).

_If the project is purely software and requires no contact risks involving physical harm, then state "Project requirements do not involve risk of death, serious harm, harm or injury." in this section._


## 6. Appendices
### 6.1 Assumptions and dependencies

One page on assumptions and dependencies (9.5.7).

### 6.2 Acronyms and abbreviations

One page glossary _as required_.

## 7. Contributions

A one page statement of contributions, including a list of each member of the group and what they contributed to this document.

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
