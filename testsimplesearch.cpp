#include <iostream>
#include "soapSKOSWSSoapBindingProxy.h"
#include "SKOSWSSoapBinding.nsmap"

int main(int argc, char *argv[])
{
    SKOSWSSoapBindingProxy service;
    soap_set_imode(&service,SOAP_C_UTFSTRING);
    soap_set_omode(&service,SOAP_C_UTFSTRING);
    _ns1__simpleSearchByMode2Response result;
    _ns1__simpleSearchByMode2  query;
    if (argc > 1)
        query.searchString = argv[1];
    else
        query.searchString = "rice";  // default search
    query.searchmode = "starting";
    if (service.simpleSearchByMode2(&query, result) == SOAP_OK)
        std::cout << result.simpleSearchByMode2Return << "\n";
    else
        service.soap_stream_fault(std::cerr);
    service.destroy();
}


