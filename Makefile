CXX = g++
CXXFLAGS = -Wall -O2 -g
LDLIBS = -lgsoap++
OBJS = testsimplesearch testconceptbytermcode testgettermbylang testgetdef
#WSDLFILE = http://artemide.art.uniroma2.it/SKOSWS/services/SKOSWS?wsdl
WSDLURL = http://agrovoc.uniroma2.it:8080/SKOSWS/services/SKOSWS?wsdl

all: $(OBJS)

testsimplesearch: testsimplesearch.cpp soapC.o soapSKOSWSSoapBindingProxy.o 

testconceptbytermcode: testconceptbytermcode.cpp soapC.o soapSKOSWSSoapBindingProxy.o 

testgettermbylang: testgettermbylang.cpp soapC.o soapSKOSWSSoapBindingProxy.o 

testgetdef: testgetdef.cpp soapC.o soapSKOSWSSoapBindingProxy.o 

soapC.o: soapC.cpp agrovoc.h

soapC.cpp: agrovoc.h
	soapcpp2 -i -C agrovoc.h

soapSKOSWSSoapBindingProxy.o: soapSKOSWSSoapBindingProxy.cpp soapSKOSWSSoapBindingProxy.h

agrovoc.h:
	wsdl2h -o agrovoc.h $(WSDLURL)

soapSKOSWSSoapBindingProxy.h: agrovoc.h
	soapcpp2 -i -C agrovoc.h
