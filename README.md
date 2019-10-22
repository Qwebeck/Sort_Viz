# Sort_Viz
C++ vizualization to vizualize buble sort algorithm.
In order to execute vizualization you should do next steps:

First - check for g++ installed with command:
`g++ -v`
In case your ouput will look like `# g++: command not found`, you should install it with commands:
```
sudo apt-get update
sudo apt-get install g++
```
First - install SFML library with command:
`sudo apt-get install libsfml-dev`

Then you should copy a repository with command:
`git clone https://github.com/Qwebeck/Sort_Viz.git`

Open a folder with command:
`cd Sort_Viz`

Type 
``` 
g++ -c main.cpp
g++ main.o -o alg-vizualization -lsfml-graphics -lsfml-window -lsfml-system
```
Now had compiled a source code, so you can execute it with command `./alg-vizualization`
