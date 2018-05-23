#include <iostream>
#include "soapSKOSWSSoapBindingProxy.h"
#include "SKOSWSSoapBinding.nsmap"

int main(int argc, char *argv[])
{
    SKOSWSSoapBindingProxy service;
    soap_set_imode(&service,SOAP_C_UTFSTRING);
    soap_set_omode(&service,SOAP_C_UTFSTRING);
    _ns1__getTermByLanguageResponse result;
    _ns1__getTermByLanguage  query;
    if (argc > 1)
        query.termcode = argv[1];
    else
        query.termcode = "6599";
    query.language = "en";
    if (service.getTermByLanguage(&query, result) == SOAP_OK)
        std::cout << result.getTermByLanguageReturn << "\n";
    else
        service.soap_stream_fault(std::cerr);
    service.destroy();
}


