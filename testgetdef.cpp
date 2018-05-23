#include <iostream>
#include "soapSKOSWSSoapBindingProxy.h"
#include "SKOSWSSoapBinding.nsmap"

int main(int argc, char *argv[])
{
    SKOSWSSoapBindingProxy service;
    soap_set_imode(&service,SOAP_C_UTFSTRING);
    soap_set_omode(&service,SOAP_C_UTFSTRING);
    _ns1__getDefinitionsResponse result;
    _ns1__getDefinitions  query;
    if (argc > 1)
        query.termcode = argv[1];
    else
        query.termcode = "6599";
    query.languagecode = "EN";
    if (service.getDefinitions(&query, result) == SOAP_OK)
    for (auto s: result.getDefinitionsReturn)
            std::cout << s << "\n";
    else
        service.soap_stream_fault(std::cerr);
    service.destroy();
}


