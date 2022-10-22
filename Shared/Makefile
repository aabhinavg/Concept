# Specify extensions of files to delete when cleaning
CLEANEXTS   = o so d 

# Specify the source files, the target files, 
# and the install directory 
SHARED_LIBRARY = library.cpp
OBJECT_FILE    = library.o
SOURCE_FILE    = main.cpp
OUTPUTFILE     = liblibrary.so
INSTALLDIR     = binaries
LIBRARY        = library

.PHONY: all
all: $(OUTPUTFILE)

# Build libgeorgeringo.so from george.o, ringo.o, 
# and georgeringo.o; subst is the search-and-replace 
# function demonstrated in Recipe 1.16
$(OUTPUTFILE):  
	mkdir -p $(INSTALLDIR)
	$(CXX) -c -fPIC $(SHARED_LIBRARY) -o $(OBJECT_FILE) 
	$(CXX) -shared  $(OBJECT_FILE) -o $(OUTPUTFILE)

	mv  $(OUTPUTFILE) $(INSTALLDIR)


.PHONY: clean 
clean:
	for file in $(CLEANEXTS); do rm -rf *.$$file rm -r binaries; done

# Generate dependencies of .ccp files on .hpp files
include $(subst .cpp,.d,$(SOURCES))

#%.d: %.cpp
#	$(CC) -M $(CPPFLAGS) $< > $@.$$$$; \
#		sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
#		rm -f $@.$$$$

.PHONY: use_shared
use_shared:
	cd $(INSTALLDIR)
	$(CXX) $(SOURCE_FILE)  -L$(CURDIR)/$(INSTALLDIR) -l$(LIBRARY) -o $(INSTALLDIR)/out
	echo "Execute the out file from the $(INSTALLDIR)/out"
export LD_LIBRARY_PATH=$(CURDIR)/$(INSTALLDIR)



.PHONY: execute
execute:
	$(INSTALLDIR)/out

	
