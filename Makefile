# get current Makefile location
PAPIINC = $(shell pwd)/papi-5.5.1/src/
PAPILIB = $(shell pwd)/papi-5.5.1/src/libpapi.a

CC = gcc
CFLAGS += -I$(PAPIINC) -std=c99 ${type}
OS = $(shell uname)

TARGETS_NTHD =  multiply_matrix

TARGETS_PTHREAD = 

ifeq ($(OS), SunOS)
   LDFLAGS =  $(PAPILIB) -lcpc
   LDFLAGS_PTHREAD =  $(PAPILIB) -lpthread -lcpc
   TARGETS = $(TARGETS_NTHD) $(TARGETS_PTHREAD) 
else 
 ifeq ($(OS), AIX)
   CC = xlc
   LDFLAGS =  $(PAPILIB) -lpmapi
   LDFLAGS_PTHREAD =  $(PAPILIB) -lpthread -lpmapi
   TARGETS = $(TARGETS_NTHD) $(TARGETS_PTHREAD) 
 else
    ifeq ($(OS), OSF1)
        LDFLAGS =  $(PAPILIB) -lrt
        LDFLAGS_PTHREAD =  $(PAPILIB) -lpthread -lrt
        TARGETS = $(TARGETS_NTHD)  
    else
        ifeq ($(OS), Linux)
             TARGETS = $(TARGETS_NTHD) $(TARGETS_PTHREAD) 
        else
             TARGETS = $(TARGETS_NTHD)  
        endif
        LDFLAGS =  $(PAPILIB) 
        LDFLAGS_PTHREAD =  $(PAPILIB) -lpthread
    endif
 endif
endif

all: $(TARGETS) 

$(TARGETS_NTHD):  %:%.o 
	$(CC) -o $@ $(CFLAGS) $^ $(LDFLAGS)

$(TARGETS_PTHREAD):  %:%.o 
	$(CC) -o $@ $(CFLAGS) $^  $(LDFLAGS_PTHREAD)
clean:
	$(RM) *.o $(TARGETS) 

