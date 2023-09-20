#pragma once

#include <pgmspace.h>
#include "css.h"
#include "microrender.special_characters.h"

#define PGM_P       const char *
#define PGM_VOID_P  const void *
#define PSTR(s) (__extension__({static const char __c[] PROGMEM = (s); &__c[0];}))

#define MCR_header0 <!DOCTYPE html><html><head><link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Roboto:300,300italic,700,700italic"><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1.0"><title>
#define MCR_header1 </title></head>
#define MCR_body0 <body><style>
#define MCR_body1 </style>
#define MCR_footer </body></html>




#define MCR_STRINGIFY(x...) #x
#define MCR_EXPAND_THEN_STRINGIFY(content...) MCR_STRINGIFY(content)

#define MCR_HEADER(title...) MCR_header0 title MCR_header1 MCR_body0 MILIGRAM_CSS MCR_body1
#define MCR_BODY(content...) content MCR_footer

#define MCR(module_name, title, body)\
auto module_name() -> PGM_P\
{\
 PGM_P content PSTR(MCR_EXPAND_THEN_STRINGIFY(MCR_HEADER(title)MCR_BODY(body)));\
 return content;\
}\

#define MCR_ELEMENT(content...) <div class="column"> content</div>
#define MCR_ROW(contents...) <div class="row"> contents </div>
#define MCR_BASE(contents...) <div class="container">contents</div>

// text elements
#define MCR_H1(title...) <h1>title</h1>
#define MCR_H2(title...) <h2>title</h2>
#define MCR_H3(title...) <h3>title</h3>
#define MCR_H4(title...) <h4>title</h4>
#define MCR_H5(title...) <h5>title</h5>
#define MCR_H6(title...) <h6>title</h6>
#define MCR_SMALL(title...) <small>title</small>
#define MCR_TEXT(content...) <p>content</p>
#define MCR_BREAK <br/>
#define MCR_QUOTE(content...) <blockquote>content</blockquote>
#define MCR_CODE(content...) <pre><code>content</code></pre>
#define MCR_ORDERED_LIST(elements...)<ol>elements</ol>
#define MCR_UNORDERED_LIST(elements...)<ul>elements</ul>
#define MCR_LIST_ELEMENT(text...)<li>text</li>
#define MCR_HSPACE(pixel)<div style=MCR_EXPAND_THEN_STRINGIFY(height: pixel##px;)></div>
#define MCR_WSPACE(pixel)<div style=MCR_EXPAND_THEN_STRINGIFY(width: pixel##px;)></div>
#define MCR_CUSTOM_STYLEBLOCK(blockcontent...)<style>blockcontent</style>
#define MCR_CUSTOM_SCRIPTBLOCK(blockcontent...)<script type="text/javascript">blockcontent</script>
#define MCR_STRONG(content...)<strong>content</strong>


