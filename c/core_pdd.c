/* radare - LGPL - Copyright 2018 - pancake, deroad */
#if 0
gcc -o core_test.so -fPIC `pkg-config --cflags --libs r_core` core_test.c -shared
mkdir -p ~/.config/radare2/plugins
mv core_test.so ~/.config/radare2/plugins
#endif

#include <r_anal.h>
#include <r_cmd.h>
#include <r_cons.h>
#include <r_core.h>
#include <r_lib.h>
#include <r_types.h>
#include <string.h>

#undef R_API
#define R_API static
#undef R_IPI
#define R_IPI static
#define SETDESC(x, y) r_config_node_desc(x, y)
#define SETPREF(x, y, z) SETDESC(r_config_set(cfg, x, y), z)

/* for compatibility. */
#ifndef R2_HOME_DATADIR
#define R2_HOME_DATADIR R2_HOMEDIR
#endif

static int cmd(void *user, const char *input) {
    printf("cmd, user: %s, input: %s\n", user, input);
}

int init(void *user, const char *input) {
    printf("init, user: %s, input: %s\n", user, input);
}

RCorePlugin r_core_plugin_test = {
    .name = "r2dec",
    .desc = "experimental pseudo-C decompiler for radare2",
    .license = "Apache",
    .call = cmd,
    .init = init};

#ifndef CORELIB
RLibStruct radare_plugin = {.type = R_LIB_TYPE_CORE,
                            .data = &r_core_plugin_test,
                            .version = R2_VERSION};
#endif
