 /**@internal
 @file
 \brief module definition/initialization for the generic import infrastructure
 \author Copyright (c) 2002 Benoit Gr�goire bock@step.polymtl.ca
 */

#include "config.h"
#include <glib.h>
#include <libguile.h>

#include "gnc-import-format-gnome.h"
#include "dialog-preferences.h"

#include "gnc-module.h"
#include "gnc-module-api.h"
/* version of the gnc module system interface we require */
int libgncmod_generic_import_LTX_gnc_module_system_interface = 0;

/* module versioning uses libtool semantics. */
int libgncmod_generic_import_LTX_gnc_module_current  = 0;
int libgncmod_generic_import_LTX_gnc_module_revision = 0;
int libgncmod_generic_import_LTX_gnc_module_age      = 0;

/*static GNCModule engine; NOTUSED */

/* forward references */
char *libgncmod_generic_import_LTX_gnc_module_path(void);
char *libgncmod_generic_import_LTX_gnc_module_description(void);
int libgncmod_generic_import_LTX_gnc_module_init(int refcount);
int libgncmod_generic_import_LTX_gnc_module_end(int refcount);


char *
libgncmod_generic_import_LTX_gnc_module_path(void)
{
  return g_strdup("gnucash/import-export");
}
char *
libgncmod_generic_import_LTX_gnc_module_description(void)
{
  return g_strdup("Gnome GUI and C code for the generic import functions");
}
int
libgncmod_generic_import_LTX_gnc_module_init(int refcount)
{
  if(!gnc_module_load("gnucash/engine", 0))
  {
    return FALSE;
  }
  if(!gnc_module_load("gnucash/app-utils", 0))
  {
    return FALSE;
  }
  if(!gnc_module_load("gnucash/gnome-utils", 0))
  {
    return FALSE;
  }

  if (!refcount) {
    gnc_import_format_gnome_register();
    gnc_preferences_add_to_page("generic-import.glade", "matcher_prefs",
				"Online Banking");

  }

  return TRUE;
}

int
libgncmod_generic_import_LTX_gnc_module_end(int refcount)
{
  return TRUE;
}