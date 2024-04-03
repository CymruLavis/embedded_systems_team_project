# SMART DRINKER COCKTAIL MACHINE PROJECT  
<p align="center">
  <img src="https://github.com/CymruLavis/embedded_systems_team_project/assets/117460546/ada58828-ce8b-49c5-b7a1-eae68de5f26a" width="500" height="500" />
</p>

# University of Glasgow team members:
Ethan Lavis  
Daraigh O'Toole Eglington  
Joshua Varghese  
Roykeane Syangu  
Instagram: https://www.instagram.com/smartdrinking_2024/

# Introduction
- project overview
- what problem are we solving

# Design
## Mechanical Design
<p align="center">
  <img src="https://github.com/CymruLavis/embedded_systems_team_project/assets/117460546/8fb6be22-de2b-4759-af3b-0c6318214bfe" width="600" height="500" />
</p>
![0001]()


- description of physical foot print
- materials used
- assembly

## GUI
- description of the screens and their purposes


## Software Design
- OOP class structure
- real time interupts
- operational threads
- how the code operates in their threads
- flow of where the program execution is sent to

# Real Time Components
discuss the real time requirement of the sub system, how our system meets that requirement, concequence of not meeting the requirement
- limit switches controlling the limits of the riser motor
- light gate controlling the position of the carousel
- Saftey switch

# Testing/Results
- unit tests
- what was tested
- problems we ran into
- how did we over come them

# How to build
- description of the base and cad files


## BOM
2x Nema 17 Stepper Motors: [Stepper Motors](https://www.omc-stepperonline.com/e-series-nema-17-bipolar-42ncm-59-49oz-in-1-5a-42x42x38mm-4-wires-w-1m-cable-connector-17he15-1504s)  
2x Motor Drivers: [Motor Drivers](https://www.amazon.co.uk/DRV8825-Stepper-Suitable-8-2V-45V-Printer/dp/B0CCRXGKLV/ref=asc_df_B0CCRXGKLV/?tag=googshopuk-21&linkCode=df0&hvadid=676281988980&hvpos=&hvnetw=g&hvrand=9779484524365892202&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9046941&hvtargid=pla-2199438568706&psc=1&mcid=84474ad0e18b36dd88e4615ffa743992&gad_source=1)  
1x 3.5inch LCD Touch Screen: [Touch Screen](https://www.amazon.co.uk/OSOYOO-Monitor-Raspberry-480x320-Interface/dp/B085TC5YMR/ref=sr_1_2?crid=350DIB5BWBZKX&keywords=raspberry+pi+touch+screen&qid=1707564275&refinements=p_36%3A-2500&rnid=428432031&sprefix=raspberry+pi+touch+scre%2Caps%2C331&sr=8-2)  
1x PIR Motion Sensor: [Motion Sensor](https://thepihut.com/products/pir-motion-sensor-module)  
1x Light Gate Sensor: [Light Gate](https://uk.rs-online.com/web/p/photoelectric-sensors/8074251)  
3x Limit Switches: [Limit Switch]()  

6x Optic Despensers: [Optic Despensers](https://www.ascotwholesale.co.uk/25ml-black-solo-measure?gad_source=1&gclid=Cj0KCQiA2KitBhCIARIsAPPMEhI-lrBpNzira6xwn5WM-c0KxcxK5rm4lakar9NHSMJ1Z-R5aHvze0YaAg49EALw_wcB)  
4x 700mmx12.7mm Square Tubing: [Square Tubing](https://www.metals4u.co.uk/materials/mild-steel/mild-steel-box-section/2371-p)  
1x 700mmx8mm Round Tubing: [Round Tubing](https://www.metals4u.co.uk/materials/mild-steel/mild-steel-tube/tube/9135-p)  
6x Velcro Straps: [Velcro](https://www.amazon.co.uk/VELCRO%C2%AE-Brand-ONE-WRAP%C2%AE-double-Strapping/dp/B0777LN5VP/ref=sr_1_28?keywords=velcro%2Bstraps&qid=1707687068&sr=8-28&th=1)  
Ball Bearings: [Ball Bearings](https://www.amazon.co.uk/sourcingmap-Groove-Bearing-Double-Bearings/dp/B07FDYTJS5/ref=sr_1_9?crid=3U5Z2J0HP3Q6U&keywords=pack%2Broller%2Bbearing%2B8mm%2BID&qid=1707647883&sprefix=pack%2Broller%2Bbearing%2B8mm%2Bid%2Caps%2C95&sr=8-9&th=1)  
Trust Bearings: [Thrust Bearings](https://www.amazon.co.uk/sourcingmap-Single-Direction-Thrust-Bearings/dp/B07G8QDQVM/ref=sr_1_6?crid=3UM1LOAX4JADQ&keywords=thrust+bearing&qid=1707732710&sprefix=thrust+bearing+%2Caps%2C288&sr=8-6)  


## Wiring Diagram
<p align="center">
  <img src="https://github.com/CymruLavis/embedded_systems_team_project/assets/117460546/0bf09030-975e-4d3b-912b-8164f7dd585b" width="300" height="500" />
</p>
## Required Libraries  
pigpio library is installed  
$sudo apt install pigpio 

diver for the LCD touch display  
$git clone https://github.com/osoyoo/LCD-show.git  
$cd LCD-show/  
$chmod +x lcd35b-show  
$./lcd35b-show  

cmake
$sudo apt install cmake

build an 
$cmake ..
$make  
$./cocktail_machine 
# References
- links to documentation

