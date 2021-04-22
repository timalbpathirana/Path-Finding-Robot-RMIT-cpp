# Thanks for checking out my Path Finding Robot.
![banner](https://user-images.githubusercontent.com/68840709/115535394-0e382f00-a2dc-11eb-978e-f5aafcf8d537.png)


#### This is an individual assignment by RMIT University to build a path finding robot using c++.
### Features-
- This only works for 20 x 20 maze env and I assumed that the robot knows the start point and end end point before searching the path.
- In Forward Search method, it will search through the neighbour nodes and collecting the nodes which are accessble. 
- Then it does a back tracking from finish to start to determine the fastest path.
- Then it will output the best path from start to finish. 

###Compiling and Running

####Compiling the code

`$ g++ -Wall -Werror -std=c++14 -O -o assign1 Node.cpp NodeList.cpp PathSolver.cpp main.cpp`

#### Running the code using input4.txt
`$ ./assign1 < testFiles/envTesting/env4/input4.txt `

### Screenshot

![c++ thingy](https://user-images.githubusercontent.com/68840709/115537819-8d2e6700-a2de-11eb-9124-afd12171c975.png)

#### For any inquiries, contact me on my linkedIn @timalpathirana
