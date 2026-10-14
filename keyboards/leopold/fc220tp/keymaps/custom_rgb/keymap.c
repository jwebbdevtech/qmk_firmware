#include QMK_KEYBOARD_H

/* Step A: Initialize your exact 6-Layer VIA mapping matrix rules */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_TAB,  TO(5),    MO(3), 
        KC_NLCK, KC_EQL,  KC_PSLS,  KC_PAST, 
        KC_P7,   KC_P8,   KC_P9,    KC_PMNS, 
        KC_P4,   KC_P5,   KC_P6,    KC_PPLS, 
        KC_P1,   KC_P2,   KC_P3,    KC_PENT, 
        KC_NO,   KC_P0,   KC_PDOT,  KC_NO
    ),
    [1] = LAYOUT(
        KC_ESC,  KC_TAB,  KC_BSPC,  MO(3), 
        KC_NLCK, KC_EQL,  KC_PSLS,  KC_PAST, 
        KC_7,    KC_8,    KC_9,     KC_PMNS, 
        KC_4,    KC_5,    KC_6,     KC_PPLS, 
        KC_1,    KC_2,    KC_3,     KC_PENT, 
        KC_NO,   KC_0,    KC_DOT,   KC_NO
    ),
    [2] = LAYOUT(
        KC_ESC,  KC_TAB,  KC_BSPC,  MO(3), 
        KC_NLCK, KC_EQL,  KC_PSLS,  KC_PAST, 
        KC_HOME, KC_UP,   KC_PGUP,  KC_PMNS, 
        KC_LEFT, KC_NO,   KC_RGHT,  KC_PPLS, 
        KC_END,  KC_DOWN, KC_PGDN,  KC_PENT, 
        KC_NO,   KC_INS,  KC_DEL,   KC_NO
    ),
    [3] = LAYOUT(
        MAGIC_TOGGLE_NKRO, CUSTOM(5),  CUSTOM(9),   KC_TRNS, 
        CUSTOM(13),        CUSTOM(12), CUSTOM(11),  CUSTOM(10), 
        CUSTOM(15),        CUSTOM(17), CUSTOM(14),  CUSTOM(16), 
        CUSTOM(3),         CUSTOM(4),  CUSTOM(18),  KC_TRNS, 
        CUSTOM(0),         CUSTOM(1),  CUSTOM(2),   KC_TRNS, 
        KC_NO,             TO(5),      KC_TRNS,     KC_NO
    ),
    [4] = LAYOUT(
        KC_ESC,  KC_TAB,  KC_BSPC,  MO(5), 
        KC_NLCK, KC_PEQL, KC_PSLS,  KC_PAST, 
        KC_P7,   KC_P8,   KC_P9,    KC_PMNS, 
        KC_P4,   KC_P5,   KC_P6,    KC_PPLS, 
        KC_P1,   KC_P2,   KC_P3,    KC_PENT, 
        KC_NO,   KC_P0,   KC_PDOT,  KC_NO
    ),
    [5] = LAYOUT(
        MAGIC_TOGGLE_NKRO, CUSTOM(5),  KC_F18,      KC_TRNS, 
        KC_F10,            KC_F11,     KC_F12,      CUSTOM(10), 
        KC_F7,             KC_F8,      KC_F9,       CUSTOM(16), 
        KC_F4,             KC_F5,      KC_F6,       KC_TRNS, 
        KC_F1,             KC_F2,      KC_F3,       KC_TRNS, 
        KC_NO,             TO(1),      KC_TRNS,     KC_NO
    )
};

/* Step B: Embed your dynamic Cyan and Purple RGB lighting rules */
#define RGB_CYAN   0, 254, 234
#define RGB_PURPLE 131, 4, 242

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case 5:
            #if defined(RGB_MATRIX_ENABLE)
                rgb_matrix_set_color_all(RGB_PURPLE);
            #elif defined(RGBLIGHT_ENABLE)
                rgblight_setrgb(RGB_PURPLE);
            #endif
            break;
        case 0:
        default:
            #if defined(RGB_MATRIX_ENABLE)
                rgb_matrix_set_color_all(RGB_CYAN);
            #elif defined(RGBLIGHT_ENABLE)
                rgblight_setrgb(RGB_CYAN);
            #endif
            break;
    }
    return state;
}

void keyboard_post_init_user(void) {
    #if defined(RGB_MATRIX_ENABLE)
        rgb_matrix_set_color_all(RGB_CYAN);
    #elif defined(RGBLIGHT_ENABLE)
        rgblight_setrgb(RGB_CYAN);
    #endif
}
