# SMART DRINKER COCKTAIL MACHINE PROJECT  
<p align="center">
  <img src="https://github.com/CymruLavis/embedded_systems_team_project/assets/117460546/566dd54f-d8e1-4490-a0ec-afe6613f25f0" width="500" height="500" />


# University of Glasgow team members:
Ethan Lavis  
Daraigh O'Toole Eglington  
Joshua Varghese  
Roykeane Syangu  
Instagram: https://www.instagram.com/smartdrinking_2024/

# Introduction
Do you love to drink but hate the work it takes to make a great cocktail? Do you struggle to know what drinks you can make with the ingredients you have available? Do you not have a live in bartender? Well, look no further as this machine is the answer to all your problems. The smart drinker cocktail machine has a database that has access to a wide variety of drink recipies and can be easily modified to add your own. With the 3D print files available in the CAD folder, a spare raspberry pi and the BOM for all the components, you can have your own cocktail machine up and running in an afternoon. The Smart Drinker is a 6 incredient dispensing machine that creates your favourite drinks in a matter of seconds. No longer will you have to google what drinks can be made with the ingredients available as the database of recipies will do that for you. No longer will you have to search for the recipies as the machine automatically mixes the perfect cocktail at the simple push of a button. If you choose to clone this repo and follow the CAD assembly then you will be left with a useful home appliance that can expand with your tastes.  

# Design
## Required Libraries  
pigpio library:  
$sudo apt install pigpio 

Install cmake  
$sudo apt install cmake

Install the diver for the LCD touch display  
$git clone https://github.com/osoyoo/LCD-show.git  
$cd LCD-show/  
$chmod +x lcd35b-show  
$./lcd35b-show  

Install Qt   
$sudo apt install qtcreator qtbase5-dev qt5-qmake cmake  


Make and run the project  
$cd build
$cmake ..  
$make  
$./CocktailMachine 

## Wiring Diagram
<p align="center">
  <img src="https://github.com/CymruLavis/embedded_systems_team_project/assets/117460546/0bf09030-975e-4d3b-912b-8164f7dd585b" width="500" height="400" />
</p>

## Mechanical Design
<p align="center">
  <img src="https://github.com/CymruLavis/embedded_systems_team_project/assets/117460546/21d57064-cbaa-4a1a-bdc2-5a37108a5809" width="400" height="500" />
</p>

The total foot print of this system is a 400mmx400mmx750mm structure made up by a majority of 3D printed compents. These prints accounted for the brackets that held the components in place, the motor gears, the corner brackets and the plates that encased the electronics. The main skeleton was atattched to 4x steel square tube uprights and the main carousel of the system was mounted to a steel round tube. The footing for the system is a thick piece of MDF that provided a wide stable base and was easy to attatch fasteners to. The assembly of this structure is easy to complete by following the assembly file in the CAD directory. 3M brass inserts are hot set into the PLA components to recieve all the fastener hardware. 

## GUI
The user interface constist of 3 different screes that the user can interact with the system through. There is the "Make Drink", "System Configuration", and "System Status" screens
### Make Drink Screen
<p align="center">
  <img src="https://github.com/CymruLavis/embedded_systems_team_project/assets/117460546/07f87260-f916-4c8b-807b-b34b2cacbbdf" width="400" height="300" />
</p>

The "Make Drink" screen is the main menu where users can choose and preview a drink before sending the commands that will make the drink to the machine.  

### System Configuration Screen
<p align="center">
  <img src="https://github.com/CymruLavis/embedded_systems_team_project/assets/117460546/d16c2eff-97fd-41bb-a6cb-02d87350cc7a" width="400" height="300" />
</p>

The "System Configuration" screen is where users can alter the ingredients that are loaded in the machine and which position the ingredients are loaded to in the physical machine. Once the addition has been made and the refill button has been pressed, the list of available drinks will adapt in the "Make Drink" screen will automatically update. The fill level of the ingredient will also be updated in the "System Status" screen.

### System Status Screen
<p align="center">
  <img src="https://github.com/CymruLavis/embedded_systems_team_project/assets/117460546/1727c2dc-8ba4-42b4-a686-aa1a54876669" width="400" height="300" />
</p>
This screen is where the user can view the fill levels of each ingredient that is loaded into the machine. With this information the system can confirm the drink has enough of each incredient to make the requested drink.

## Software Design
### Class Structure
The objects of the program were broken down into individual classes which made for easy reuse of code for like objects. This also allowed for easy abstraction of data and maintainabilty of the code. The objects have been created for each of the physical components as well as the backend databse 


- OOP class structure
- real time interupts
- operational threads
- how the code operates in their threads
- flow of where the program execution is sent to
- 
### Real Time Components
The real time components for this machine come from the input snesors that control the motors as well as saftey sensors to ensure nobody would be injured during operation by reaching into the machines workspace. All sensors must respond instantaneously as they ensure the machines accuracy, keep the machine from damageing itself, and keep users from being injured. For the saftey sensors a PIR motion sensor as well as a emergency stop button were used with the purpose of if someone were to enter the area that had parts moving, the machine would stop immediately to avoid injury.

For the callibration sensor, a limit switch is used to zero the position of the carousel. This will guarantee that the carousel will reach the correct position and dispense the appropriate ingredient into the glass. Limit switches are also used for the riser platform that will dispense the ingredients. An upper and lower switch are installed to keep the riser motor from passing physical limits that could damage the cup or the rest of the machine.  

All of these components work together in an event driven manner using interupts and callbacks to allow for precise readings of the GPIO pins. They're operations have also been broken up into threads which allow the different functions of the machine to operate in parallel in order not to block their operation. While the system waits for a user to input a drink order these threads sleep to conserve system and computational power. 

# Testing/Results
Each section of the system was tested individually to understand how the components worked on their own before incorporating them into the main operation. Each of these tests can be found in the UnitTests directory. By using the unit tests, small scale operations of threads and callbacks were able to be focused on thus making the final implementation of everything go alot smoother. This also reduced the amount of debugging that had to be completed once all the components were merged together. 

The main unit tests included tests on the database, individual motors, integrating motors with input sensors, running the make drink logic with the motors and associated limit switches. These tests and even more tests of a smaller scale were completed to ensure proper functioning of the machine through every step of the process. Some issues that the team came across during the testing was the use of threads that were inadvertently blocking the main thread which went against the main goal of the project. These were overcome by (HOW DID WE OVER COME THIS) utilizing callback functions that were local in the main function rather then in a different class that was found to be the culprit of the main thread blocking.

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


# References
[PIGPIO Library Documentation](https://abyz.me.uk/rpi/pigpio/)

- links to documentation

