/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

// LAYERS
#define LAYER(layer_name, layout) \
    / { \
        keymap { \
            compatible = "zmk,keymap"; \
            layer_name { \
                display-name = #layer_name; \
                bindings = <layout>; \
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
            }; \
        }; \
    };

// MOD MORPH
#define MORPH(name, base_binding, modified_binding) \
    / { \
        behaviors { \
            name: name { \
                compatible = "zmk,behavior-mod-morph"; \
                #binding-cells = <0>; \
                bindings = <base_binding>, <modified_binding>; \
                mods = <(MOD_LSFT|MOD_RSFT)>; \
            }; \
        }; \
    };

// HOME ROW MODIFIER
#if !defined QUICK_TAP_TERM
    #define QUICK_TAP_TERM 200
#endif

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
