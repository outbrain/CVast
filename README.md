
# CVAST

VAST parser library for client side or server side use.
Validation is done during parsing and throw exception / error on invalid schema.
Header only for use in a C++ project.

# C++
Include cvast.hpp header file in your project.

# Client side
Import the distribution build located in dist/cvast.js. 

# Node.js
N-API binding file will be soon available.

# Usage

    C_vast cvast(std::string xmlString, bool isPermissive = false);  

### C++

    #include "cvast/cvast.hpp"
	
	using namespace Cvast;  
	using namespace VideoTemplate;
	
	...

    C_vast cvast(xmlString, true);  
    Vast vast = cvast.getVast();

Get access to the POD structure using:

    string path = "vast/ad0";  
    Ad* ad = cvast.api<Ad>(path).get();

Or retrieve data using:

    printf("%s\n", ad->attrs.id.c_str());  
    printf("%s\n", cvast.api<>(path).attr("id")->c_str());
   
See example.cpp for more examples.
    
### Javascript
The library call the *_onJSVastLoad* function when the module is loaded and ready to use. 

    function _onJSVastLoad () {  
	    var instance = new Module.JSVast(xmlString, true);
	    console.log(instance.getAttribute('vast/ad0', 'id'));
	    console.log(instance.getValue('vast/ad0/inLine/adSystem'));
	    console.log(instance.getValue('vast/ad0/inLine/adSyste'));
	    instance.delete();  
	}

JavaScript, specifically ECMA-262 Edition 5.1, does not support [finalizers](http://en.wikipedia.org/wiki/Finalizer) or weak references with callbacks.  Therefore, javaScript code must explicitly delete any C++ object handles it has received, or the Emscripten heap will grow indefinitely.

### Node.js
Coming soon

# Data types
*Currency*, *Mimetype* and *event* structures are located in cvast/datatypes/dataTypes.hpp. New events, mime-types or currencies can be added to the lists there.
