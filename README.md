This all assumes a linux machine. Sorry.

# To run

    $ make
	
	$ ./main INPUT_FILE_NAME OUTPUT_FILE_NAME
	
# To profile

	$ make clean
	
	$ make profile
	
Because we don't want output to count in our profile, we always write
to `/dev/null` when profiling:
	
	$ ./main INPUT_FILE_NAME /dev/null
	
	$ gprof main > gprof.out
	
The output of gprof is a bit inscrutable, but it's very helpful to
pinpoint places where the code is slow. It's what I've used to
optimize things.

