
OUTPUT	:= hellocerflet.exe

SOURCES	:= HelloCerflet.cpp \
			../lib/httpcerflet.cpp
			
INCLUDES := -I../lib/

CC_FLAGS := -Og -DPOCO_WIN32_UTF8

LD_FLAGS := -lPocoNet.dll -lPocoFoundation.dll -lPocoUtil.dll


all: 
	g++ -o $(OUTPUT) $(SOURCES) $(INCLUDES) $(CC_FLAGS) $(LD_FLAGS)
