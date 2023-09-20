#include "form_demo.h"
#include "../lib/microrender/include/microrender.simpleajax.forms.h"
#include "../lib/microrender/include/microrender.modules.h"


MCR(forms_demo, Forms Demo,

MCR_FIXED_HEADERBAR(microrender,
    MCR_LIST_ELEMENT(<a href="https://github.com/bluewingtitan">author</a>)
    MCR_LIST_ELEMENT(<a href="/">Home</a>)
    MCR_LIST_ELEMENT(<a href="/ajax">AJAX Demo</a>)
)
MCR_BASE(
    MCR_HSPACE(80)
    MCR_ROW(
        MCR_ELEMENT(
            MCR_H1(Forms Demo)
            MCR_SMALL(... I hope you are doing great today!)
        )
    )
    MCR_HSPACE(20)
    MCR_ROW(
        MCR_ELEMENT(
            MCR_H3(Last Message: )
            MCRA_ANCHOR_TEXT(last_message_text, (loading), /last_message)
            MCRA_TRIGGER_INTERVAL(5000, last_message_text)
        )
    )
    MCR_HSPACE(20)
    MCR_ROW(
        MCRA_FORM(/form_submit, POST, 
            MCRA_FORM_FIELDSET(
                MCRA_FORM_LABEL(form_name, Your Name)
                MCRA_FORM_TEXT(Type in your name, form_name)
                MCRA_FORM_LABEL(form_message, Your Message)
                MCRA_FORM_TEXT(Type in your message, form_message)
                MCRA_FORM_SEND_BUTTON(Send Message...)
            )
        )
    )
)
)

MCR(forms_demo_sent, Forms Demo,

MCR_FIXED_HEADERBAR(microrender,
    MCR_LIST_ELEMENT(<a href="https://github.com/bluewingtitan">author</a>)
    MCR_LIST_ELEMENT(<a href="/">Home</a>)
    MCR_LIST_ELEMENT(<a href="/ajax">AJAX Demo</a>)
)
MCR_BASE(
    MCR_HSPACE(80)
    MCR_ROW(
        MCR_ELEMENT(
            MCR_H1(Forms Demo)
            MCR_SMALL(... I hope you are doing great today!)
        )
    )
    MCR_HSPACE(20)
    MCR_ROW(
        MCR_ELEMENT(
            MCR_H2(Your message was sent! Look into the ESPs Serial Output!)
            <a href="/forms">Back to form page</a>
        )
    )
)
)
