#include "ajax_demo.h"
#include "../lib/microrender/include/microrender.simpleajax.h"
#include "../lib/microrender/include/microrender.modules.h"

MCR(ajax_demo, AJAX Demo,

MCR_FIXED_HEADERBAR(microrender,
    MCR_LIST_ELEMENT(<a href="https://github.com/bluewingtitan">author</a>)
    MCR_LIST_ELEMENT(<a href="/">Home</a>)
    MCR_LIST_ELEMENT(<a href="/forms">Forms Demo</a>)
)
MCR_BASE(
    MCR_HSPACE(80)
    MCR_ROW(
        MCR_ELEMENT(
            MCR_H1(AJAX Demo)
            MCR_SMALL(... I hope you are doing great today!)
        )
    )
    MCR_HSPACE(20)
    MCR_ROW(
        MCR_ELEMENT(
            MCR_H1(MCRA_ANCHOR_TEXT(visitcountanchor, 0, visit_count) visits on this page (since esp start)!)
            MCRA_TRIGGER_INTERVAL(5000, visitcountanchor)
            MCR_TEXT(This demo is meant to show some basic ajax, that is built straight into microrender!)
            MCR_TEXT(The number above is refreshed every 5 seconds. Try it out, <a href="/ajax" target="_blank">open this page in another tab!</a>)
        )
    )
)
)

