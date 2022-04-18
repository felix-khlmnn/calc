# calc

This is just a small calculator that you can use in your command line.  
It's simple to use and without any unnecessary additions.

## Installation
First, you have to compile the source code by executing the following command:

```bash
g++ -o calc calc.cpp
```
Once your `calc` executable is compiled, you can run it either by writing `./calc` in the folder of the executable or by adding it to the corresponding binary locations.

One example of this would be running the following command:
```bash
sudo cp path/to/calc /usr/local/bin/calc 
```
This adds the `calc` executable to the `$PATH` of the user, making it accesible in any shell by simply calling `calc`.

## Usage
As I wrote in the beginning, this little calculator isn't anything fancy.  
After starting the applicaton, you can start writing operations.  
*Limitations:*
- As of right now, operations can only include *one* operator.
- The only operators that are working right now are +, -, * and /.
- Carrying over results (Ans in calculators) is not a thing as of right now  

If you detect any issues, please post an issue. 