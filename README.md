# calc

This is just a small calculator that you can use in your command line.  
It's simple to use and without any unnecessary additions.

## Installation
First, you have to compile the source code by executing the following command:

```bash
g++ -o calc calc.cpp
```
Once your `calc` executable is compiled, you can run it either by running `./calc` in the folder of the executable or by adding it to the corresponding binary locations.

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
- The operators +, -, *, /, % and ^ are the only valid operators.

Answers can be carried over by writing `ans` in any part of the operation. 

If you detect any issues, please post an issue. 

## Windows
Windows users don't have the same luxuries as Linux users have: The Windows command prompt doesn't support escape codes to set colors, etc. In order to avoid seeing a lo of gibberish on the screen, Windows users should instead compile the file `wincalc.cpp`, which excludes those escape sequences.