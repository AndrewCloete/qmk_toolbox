#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SYMB 1
#define _NAV 2
#define _ADJUST 3

enum custom_keycodes { QWERTY = SAFE_RANGE, SYMB, NAV, ADJUST, KC_WIN_TAB, MACRO_PTT };

// Shortcut to make keymap more readable
#define SYM_L MO(_SYMB)
#define SYM_A MO(_ADJUST)

#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_BSLS)

#define KC_NAGR LT(_NAV, KC_GRV)
#define KC_NAESC LT(_NAV, KC_ESC)
#define KC_NAMI LT(_NAV, KC_MINS)

#define KC_ADEN LT(_ADJUST, KC_END)

// Unicode

enum unicode_names { BANG, IRONY, SNEK, WAVE, THUMB_UP, UCE1, UCE2, UCO1, UCO2 };

const uint32_t PROGMEM unicode_map[] = {
    [BANG]     = 0x203D,  // ‽
    [IRONY]    = 0x2E2E,  // ⸮
    [SNEK]     = 0x1F40D, // 🐍
    [WAVE]     = 0x1F44B,
    [THUMB_UP] = 0x1F44D, //
    [UCE1]     = 0x00EB,  // ë
    [UCE2]     = 0x00EA,  // ê
    [UCO1]     = 0x00F6,  // ö
    [UCO2]     = 0x00F4   // ô
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_WIN_TAB:
            if (record->event.pressed) {
                // when keycode KC_WIN_TAB is pressed
                register_code(KC_LWIN);
                register_code(KC_TAB);
            } else {
                // when keycode KC_WIN_TAB is released
                unregister_code(KC_TAB);
                unregister_code(KC_LWIN);
            }
            break;
        case MACRO_PTT:
            // See https://docs.qmk.fm/#/feature_macros?id=send_string-amp-process_record_user
            if (record->event.pressed) {
                SEND_STRING(SS_LWIN("5") SS_LCTL("d"));
            }
            break;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NAGR ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_NAMI ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     LALT_T(KC_TAB),KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    , MACRO_PTT,                   SYM_A  ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,LT(_SYMB, KC_EQL),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NAESC ,KC_A    ,KC_S    ,KC_D    ,KC_F   ,KC_G    ,KC_LBRC ,                          KC_RBRC ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,LT(_NAV, KC_SCLN) ,KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     SYM_L   ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B   ,C(KC_LWIN),SYM_L ,        KC_HOME ,KC_ADEN ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH , LALT_T(KC_BSLS),
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     SYM_A   ,KC_PSCR ,KC_DEL , KC_LALT ,     KC_LCTL ,    KC_LSFT ,KC_LWIN ,        KC_BSPC  ,KC_SPC  ,    KC_ENT ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_EXLM ,XP(UCO1, UCO2),XP(UCE1, UCE2),KC_AMPR,KC_UNDS ,_______ ,               _______ ,KC_CIRC,KC_1    ,KC_2    ,KC_3    ,KC_DLR ,  KC_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     SYM_A   ,KC_AT   ,XXXXXXX, KC_MS_U, XXXXXXX, KC_BTN1,  KC_LPRN ,                         KC_RPRN ,KC_HASH, KC_4    ,KC_5    ,KC_6    ,KC_ASTR ,KC_GRV  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX, KC_MS_L,KC_MS_D ,KC_MS_R ,KC_BTN2 , _______ ,_______ ,        KC_TILD ,_______ ,KC_PERC ,KC_7    ,KC_8    ,KC_9    ,KC_TILD ,KC_EXLM ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,      _______,    _______ ,_______ ,        _______ ,_______ ,    KC_0,         XXXXXXX  ,XXXXXXX ,XXXXXXX  ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_WBAK,KC_WFWD,KC_LPRN,KC_RPRN,XXXXXXX ,_______ ,                          _______ ,KC_HOME ,KC_PGDN ,KC_PGUP ,KC_WFAV ,KC_END  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_LALT, KC_PSCR ,KC_LCBR ,KC_RCBR ,KC_UNDS ,_______ ,                          _______ ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,KC_BTN3 ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     SYM_A   ,XXXXXXX ,KC_DEL  ,KC_LBRC ,KC_RBRC ,XXXXXXX ,_______ ,_______ ,        KC_PGUP ,KC_PGDN ,KC_WH_L ,KC_WH_D ,KC_WH_U ,KC_WH_R ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    XXXXXXX ,     KC_HOME ,KC_PGDN ,KC_PGUP ,KC_END 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,RESET   ,RGB_M_P ,RGB_TOG ,RGB_MOD ,RGB_HUD ,RGB_HUI ,                          RGB_SAD ,KC_VOLD ,KC_F1   ,KC_F2   ,KC_F3   ,KC_VOLU ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,KC_MPRV ,KC_F4   ,KC_F5   ,KC_F6   ,KC_MNXT ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,XXXXXXX ,        XXXXXXX ,_______ ,XXXXXXX ,KC_F7   ,KC_F8   ,KC_F9   ,KC_MPLY ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        KC_F10  ,KC_F11 ,     KC_F12  ,     XXXXXXX, XXXXXXX ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
};
