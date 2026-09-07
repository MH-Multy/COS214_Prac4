# COS214_Prac4 How to run

## It is Required for the host machine to have Docker installed

1. Build the Docker Image
Open a terminal in project directory and run:
docker build -t taskforge

2. Start the Docker Container
Run this command in project directory:
(Linux/macOS/Git)
docker run -it --rm -v "$(pwd):/app" taskforge

(Windows PowerShell)
docker run -it --rm -v "$(PWD):/app" taskforge

3. Build the Program
Inside the Docker container run:
make

4. Excute the Program
Run:
./taskforge

5. Debug with GDB
gdb ./taskforge

Inside GDB, the program can be run with:
run

Useful commands in GDB:
break main
next
continue
backtrace
quit

6. Check the Program with Valgrind for leakes
Run Valgrind with:
valgrind --leak-check=full ./taskforge

7. To clean up
To remove compiled files run:
make clean