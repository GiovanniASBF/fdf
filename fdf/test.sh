#!/bin/sh

# Exit immediately if a command fails
set -e

# 1. Build the test executable
make test

# 2. Run the test executable
./test_runner

# 3. Clean up the test files
make tclean

# Optional: Tell the user it's done
echo "Test script finished successfully."

#/**
#"!/bin/sh" is called a shebang (or hashbang).
#It's a special instruction at the very beginning of a script 
#that tells your operating system which program to use to run the rest of the lines in the file.
#    #! is the marker that tells the OS, "This is a shebang."
#    /bin/sh is the path to the program (the interpreter) that should be used. 
#	sh is a standard, widely-available command-line interpreter (a shell).
#In short, "#!/bin/sh" just means: 
#"Hey, operating system! Don't just read this file. 
#You need to run it using the sh program." 
#This is what allows you to execute your script just by typing ./test.sh instead of sh test.sh
