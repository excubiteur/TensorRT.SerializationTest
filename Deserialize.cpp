#include <iostream>
#include <fstream>
#include <cuda_runtime.h>
#include <NvInferPlugin.h>
#include <NvInfer.h>
#include <NvCaffeParser.h>
#include <vector>

using namespace std;

class Logger : public nvinfer1::ILogger 
{
public:
	void log(nvinfer1::ILogger::Severity severity, const char *msg) override
	{
		switch(severity)
		{
			case nvinfer1::ILogger::Severity::kINTERNAL_ERROR:
				cout<<"INTERNAL:"<<msg<<endl;
				break;
			case nvinfer1::ILogger::Severity::kERROR:
				cout<<"ERROR:"<<msg<<endl;
				break;				
			case nvinfer1::ILogger::Severity::kWARNING:
				cout<<"WARNING:"<<msg<<endl;
				break;					
			case nvinfer1::ILogger::Severity::kINFO:
				cout<<"INFO:"<<msg<<endl;
				break;			
			case nvinfer1::ILogger::Severity::kVERBOSE:
				cout<<"VERBOSE:"<<msg<<endl;
				break;				
		}		
	}
};

static Logger logger;

int main()
{
  const char * serialized = "serialized.bin";
  initLibNvInferPlugins(&logger, "");
  cout<<"Deserialize"<<endl;
  std::ifstream in(serialized, std::ios::binary | std::ios::ate);
  if(in)
  {
    std::streamsize size = in.tellg();
    in.seekg(0,std::ios::beg);
    std::vector<char> buffer(size);
    if(in.read(buffer.data(),size))
    {
      nvinfer1::IRuntime* runtime = nvinfer1::createInferRuntime(logger);
      auto engine = runtime->deserializeCudaEngine((const void *)buffer.data(), (std::size_t)size, nullptr);		   
      auto context = engine->createExecutionContext();				
    }    
  }
  cout<<"Deserialize Done"<<endl;
}
