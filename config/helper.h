/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIF
 */

#pragma once

// GLOBAL
#define LEFT_KEYS 1 2 3 4 5 13 14 15 16 17 25 26 27 28 29 36 37 38 39 40
#define RIGHT_KEYS 6 7 8 9 10 18 19 20 21 22 30 31 32 33 34 36 37 38 39 40

#define ALPHA 0
#define NAV 1
#define NUM 2
#define FUNC 3

#if !defined QUICK_TAP_TERM
    #define QUICK_TAP_TERM 200
#endif

#if !defined PRIOR_IDLE
    #define PRIOR_IDLE 200
#endif

// LAYERS
#define LAYER(layer_name, layout) \
    / { \
        keymap { \
            compatible = "zmk,keymap"; \
            name { \
                display-name = #layer_name; \
                bindings = layout; \
            }; \
        }; \
    };

// COMBOS
#if !defined COMBO_TIMEOUT
    #define COMBO_TIMEOUT 30
#endif

#define COMBO(name, combo_binding, keypos, active_layers) \
    / { \
        combos { \
            compatible = "zmk,combos"; \
            combo_ ## name { \
                timeout-ms = <COMBO_TIMEOUT>; \
                bindings = <combo_binding>; \
                key-positions = <keypos>; \
                layers = <active_layers>; \
                require-prior-idle-ms = <PRIOR_IDLE>; \
            }; \
        }; \
    };

// MOD MORPH
#define MORPH(name, base_binding, mod_binding) \
    / { \
        behaviors { \
            name: name { \
                compatible = "zmk,behavior-mod-morph"; \
                #binding-cells = <0>; \
                bindings = <base_binding>, <mod_binding>; \
                mods = <(MOD_LSFT|MOD_RSFT)>; \
            }; \
        }; \
    };

// HOMEROW MODS
#define HRM(name, hold_trigger_keys, required_idle) \
    / { \
        behaviors { \
            name: name { \
                compatible = "zmk,behavior-hold-tap"; \
                #binding-cells = <2>; \
                flavor = "balanced"; \
                tapping-term-ms = <500>; \
                quick-tap-ms = <QUICK_TAP_TERM>; \
                bindings = <&kp>, <&kp>; \
                require-prior-idle-ms = <required_idle>; \
                hold-trigger-key-positions = <hold_trigger_keys>; \
                hold-trigger-on-release; \
            }; \
        }; \
    };


// TAP-DANCE
#define TD(name, tap, dance) \
    / { \
        behaviors { \
            name: name { \
                compatible = "zmk,behavior-tap-dance"; \
                #binding-cells = <0>; \
                tapping-term-ms = <200>; \
                bindings = <tap>, <dance>; \
            }; \
        }; \
    };

