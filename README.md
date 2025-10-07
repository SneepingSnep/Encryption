Hello and welcome to this weeks problem.

In this week i have made an encryption decryption soruce code, and tried to make it look nice with header files and source files
You said that the compiling and running could be done with Make, so that is what i have done, and it took quite some times to get to work.
When you have my git folder opened in your IDE, you should be able to run "make main" and this will build our code and compile all the dependencies.
After this i have made 4 runs for you. that you can acces in the terminal
First run type: make run1
Second run type: make run2
Third run type: make run3
Fourth run type: make run4
This will just give you an idea that the code is working without having to do much
Now if you want to test your own msg the cli for running the code goes like the
compile the code using "make main"
ARGV[1] will be the encryption mode. Either caesar or vinegere.
ARGV[2] will be the msg you would like either encrypted or decrypted. either "e" or "d"
ARGV[3] will be the the choice beetween encryption or decryption.
ARGV[4] is reserved for vingere and will be the key you would like to encrypt with.

Example 
For encryption with caesar
<./main.exe caesar DAMN e>
this will encrypt the msg damn and it will spit out GDPQ
>Note --> You can type c instead of caesar if you please and its not case sensitive

Example
For encryption with 
<./main.exe Vigenere ATTACKATDAWN e LEMON>
this will encrypt the msg ATTACKATDAWN and it will spit out LXFOPVEFRNHR.
>Note --> You can type v instead of Vigenere if you please and its not case sensitive
