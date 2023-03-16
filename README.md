# Project2
Peer reviw input is attached here as a pdf file named ```PHSX815_Project2.pdf```. 
## Simulation
The simulation part of the hypothetical decay process is done by the program ```doDecay.C```. It will ask for an argument to pass. This will be a equal to the number of the events of the decay of a primary particle. 
## Analysis
The analysis part is be done using the program ```DecayAnalysis2.C```. It will also asks for an argument to pass. I have used 1000 for my analysis. So I was using this number as an argument and I also set the number of runs as 10. If we change the argument we also need to make a relevant run numbers and total events for each run. This can be set in the while loop of this program. 

## How to Run the Programs?
I have been using [ C++](https://learn.microsoft.com/en-us/cpp/build/vscpp-step-0-installation?view=msvc-170) and [ROOT](https://root.cern/install/) to develop these programs. In case you are missing the root in your system, you can install from here [https://root.cern/install/]. We can run these programs using [ROOT] *macro* as simply put these commands in your [ROOT] terminal type root[0] **`.x doDecays.C(10000)`** and type root[0] **`.x DecayAnalysis2.C(1000)`**
## Short Comings
This program can not handle the number of runs/experiments and the limits for the number of events in each run. 
