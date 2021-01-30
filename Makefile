

all: release

clean:
	rm -fR build/*

release: 
	mkdir build ; cd build ; cmake .. -DCMAKE_BUILD_TYPE=Release
	echo "cd build and then type make"

debug: 
	mkdir build ; cd build ; cmake .. -DCMAKE_BUILD_TYPE=Debug
	echo "cd build and then type make"

	
