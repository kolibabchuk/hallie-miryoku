// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku
// generated -*- buffer-read-only: t -*-

#pragma once

#if !defined (MIRYOKU_LAYER_LIST)

#define MIRYOKU_LAYER_LIST \
MIRYOKU_X(BASE,   "Base",   sensor-bindings = < &inc_dec_kp LEFT RIGHT &inc_dec_kp UP DOWN> ;) \
MIRYOKU_X(EXTRA,  "Extra",  sensor-bindings = < &inc_dec_kp LEFT RIGHT &inc_dec_kp UP DOWN> ;) \
MIRYOKU_X(TAP,    "Tap",    sensor-bindings = < &inc_dec_kp LEFT RIGHT &inc_dec_kp UP DOWN> ;) \
MIRYOKU_X(BUTTON, "Button", sensor-bindings = < &inc_dec_kp LEFT RIGHT &inc_dec_kp UP DOWN> ;) \
MIRYOKU_X(NAV,    "Nav",    sensor-bindings = < &inc_dec_kp UP DOWN &inc_dec_kp LEFT RIGHT> ;) \
MIRYOKU_X(MOUSE,  "Mouse",  sensor-bindings = < &inc_dec_kp LEFT RIGHT &inc_dec_kp UP DOWN> ;) \
MIRYOKU_X(MEDIA,  "Media",  sensor-bindings = <&inc_dec_kp C_BRI_DEC C_BRI_INC &inc_dec_kp C_VOL_UP C_VOL_DN> ;) \
MIRYOKU_X(NUM,    "Num",    sensor-bindings = < &inc_dec_kp LEFT RIGHT &inc_dec_kp UP DOWN> ;) \
MIRYOKU_X(SYM,    "Sym",    sensor-bindings = < &inc_dec_kp LEFT RIGHT &inc_dec_kp UP DOWN> ;) \
MIRYOKU_X(FUN,    "Fun",    sensor-bindings = < &inc_dec_kp LEFT RIGHT &inc_dec_kp UP DOWN> ;)

#define U_BASE   0
#define U_EXTRA  1
#define U_TAP    2
#define U_BUTTON 3
#define U_NAV    4
#define U_MOUSE  5
#define U_MEDIA  6
#define U_NUM    7
#define U_SYM    8
#define U_FUN    9

#endif
