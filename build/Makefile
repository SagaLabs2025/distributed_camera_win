.PHONY: all clean

all:
	@echo "Building dcamera_source and dcamera_sink..."
	c++ -std=c++17 -dynamiclib -o libdcamera_source.dylib src/dcamera_source_dll.cpp
	c++ -std=c++17 -dynamiclib -o libdcamera_sink.dylib src/dcamera_sink_dll.cpp

clean:
	rm -f libdcamera_source.dylib libdcamera_sink.dylib
