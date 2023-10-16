# Introducction

The objective of this project is to implement Dijkstra's algorithm in c++14 with a functional paradigm, using the same functions used to implement this algorithm in haskell (../dijkstra.hs). 

## Implementation

We kept the functional paradigm using **pure functions** such as 'inicializarPesos', 'obtenerNoConocidos', 'actualizarResultados', and 'obtenerPesoArista'. They have no side effects, and their result depends solely on their inputs, making the code more understandable and reasoning-friendly.

**Immutability** is another concept that we've used. Data, such as weight vectors, previous vectors, traversed vectors, known vertices, and unknown vertices, is updated by creating new vectors instead of modifying existing ones. This promotes data immutability, another functional programming principle. Also, **Immutability of Input Data** in the Input data, such as the graph and vertices, is passed as constants, indicating that it should not be modified within the functions.

Besides, **Function Composition**: Functions are composed to perform more complex tasks; for example, the dijkstra function uses other functions like initializeWeights, getUnknownVertices, and updateResults.

It's important to note that while the functional programming paradigm has been followed to a large extent, C++ is not a purely functional language, and certain language features may require certain deviations. However, we've made an effort to implement the code in a way that favors functional programming principles whenever possible.


## Run on GNU/Linux

Open a terminal, move to dijkstra-cpp folder and execute this line:

```
g++ -std=c++14 -Iinc src/dijkstra.cpp main.cpp -o dijkstra_executable
```
Then, an executable file is created. In this case, it's named 'dijkstra_executable' so we can execute this program in a terminal with
```
./dijkstra_executable
```

## Run on Mac OS

After this [instructions](https://www.macports.org/install.php), open a terminal and install **clang-14**

```
sudo port install clang-14
```

To compile some .cpp, execute

```
clang++ -std=c++14 -o exe HelloWorld.cpp
```

