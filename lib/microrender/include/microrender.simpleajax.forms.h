/*

Forms extension to simpleajax
Used to implement forms that push data to a server.
Forms may also trigger reloads.


Forms uses MCRA_ as prefix, as it is considered part of simpleajax

*/

#pragma once
#include "microrender.simpleajax.h"

#define MCRA_FORM(_action, _method, content...) <form action=#_action method=#_method>content</form>
#define MCRA_FORM_GET(action, content...) MCRA_FORM(action, GET, content)

#define MCRA_FORM_FIELDSET(content...) <fieldset>content</fieldset>
#define MCRA_FORM_LABEL(_for, content...) <label for=#_for>content</label>
#define MCRA_FORM_TEXTAREA(_placeholder, _id, content...) <textarea placeholder=#_placeholder id=#_id name=#_id>content</textarea>
#define MCRA_FORM_INPUT(_type, _placeholder, _id, content...) <input type=#_type placeholder=#_placeholder name=#_id id=#_id>content</input>
#define MCRA_FORM_TEXT(_placeholder, _id, content...) MCRA_FORM_INPUT(text, _placeholder, _id, content)

#define MCRA_FORM_SELECT(_id, content...) <select id=#_id name=#_id>content</select>
#define MCRA_FORM_SELECT_OPTION(_value, content...) <option value=#_value>content...</option>

#define MCRA_FORM_SEND_BUTTON(label) <input class="button-primary" type="submit" value=#label></input>
#define MCRA_FORM_CANCEL_BUTTON(label) <input class="button-clear" type="reset" value=#label></input>

