# ENGR 301 Group 6 Architectural Design and Proof-of-Concept

* Dylan Sukha, Jason McCormick, Ketaki Bagal, Penny Peneueta, Robert Reid, Rowan Rathod, Sean Osborne-Curtis *

## 1. Introduction

The development of rockets over the last few decades has driven technlogy to grow in many different aspects that affect our everyday lives. Model rockets has become a growing concept globally that has expanded the knowledge and interest greatly. Rockets are susceptible to a variety of disturbances during flight, particular duirng the early stages. Such as unexpected winds, irregulatory and non-symmetrical motors, imparting a random launch angle. These result in unstable flight, by implementing an active control system we can cope with these undesired attributes.

The project aims to investigate and develop an existing avionics control and rocket system. This will implement the further design of an active control which will provide changes depending on the measured state of the rocket using sensors and actuators. This development will be supported by other teams working on a mission control aspect and others focusing on simulation of the rocket and flight.


### Client

Andre Geldenhuis is the client for this project. He can be contacted through email, Andre.Geldenhuis@vuw.ac.nz, or through the mattermost. He is an experienced rocket enthusiast and is a member of the New Zealand Rocketry Association who was the previous client of the 2018 project. His previous experience within the model rocket community is with launching model rockets from high altitude balloons. 


### 1.1 Purpose

The purpose of this system is to develop an existing rocket system and to improve its avionics and flight control, while also developing project managment skills.

### 1.2 Scope

For this project, we are improving and/or fixing a previous team initial system design of a model rocket. Due to the current worldwide event (COVID-19), we have not been able to access hardware. This means that it still a little unclear what exactly requires fixing and what requires improvement. The current task that will need to be down are the following: 
Take the existing avionics board and make it functional work 
To produce a base station to communicate with the rocket 
To develop and/or fix code to get the rocket functioning 
To redesign any parts (I.E body or gimbal) if the said part is not functioning or efficient 


### 1.3 Changes to requirements

If the requirement have changed significantly since the requirements document, outline the changes here. Changes must be justified and supported by evidences, i.e., they must be substantiated. (max one page, only if required)

## 2. References

References to other documents or standards. Follow the IEEE Citation Reference scheme, available from the [IEEE website](https://ieee-dataport.org/sites/default/files/analysis/27/IEEE%20Citation%20Guidelines.pdf) (PDF; 20 KB). (1 page, longer if required)

## 3. Architecture

Describe your system's architecture according to ISO/IEC/IEEE 42010:2011(E), ISO/IEC/IEEE 12207, ISO/IEC/IEEE 15289 and ISO/IEC/IEEE 15288.

Note in particular the note to clause 5 of 42010:

_"The verb include when used in Clause 5 indicates that either the information is present in the architecture description or reference to that information is provided therein."_

This means that you should refer to information (e.g. risks, requirements, models) in this or other documents rather than repeat information.

### 3.1 Stakeholders

See ISO/IEC/IEEE 42010 clause 5.3 and ISO/IEC/IEEE 12207 clause 6.4.4.3(2).

For most systems this will be about 2 pages, including a table mapping concerns to stakeholder.

#### Client 
The client for the rocket project is Andre Geldenhuis. 
For the project, the client requires the avionics package to strictly comply with certain specifications both, software-related and hardware-related. 

#### School of Engineering and Computer Science (ECS)

#### Software Developers and Testers

#### Wider Rocketry Community
The wider rocketry community consists of persons with a profound interest in rocket-related development and innovation. The expectation is that information regarding the avionics package and rocket will be available and usable by the community. 

#### Civil Aviation Authority (CAA)
The Civil Aviation Authorities of New Zealand establish and maintain the rules that all pilots, engineers, aircraft operators, airlines and aerodromes must follow to keep flying safe. The avionics package must follow suit.

#### New Zealand Student Space Association (NZSSA)
The New Zealand Student Space Association (NZSSA) is a student-run organisation with the intentions of following the progress made on the avionics package and rocket. 

#### Local Council
The local council includes the following authoritative bodies: Wellington City Council, Hutt City Council and Upper Hutt City Council. As a collective, the three councils ensure that laws and regulations are complied with in their respective region. In relation to the avionics package, the local council will guarantee that the build and launch of the rocket is compliant with model rocket use requirements in the area. 

#### Local Residents
The local residents include persons who reside in the greater Wellington Region, specifically Upper Hutt City residents that populate the surrounding area of the launch site. 

| Stakeholder  | Concerns |
|--------------|---------|
| Client       | The avionics package must be comprised of fixated and durable components, and should not exceed the specified size of the rocket airframe. It is also expected that the avionics package will interface with the base station and the gimbal to guide the rocket in-flight. Additionally, the avionics package should stabilise the rocket in an upright position pre-launch. The onboard power management must also be able to cope with each state of the rocket's execution. The avionics package-related information and data must be open source and published on the client's GitHub. The concerns listed are acknowledged in order to ensure a successful product for the client.        |
|  Civil Aviation Authority (CAA)            | The CAA requires that all rockets conform to all regulations set out in the CAA rules Part 101 Gyrogliders and Parasails, Unmanned Aircraft (including Balloons), Kites, and Rockets Operating Rules [1]. |
| School of Engineering and Computer Science (ECS)             | The VUW School of engineering and Computer Science requires all parts of the project; to be correctly licensed and follow all relevant guidelines set out by ECS (including but not limited to open software, health and safety, copyrighting, plagiarism etc). |
| Software Developers and Testers            | The Software Developers / Testers require that the avionics package complies with relevant open software and ethics rules.
| Wider Rocketry Community            |  The rocket project must be open source and available to the wider rocketry community. Open source software operates under a license that provides users with the rights to freely use, modify and distribute the software. In this case, the rocketry community would benefit greatly from the rocket project if it is open source, as it can be adapted to future developments.        |
|  New Zealand Student Space Association (NZSSA)             |  The New Zealand Student Space Association (NZSSA) should regularly be kept up-to-date on the development of the avionics package and rocket. The organisation will be able to provide useful advice and information if they are often updated on the progress of the rocket.          |
| Local Council  | The local council requires that the rocket does not violate model rocket use-related laws and regulations. In addition, the council will strictly require that the launch and flight of the rocket does not pose a risk to persons in the vicinity or damage to property in the surrounding area.         |
| Local Residents             | The local residents require an ensurity to their safety. And so the avionics package must conform to all relevant safety regulations and guidelines from relevant organisations and ruling bodies.  |



### 3.2 Architectural Viewpoints
(1 page, 42010 5.4) 

Identify the architectural viewpoints you will use to present your system's architecture. Write one sentence to outline each viewpoint. Show which viewpoint frames which architectural concern.

### 4. Architectural Views

(5 sub-sections of 2 pages each sub-section, per 42010, 5.5, 5.6, with reference to Annex F of both 12207 and 15288) 

Describe your system's architecture in a series of architectural views, each view corresponding to one viewpoint.

You should include views from the following viewpoints (from Kruchten's 4+1 model):

 * Logical
 * Development
 * Process
 * Physical 
 * Scenarios - present scenarios illustrating how two of your most important use cases are supported by your architecture

As appropriate you should include the following viewpoints:

 * Circuit Architecture
 * Hardware Architecture

Each architectural view should include at least one architectural model. If architectural models are shared across views, refer back to the first occurrence of that model in your document, rather than including a separate section for the architectural models.

### 4.1 Logical
...

### 4.2 Development
...

### 4.3 Process
...

### 4.4 Physical 
...

### 4.5 Scenarios
...

## 5. Development Schedule

_For each subsection, make clear what (if anything) has changed from the requirements document._ If unchanged, these sections should be copied over from the requirements document, not simply cross-referenced.

Schedules must be justified and supported by evidences; they must be either direct client requirements or direct consequences of client requirements. If the requirements document did not contain justifications or supporting evidences, then both must be provided here.

### 5.1 Schedule

Identify dates for key project deliverables:

1. prototype(s).
1. first deployment to the client.
1. further improvements required or specified by the client.

(1 page).

### 5.2 Budget and Procurement

#### 5.2.1 Budget

Present a budget for the project (as a table), showing the amount of expenditure the project requires and the date(s) on which it will be incurred. Substantiate each budget item by reference to fulfilment of project goals (one paragraph per item).

(1 page). 

#### 5.2.2 Procurement

Present a table of goods or services that will be required to deliver project goals and specify how they are to be procured (e.g. from the School or from an external organisation). These may be software applications, libraries, training or other infrastructure, including open source software. Justify and substantiate procurement with reference to fulfilment of project goals, one paragraph per item.
(1 page).

### 5.3 Risks 

Identify the ten most important project risks: their type, likelihood, impact, and mitigation strategies (3 pages).

### 5.4 Health and Safety

Document here project requirements for Health and Safety.

#### 5.4.1 Safety Plans

Safety Plans may be required for some projects, depending on project requirements.


## 6. Appendices

### 6.1 Assumptions and dependencies 

One page on assumptions and dependencies (9.5.7) 

### 6.2 Acronyms and abbreviations

One page glossary as required 

## 7. Contributions

An one page statement of contributions, including a list of each member of the group and what they contributed to this document.

---

## Formatting Rules 

 * Write your document using [Markdown](https://gitlab.ecs.vuw.ac.nz/help/user/markdown#gitlab-flavored-markdown-gfm) in your team's GitLab repository.
 * Major sections should be separated by a horizontal rule.


## Assessment 

This document will be weighted at 20% on the architectural proof-of-concept(s), and 80% on the architecture design.

The proof-of-concept will be assessed for coverage (does it demonstrate all the technologies needed to build your project?) and quality (with an emphasis on simplicity, modularity, and modifiability).

The document will be assessed by considering both presentation and content. Group and individual group members will be assessed by identical criteria, the group mark for the finished PDF and the individual mark on the contributions visible through `git blame`, `git diff`, file histories, etc. 

The presentation will be based on how easy it is to read, correct spelling, grammar, punctuation, clear diagrams, and so on.

The content will be assessed according to its clarity, consistency, relevance, critical engagement and a demonstrated understanding of the material in the course. We look for evidence these traits are represented and assess the level of performance against these traits. Inspection of the GitLab Group is the essential form of assessing this document. While being comprehensive and easy to understand, this document must be reasonably concise too. You will be affected negatively by writing a report with too many pages (far more than what has been suggested for each section above).

---
