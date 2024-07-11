/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOCK1 1
#define _SYMB 2
#define _NAV 3
#define _ADJUST 4

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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //├────────┼────────┼────────┼────────┼────────┼────────┐                                  ┌────────┼────────┼────────┼────────┼────────┼────────┤
     LALT_T(KC_TAB),KC_Q ,KC_W ,KC_E    ,KC_R    ,KC_T                                       ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,LT(_SYMB, KC_EQL),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NAESC ,KC_A  ,KC_S    ,KC_D    ,KC_F   ,KC_G                                       ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,LT(_NAV, KC_SCLN) ,KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┐                                  ┌────────┼────────┼────────┼────────┼────────┼────────┤
     SYM_L   ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B                                       ,KC_N    ,LALT_T(KC_M)    ,KC_COMM ,KC_DOT  ,KC_SLSH , KC_BSLS,
  //├───────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤        ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┤
                                             KC_LCTL ,    KC_LSFT ,KC_LWIN ,        KC_BSPC  ,KC_SPC  ,    KC_ENT
  //                                        └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘
  ),

  [_SYMB] = LAYOUT(

  //├────────┼────────┼────────┼────────┼────────┼────────┐                                  ┌────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX , KC_EXLM ,XP(UCO1, UCO2),XP(UCE1, UCE2),KC_AMPR,KC_UNDS,                         KC_CIRC,KC_1    ,KC_2    ,KC_3    ,KC_DLR ,  KC_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     SYM_A   ,KC_AT   ,XXXXXXX, KC_MS_U, XXXXXXX, KC_BTN1,                                    KC_HASH, KC_4    ,KC_5    ,KC_6    ,KC_ASTR ,KC_GRV  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┐                                  ┌────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX, KC_MS_L,KC_MS_D ,KC_MS_R ,KC_BTN2  ,                                   KC_PERC ,KC_7    ,KC_8    ,KC_9    ,KC_TILD ,KC_EXLM ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┤
                                              _______,    _______ ,_______ ,         _______ ,_______ ,    KC_0
  //                                         └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘
  ),

  [_NAV] = LAYOUT(
  //├────────┼────────┼────────┼────────┼────────┼────────┐                                  ┌────────┼────────┼────────┼────────┼────────┼────────┤
  DF(_LOCK1), KC_WBAK, KC_WFWD,KC_LPRN,  KC_RPRN, XXXXXXX ,                                   KC_HOME ,KC_PGDN ,KC_PGUP ,KC_WFAV ,KC_END  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_LALT, KC_PSCR ,KC_LCBR ,KC_RCBR ,KC_UNDS ,                                   KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,KC_BTN3 ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┐                                  ┌────────┼────────┼────────┼────────┼────────┼────────┤
     SYM_A   ,XXXXXXX ,KC_DEL  ,KC_LBRC ,KC_RBRC ,XXXXXXX ,                                   KC_WH_L ,KC_WH_D ,KC_WH_U ,KC_WH_R ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┤
                                              _______ ,    _______ ,_______ ,        _______ ,_______ ,    XXXXXXX
  //                                         └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘
  ),

  [_ADJUST] = LAYOUT(
  //├────────┼────────┼────────┼────────┼────────┼────────┐                                  ┌────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX, RGB_M_P, RGB_TOG, RGB_MOD, RGB_HUD,                                    KC_VOLD ,KC_F1   ,KC_F2   ,KC_F3   ,KC_VOLU ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,                                    KC_MPRV ,KC_F4   ,KC_F5   ,KC_F6   ,KC_MNXT ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┐                                  ┌────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,                                    XXXXXXX ,KC_F7   ,KC_F8   ,KC_F9   ,KC_MPLY ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┤
                                              XXXXXXX ,    XXXXXXX ,XXXXXXX ,        KC_F10  ,KC_F11 ,     KC_F12
  //                                         └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘
  ),

  [_LOCK1] = LAYOUT(

  //├────────┼────────┼────────┼────────┼────────┼────────┐                                  ┌────────┼────────┼────────┼────────┼────────┼────────┤
 DF(_QWERTY) ,KC_EXLM, KC_1,    KC_2 ,   KC_3,    KC_UNDS,                                    KC_CIRC,KC_1    ,KC_2    ,KC_3    ,KC_DLR ,  KC_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                  ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NAESC, KC_AT,  KC_4,    KC_5,    KC_6,    KC_BTN1,                                    KC_HASH, KC_4    ,KC_5    ,KC_6    ,KC_ASTR ,KC_GRV  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┐                                  ┌────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX,  KC_7,    KC_8 ,   KC_9 ,   KC_BTN2,                                    KC_PERC ,KC_7    ,KC_8    ,KC_9    ,KC_TILD ,KC_EXLM ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┤
                                              KC_0,        _______ ,_______ ,        _______ ,_______ ,    KC_0
  //                                         └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘
  )
};
