/*

THIS HEADER CONTAINS FEATURES THAT ARE YET TO BE COMPLETELY IMPLEMENTED AND TESTED.
USE WITH CARE.

*/

#pragma once
#include "microrender.h"

// from official repo.
// does not contain colors for some elements, so I don't feel comfortable marking this as fully available
// you can put this literally anywhere in your page definition. 
#define MCR_EXPERIMENTAL_ENABLE_THEME_DARK() MCR_CUSTOM_STYLEBLOCK(THEME_DARK)
