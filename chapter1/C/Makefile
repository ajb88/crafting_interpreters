CXX = gcc
LINK = gcc

TARGET = test



SRCDIR := src
INCDIR := include
BUILDDIR := obj
TARGETDIR := bin

vpath %$(SRCEXT) $(SRCDIR)
vpath %$(HEADEREXT) $(INCDIR)
vpath %$(OBJEXT) $(BUILDDIR)
vpath % $(TARGETDIR)

SRCEXT := .c
HEADEXT := .h
OBJEXT := .o


CXXFLAGS := -Wall -g
INC := -I$(INCDIR) -I/usr/local/include
LIB := -lm





################################################################################
# NO TOUCHING
################################################################################

SOURCES := $(wildcard $(SRCDIR)/*$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%, $(BUILDDIR)/%, $(patsubst %$(SRCEXT), %$(OBJEXT), $(SOURCES)))


.PHONY: all cleaner directories TAGS

all: directories $(TARGET) 

remake: cleaner all

directories:
	@mkdir -p $(TARGETDIR)
	@mkdir -p $(BUILDDIR)

clean:
	rm -rf $(BUILDDIR)

cleaner: clean
	rm -rf $(TARGETDIR)

TAGS:
	find . -name "*.cpp" -print -or -name "*.hpp" -print | xargs etags --append

# Link
$(TARGET): $(OBJECTS)
	$(LINK) -o $(TARGETDIR)/$(notdir $@) $^ $(LIB)

$(BUILDDIR)/%$(OBJEXT): %$(SRCEXT)
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $(BUILDDIR)/$(notdir $@) 

print-% : ; @echo $* = $($*)

