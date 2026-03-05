// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

#if !defined (MIRYOKU_LAYOUTMAPPING_HALLIE)

#define XXX &none
#define HYPR LG(LA(LS(LCTRL)))

// Default mapping for BASE, EXTRA, and TAP layers
#define MIRYOKU_LAYOUTMAPPING_HALLIE( \
     K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,      K35, K36, K37, N38, N39 \
) \
&td_bslh_globe_base        K00  K01  K02  K03  K04    K05  K06  K07  K08  K09  U_MT(GLOBE, LBKT) \
U_MT(HYPR, RBKT)           K10  K11  K12  K13  K14    K15  K16  K17  K18  K19  U_MT(HYPR, SQT) \
&mt_input_switch LSHFT 0   K20  K21  K22  K23  K24    K25  K26  K27  K28  K29  U_MT(RSHFT, FSLH) \
                                K32  K33  K34    K35  K36  K37

// BUTTON layer mapping with custom outer column keys
#define MIRYOKU_LAYOUTMAPPING_BUTTON( \
     K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,      K35, K36, K37, N38, N39 \
) \
U_BOOT K00  K01  K02  K03  K04    K05  K06  K07  K08  K09  U_BOOT \
U_BOOT K10  K11  K12  K13  K14    K15  K16  K17  K18  K19  U_BOOT \
U_BOOT K20  K21  K22  K23  K24    K25  K26  K27  K28  K29  U_BOOT \
                 K32  K33  K34    K35  K36  K37

// NAV layer mapping with custom outer column keys
#define MIRYOKU_LAYOUTMAPPING_NAV( \
     K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,      K35, K36, K37, N38, N39 \
) \
&kp C_AC_DESKTOP_SHOW_ALL_APPLICATIONS  K00  K01  K02  K03  K04    K05  K06  K07  K08  K09  &kp ESC  \
&kp C_AC_DESKTOP_SHOW_ALL_WINDOWS       K10  K11  K12  K13  K14    K15  K16  K17  K18  K19  &kp HYPR \
&kp C_AC_SEARCH                         K20  K21  K22  K23  K24    K25  K26  K27  K28  K29  &kp GLOBE \
                                                  K32  K33  K34    K35  K36  K37

// MOUSE layer mapping with custom outer column keys
#define MIRYOKU_LAYOUTMAPPING_MOUSE( \
     K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,      K35, K36, K37, N38, N39 \
) \
&kp C_AC_DESKTOP_SHOW_ALL_APPLICATIONS  K00  K01  K02  K03  K04    K05  K06  K07  K08  K09  &kp ESC \
&kp C_AC_DESKTOP_SHOW_ALL_WINDOWS       K10  K11  K12  K13  K14    K15  K16  K17  K18  K19  &kp HYPR \
&kp C_AC_SEARCH                         K20  K21  K22  K23  K24    K25  K26  K27  K28  K29  &kp GLOBE \
                                                  K32  K33  K34    K35  K36  K37

// MEDIA layer mapping with custom outer column keys
#define MIRYOKU_LAYOUTMAPPING_MEDIA( \
     K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,      K35, K36, K37, N38, N39 \
) \
&kp C_AC_DESKTOP_SHOW_ALL_APPLICATIONS  K00  K01  K02  K03  K04    K05  K06  K07  K08  K09  &kp ESC \
&kp C_AC_DESKTOP_SHOW_ALL_WINDOWS       K10  K11  K12  K13  K14    K15  K16  K17  K18  K19  &kp HYPR \
&kp C_AC_SEARCH                         K20  K21  K22  K23  K24    K25  K26  K27  K28  K29  &kp GLOBE \
                                                  K32  K33  K34    K35  K36  K37

// NUM layer mapping with custom outer column keys
#define MIRYOKU_LAYOUTMAPPING_NUM( \
     K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,      K35, K36, K37, N38, N39 \
) \
&kp C_AC_DESKTOP_SHOW_ALL_APPLICATIONS  K00  K01  K02  K03  K04    K05  K06  K07  K08  K09  &kp ESC \
&kp C_AC_DESKTOP_SHOW_ALL_WINDOWS       K10  K11  K12  K13  K14    K15  K16  K17  K18  K19  &kp HYPR \
&kp C_AC_SEARCH                         K20  K21  K22  K23  K24    K25  K26  K27  K28  K29  &kp GLOBE \
                                                  K32  K33  K34    K35  K36  K37

// SYM layer mapping with custom outer column keys and unicode tilde/backtick
#define MIRYOKU_LAYOUTMAPPING_SYM( \
     K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,      K35, K36, K37, N38, N39 \
) \
&kp C_AC_DESKTOP_SHOW_ALL_APPLICATIONS  K00  K01  K02  K03  K04    K05  K06  K07  K08  K09  &kp ESC \
&kp C_AC_DESKTOP_SHOW_ALL_WINDOWS       K10  K11  K12  K13  K14    K15  K16  K17  K18  K19  &kp HYPR \
&kp C_AC_SEARCH                         K20  K21  K22  K23  K24    K25  K26  K27  K28  K29  &kp GLOBE \
                                                  K32  K33  K34    K35  K36  K37

// FUN layer mapping with numbers 1-6 on outer columns
#define MIRYOKU_LAYOUTMAPPING_FUN( \
     K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, \
     N30, N31, K32, K33, K34,      K35, K36, K37, N38, N39 \
) \
&kp C_AC_DESKTOP_SHOW_ALL_APPLICATIONS  K00  K01  K02  K03  K04    K05  K06  K07  K08  K09  &kp ESC \
&kp C_AC_DESKTOP_SHOW_ALL_WINDOWS       K10  K11  K12  K13  K14    K15  K16  K17  K18  K19  &kp HYPR \
&kp C_AC_SEARCH                         K20  K21  K22  K23  K24    K25  K26  K27  K28  K29  &kp GLOBE \
                                                  K32  K33  K34    K35  K36  K37

#endif

#define MIRYOKU_MAPPING MIRYOKU_LAYOUTMAPPING_HALLIE
