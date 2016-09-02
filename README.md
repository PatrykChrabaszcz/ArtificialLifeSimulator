Artificial Life Simulator
======================

Project for "Advanced C++ Programming" course

In the enviroment there are three types of objects: Plants, PlantEaters and MeatEaters. 
They interact with each other in a specific way. Plants are stationary, they have some 
"energy" which is transfered when they are "attacked" by PlantEaters, similary PlantEaters
have "energy" which is transfered when they are "attacked" by MeatEaters. Both PlantEaters 
and MeatEaters are equiped with a set of motors and sensors. Additionaly they have a "brain" 
which maps inputs from sensors to motors. Brains of those animals can evolve in a specific way
described by Mutator. Idea is to create new animals from those that were best suited for the 
enviroment.

There is a simple implementation of the brain, which is based on static predefined Artificial Network.
There is also a simple implementation of the Mutator class, but it's quite random and needs an improvement. 

It's quite interesting to see the behaviour of the animals, as some of them can correctly sense food and 
move in a right direction while others got stuck on the border or move in a random way. Better implementation
of the Mutator class could keep the "right" behaviours in the population and get rid of the "wrong" ones

![alt tag](https://github.com/PatrykChrabaszcz/ArtificialLifeSimulator/blob/master/Pictures/Window.jpg)

One of the tasks was to achive modularity of different parts of the code, and use make use of design patterns 
presented in the lecture. Thanks to that it's easy to:
1. Add new Brain classes that will map sensor input into movements of a robot 
2. Add new Mutator classes that will combine two brains into new one (evolution)
3. Add new PhysicEngine classes that will update animals and the enviroment based on animals motors 


Youtube Video: https://www.youtube.com/watch?v=EGKi2akZbAY

Application in C++ using Qt library and a little bit of QML, working on  Ubuntu 12.04

Libraries:
Qt5
fann 
