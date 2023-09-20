/*
Simple AJAX is a basic framework to build dynamic pages.

It's philosophy follows two simple concepts:

    * anchors: In-Page placeholders that can get filled with content. Anchor-elements also define their refresh-functions (except MCRA_ANCHOR_PLAIN)
    * triggers: Different elements to trigger reloads of an anchor
    
    all elements (except MCRA_ANCHOR_PLAIN) automatically trigger their refresh function once on load.

Instead of MCR_ the macros for simpleajax begin with MCRA_

*/

#pragma once

#include "microrender.h"

#define MCRA_ANCHOR_PLAIN(anchor_name, placeholder) <span id=#anchor_name>...</span>

#define MCRA_REFRESH_FUNCTION(anchor_name)refresh_##anchor_name

#define MCRA_ANCHOR_TEXT(anchor_name, placeholder, api_url) MCRA_ANCHOR_PLAIN(anchor_name, placeholder) MCR_CUSTOM_SCRIPTBLOCK(\
    function MCRA_REFRESH_FUNCTION(anchor_name)(){\
        var xhr = new XMLHttpRequest();\
        xhr.onreadystatechange = function() {\
            if (this.readyState == 4 && this.status == 200) {\
                document.getElementById(#anchor_name).innerHTML = xhr.responseText;\
            }\
        };\
        xhr.open('GET', #api_url);\
        xhr.send();\
    };MCRA_REFRESH_FUNCTION(anchor_name)();)

#define MCRA_TRIGGER_INTERVAL(milliseconds, anchor_name) MCR_CUSTOM_SCRIPTBLOCK(setInterval(() => MCRA_REFRESH_FUNCTION(anchor_name)(), milliseconds);)

