// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku

// indicators.h is from zmk-feature-splittedspace module (not in upstream miryoku.dtsi)
#include <dt-bindings/zmk/indicators.h>
// &ind behavior node — registers the hallie indicator behavior so the keymap
// can reference it. Without this include, MEDIA layer references to &ind fail
// to resolve at DTS compile time.
#include <behaviors/indicators.dtsi>

// Layer-specific mappings for outer column customization
#define MIRYOKU_LAYERMAPPING_BUTTON MIRYOKU_LAYOUTMAPPING_BUTTON
#define MIRYOKU_LAYERMAPPING_NAV MIRYOKU_LAYOUTMAPPING_NAV
#define MIRYOKU_LAYERMAPPING_MOUSE MIRYOKU_LAYOUTMAPPING_MOUSE
#define MIRYOKU_LAYERMAPPING_MEDIA MIRYOKU_LAYOUTMAPPING_MEDIA
#define MIRYOKU_LAYERMAPPING_NUM MIRYOKU_LAYOUTMAPPING_NUM
#define MIRYOKU_LAYERMAPPING_SYM MIRYOKU_LAYOUTMAPPING_SYM
#define MIRYOKU_LAYERMAPPING_FUN MIRYOKU_LAYOUTMAPPING_FUN

// Restore the Hallie-specific bindings that were in kolibabchuk/miryoku_zmk but
// are absent from upstream manna-harbour/miryoku_zmk. The #if !defined guards in
// miryoku_layer_selection.h skip their own alternatives when these are set.
// Common pattern: K04/K14/K24 (inner-left column) gets additional utility keys.

// NAV: PrtSc / ScrollLock / ContextMenu, and a reordered arrow cluster
// (PG_UP HOME UP END INS on row 0, PG_DN LEFT DOWN RIGHT caps_word on row 1)
#define MIRYOKU_LAYER_NAV \
U_BOOT,            &u_to_U_TAP,       &u_to_U_EXTRA,     &u_to_U_BASE,      &kp PSCRN,         &kp PG_UP,         &kp HOME,          &kp UP,            &kp END,           &kp INS,           \
&kp LGUI,          &kp LALT,          &kp LCTRL,         &kp LSHFT,         &kp SCROLLLOCK,    &kp PG_DN,         &kp LEFT,          &kp DOWN,          &kp RIGHT,         &u_caps_word,      \
U_NA,              &kp RALT,          &u_to_U_NUM,       &u_to_U_NAV,       &kp K_CONTEXT_MENU, U_RDO,            U_PST,             U_CPY,             U_CUT,             U_UND,             \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              &kp RET,           &kp BSPC,          &kp DEL,           U_NP,              U_NP

// MOUSE: PrtSc / ScrollLock / ContextMenu on K04/K14/K24. Right-hand index
// stretch (K05/K15) mirrors NAV's PgUp/PgDn instead of U_NU, since the MOUSE
// layer often needs page-scroll too.
#define MIRYOKU_LAYER_MOUSE \
U_BOOT,            &u_to_U_TAP,       &u_to_U_EXTRA,     &u_to_U_BASE,      &kp PSCRN,         &kp PG_UP,         U_WH_R,            U_MS_U,            U_WH_L,            U_WH_D,            \
&kp LGUI,          &kp LALT,          &kp LCTRL,         &kp LSHFT,         &kp SCROLLLOCK,    &kp PG_DN,         U_MS_L,            U_MS_D,            U_MS_R,            U_WH_U,            \
U_NA,              &kp RALT,          &u_to_U_SYM,       &u_to_U_MOUSE,     &kp K_CONTEXT_MENU, U_RDO,            U_PST,             U_CPY,             U_CUT,             U_UND,             \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              U_BTN2,            U_BTN1,            U_BTN3,            U_NP,              U_NP

// MEDIA: battery query / indicator toggle / system power, rendered by &ind behavior
#define MIRYOKU_LAYER_MEDIA \
U_BOOT,            &u_to_U_TAP,       &u_to_U_EXTRA,     &u_to_U_BASE,      &ind BAT_ST,       U_RGB_TOG,         U_RGB_EFF,         &kp C_VOL_UP,      U_RGB_HUI,         U_RGB_SAI,         \
&kp LGUI,          &kp LALT,          &kp LCTRL,         &kp LSHFT,         &ind IND_ON,       U_EP_TOG,          &kp C_PREV,        &kp C_VOL_DN,      &kp C_NEXT,        U_RGB_BRI,         \
U_NA,              &kp RALT,          &u_to_U_FUN,       &u_to_U_MEDIA,     &kp K_POWER,       &u_out_tog,        &u_bt_sel_0,       &u_bt_sel_1,       &u_bt_sel_2,       &u_bt_sel_3,       \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              &kp C_STOP,        &kp C_PP,          &kp C_MUTE,        U_NP,              U_NP
