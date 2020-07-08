For 
- Nano Jetpack 4.3 
  and 
- Xavier NX Jetpack 4.4

Using res10_300x300_ssd_iter_140000_fp16.caffemodel

Open terminal and do the following in this folder

make clean
make
./Serialize.exe
./Deserialize.exe

Works OK in Nano
In Xavier NX Deserialize.exe causes an assertion and segmentation fault
