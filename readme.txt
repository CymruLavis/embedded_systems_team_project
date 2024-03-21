Note to developers: after connecting this repo to your local machine any additional 
class files that need to be used in execution need to be added to the CMakeLists.txt file. That is done by adding 
src/<filename>.cpp to the add_exacutable chain

ensure pigpio library is installed
>> sudo apt install pigpio

install diver for the LCD touch display
>>git clone https://github.com/osoyoo/LCD-show.git
>>cd LCD-show/
>>chmod +x lcd35b-show
>>./lcd35b-show

to run the program make sure you are in the build directory then run the following
>> make
>> ./cocktail_machine


make is the command that will compile the project with our cmake architecture
./cocktail_machine executes/runs the project


#SMART DRINKER COCKTAIL MACHINE PROJECT  
![Logo]()

#University of Glasgow team members:
Ethan Lavis
Daraigh O'Toole Eglington
Joshua Varghese
Roykeane Syangu

The goal of this project is to create an automcatic cocktail dispensor using real time embedded programming on the raspberry pi

![CAD]()
