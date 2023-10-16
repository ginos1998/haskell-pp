## Run on GNU/Linux

Open a terminal, move to dijkstra-cpp folder and execute this line:

```
g++ -std=c++14 -Iinc src/dijkstra.cpp main.cpp -o dijkstra_executable
```

## Run on Mac OS

After this [instructions](https://www.macports.org/install.php), open a terminal and install clang-14

```
sudo port install clang-14
```

To compile some .cpp, execute

```
clang++ -std=c++14 -o exe HelloWorld.cpp
```

