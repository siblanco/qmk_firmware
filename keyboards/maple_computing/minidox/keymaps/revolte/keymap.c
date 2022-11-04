#include QMK_KEYBOARD_H

enum custom_keycodes {
  SHORT_ARROW = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SHORT_ARROW:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("=>");
        } else {
            // when keycode QMKBEST is released
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_split_3x5_3(
  KC_Q,    KC_W,    KC_F,    KC_P,         KC_B,         KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
  KC_A,    KC_R,    LT(3, KC_S),    LALT_T(KC_T), LT(4, KC_G),         KC_M,    LALT_T(KC_N),    KC_E,    KC_I,    KC_O,
  KC_Z,    KC_X,    KC_C,    KC_D,         KC_V,         KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
              KC_ESC, LT(1, KC_SPC), LT(2, KC_TAB),         LCTL_T(KC_ENT), LSFT_T(KC_BSPC), KC_DEL
),
[1] = LAYOUT_split_3x5_3(
  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                KC_LBRC,    KC_7,    KC_8,    KC_9,    KC_RBRC,
  XXXXXXX,    XXXXXXX,    XXXXXXX,    SHORT_ARROW,    XXXXXXX,                KC_SCLN,    KC_4,    KC_5,    KC_6,    KC_EQL,
  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                KC_GRV,     KC_1,    KC_2,    KC_3,    KC_BSLS,
                                 _______, _______, _______,         KC_DOT, KC_0, KC_MINS
),
[2] = LAYOUT_split_3x5_3(
  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                KC_LCBR,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RCBR,
  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                KC_COLN,    KC_DLR,    KC_PERC,    KC_CIRC,    KC_PLUS,
  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                KC_TILD,     KC_EXLM,    KC_AT,    KC_HASH,    KC_PIPE,
                                 _______, _______, _______,         KC_LPRN, KC_RPRN, KC_UNDS
),
[3] = LAYOUT_split_3x5_3(
  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                KC_MPRV,    KC_VOLD,    KC_VOLU,    KC_MNXT,    KC_CAPS,
  XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_APP,    XXXXXXX,                 KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    XXXXXXX,
  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                XXXXXXX,    KC_PGDN,    KC_PGUP,    KC_END,     XXXXXXX,
                                 _______, _______, _______,         _______, _______, _______
),
[4] = LAYOUT_split_3x5_3(
  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                KC_MS_L,    KC_MS_D,    KC_MS_U,    KC_MS_R,    KC_APP,
  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                KC_WH_L,    KC_WH_D,    KC_WH_U,    KC_WH_R,    XXXXXXX,
                                 _______, _______, _______,         KC_BTN2, KC_BTN1, KC_BTN3
)
};

enum combo_events {
  EMAIL_WORK,
  EMAIL_PRIVATE,
  COMBO_LENGTH
};


uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!

const uint16_t PROGMEM email_work_combo[] = {KC_E, KC_W, COMBO_END};
const uint16_t PROGMEM email_private_combo[] = {KC_E, KC_P, COMBO_END};

combo_t key_combos[] = {
  [EMAIL_WORK] = COMBO_ACTION(email_work_combo),
  [EMAIL_PRIVATE] = COMBO_ACTION(email_private_combo),
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case EMAIL_WORK:
      if (pressed) {
        SEND_STRING("hs@roberts.de");
      }
      break;
    case EMAIL_PRIVATE:
      if (pressed) {
        SEND_STRING("hallo@siblanco.dev");
      }
      break;
  }
}
