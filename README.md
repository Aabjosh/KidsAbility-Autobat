# KidsAbility-Autobat
This is the .ino code used for my basic automatic batting mechanism created for KidsAbility. Here I employed a CIM motor, Talon SR, and a custom power distributor to actuate the system.

## How it works
Using a right-angle drive 45:1 planetary gear box hybrid system, a control system using an Arduino Uno and a custom power distribution switch circuit board, and a Jellybean Button (headphone jack) actuation signal, a bat is automatically swung to hit a softball standing on an upright. The way this works is by using a post to tension a car jack spring on which the bat is fastened, which releases it with a force great enough to launch the ball 10-20 meters on average. Although no encoder was used, the bat is timed variably to return to its starting position using a random value from a set, to accomodate for biases in release pressure that can influence the spinning upright's angle. 

## Accomodations
- There are two power switches for safety
  - A red industry-standard "kill switch" is included for power cutoff in dangerous situations
  - An illuminated secondary power button for a "live" warning 
- All wires are wrapped in bright tape to limit the chances of seperation or exposure
- The Arduino Uno, custom power distributor, Talon SR, CIM motor, and drive gearbox are all enclosed within the wooden frame designed in Inventor
- The battery can be charged directly using an integrated port on the wooden frame to limit the possibility of toxicity or short circuiting when the battery is exposed to an uninformed environment
- The Jellybean button can be easily switched out due to its headphone jack connection

## Outcomes
- Effectively reduced the cost for KidsAbility to receive such a system by ~10x, while providing the same benefits (total cost under $400 to produce)
- Created to mitigate antisociality/negative mental health and a lack of physical activity in students with muscular or coordinative deficits who would otherwise be unable to participate in such a game
- Provided valuable industrial experience in project development and applicable problem solving
- Inspired me to create an organization dedicated to finding issues in communities that can be solved by students everywhere by engineering and programming means

Videos, CAD files, instructions... to be uploaded shortly.

