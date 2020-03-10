# High level requirements

*The focus of the assignment is on the testing, CI, CD and Makefiles.
The project shall use automatic tests, CI, CD, Makefiles and at least some tests
writen in Python. Start with an empty main (or something simple like a print out
to see that it is running) and then continue with CI/CD and Makefile.
Start implementing features by writing test cases and then write the code.*

## The functional stuff
This project concists of a local web page, connected to an esp32.
You should be able to turn on and off a led connected to the esp32 from the web page.

(HTML/PM/CURL) will send a request to (Python with REST api) who will do stuff with it and send it forward to (ESP32).

esp32 will print out its ip adress to the serial port,  which can then be read manually(or otherwise) and will be accessible by the REST api. The REST api is avaiable by HTTP requests like GET and POST (we will use HTML Page or Postman or cUrl). 



## Contenious integration
*This project should rely on git hub actions for contenious integration*
Git hub actions should have platform IO "installed".

On push:
echo "Something was pushed"
makefile build using platform io.
Run python tests.
show status flag in readme.

## Contenious deployment
*This project should rely on git hub actions for contenious deployment*

On push to master:
* echo "release mode activated"
* makefile build using platform io.
* BB tests (this part is ok to skip)
* publish a release with:
* the source files in a .zip file.
* the excecutable (for sending to your own esp32)
* some instructions for installing and using the software.

a configfile containing:
	wifi name.
	wifi password.
	pin on esp32 that led is connected to.
	ip adress to esp32.

it should add a git hub tag (eg. v0.1)


## Automatic tests


### Tests using python

*Some tests should use python.*

Theese tests are the ones that run with git hub actions.
Tests should be added in the list below.

* The code should run.
* Fake ESP32 with python. And run some bb functional tests
* To fetch ip adress, print out via serial port. Test this.
* Test the request from HTML/curl/PM. Fake the response from esp32.
* The program should exit without any errors.


### Tests using C

*Some tests should use unity in C.*

Theese tests should use Unity or platform IO in a separate test file.
Tests should be added in the list below.
Test esp32 sw, the functional code.

* The code should compile.
* the lights on/off should work
* read from serial port. status wifi.
* The code should exit without any errors.



## Makefiles

*This project should rely on one or more makefiles to compile the code and run tests*.\
different targets in the makefile (flags). make one large make file.\

* checkhw(esp32 tests)
* checksw(REST and other python tests)
* all (Build all)
* dist (zip all, there is a way of doing it in yml, but easier to test it if you have a make file).
* clean (Clean and tidy up from old folders and files that does not need to exist anymore).

The makefile should compile the program and all its dependencies using platform IO or equivalent.\


---

###### Version table.
Version |Description |Signed | Date
|--- |							      ---| ---|       ---|
|    |   							 |    |	 	 |
|V0.2|Revised requirements with some descriptions of comunication|Lila|2020-03-10|
|V0.1|Initial structure created				   	 |Lila|2020-03-06|
