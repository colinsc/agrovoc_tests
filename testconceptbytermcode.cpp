#include <iostream>
#include "soapSKOSWSSoapBindingProxy.h"
#include "SKOSWSSoapBinding.nsmap"

int main(int argc, char *argv[])
{
    SKOSWSSoapBindingProxy service;
    soap_set_imode(&service,SOAP_C_UTFSTRING);
    soap_set_omode(&service,SOAP_C_UTFSTRING);
    _ns1__getConceptInfoByTermcodeResponse result;
    _ns1__getConceptInfoByTermcode  query;
    if (argc > 1)
        query.termCode = argv[1];
    else
        query.termCode = "6599"; // default rice
    if (service.getConceptInfoByTermcode(&query, result) == SOAP_OK)
        for (auto s : result.getConceptInfoByTermcodeReturn)
            std::cout  << s << "\n";
    else
        service.soap_stream_fault(std::cerr);
    service.destroy();
}


