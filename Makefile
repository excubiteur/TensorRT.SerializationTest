CXX=gcc
CXXFLAGS=-I/usr/local/cuda/include 
LIBS := -lstdc++ \
  -L/usr/local/cuda/lib64 -lcudart -lnvinfer_plugin -lnvcaffe_parser -lnvinfer

all: Serialize.exe Deserialize.exe

Serialize.exe: Serialize.o 
	$(CXX) -o Serialize.exe Serialize.o $(LIBS)

Deserialize.exe: Deserialize.o 
	$(CXX) -o Deserialize.exe Deserialize.o $(LIBS)

clean:
	rm -f *.exe
	rm -f *.o
	rm -f *.bin

	
