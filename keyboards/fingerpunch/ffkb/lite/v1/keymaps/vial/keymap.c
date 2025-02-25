#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _EXTRA
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |  ESC |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |BckSpc|
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |  TAB |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |  SFT |   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  | SFT  |
 * `-----------------------------------------'             `-----------------------------------------'
 *                          ,--------------------.    ,--------------------.
 *                          |   \  | Enter| LOWER|    | RAISE| Space| Del  |
 *                          `--------------------'    `--------------------.
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_QWERTY] = LAYOUT_ffkb(
  KC_ESC,  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,             KC_BSPC,
  KC_TAB,  LCTL_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LSFT_T(KC_F), KC_G,         KC_H,    RSFT_T(KC_J), RALT_T(KC_K), RGUI_T(KC_L), RCTL_T(KC_SCLN),  KC_QUOT,
  KC_LSFT, KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,          KC_RSFT,
                                     KC_BSLS,        KC_ENT,       LOWER,        RAISE,   KC_SPC,       KC_DEL
),


/* Raise
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Home | Left | Down |  Up  | Right| End  |             |      |   -  |   =  |   [  |   ]  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |      | PgDn | PgUp |      |CpsWrd|             |      |      |      |      |      |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *                          ,--------------------.    ,--------------------.
 *                          |   \  | Enter| LOWER|    | RAISE| Space| Del  |
 *                          `--------------------'    `--------------------.
 */

[_RAISE] = LAYOUT_ffkb(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,     KC_7,       KC_8,    KC_9,    KC_0,    _______,
  KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TAB,       _______,  KC_MINS,    KC_EQL,  KC_LBRC, KC_RBRC, _______,
  _______, _______, KC_PGDN, KC_PGUP, _______, _______,      _______,  _______,    _______, _______, _______, _______,
                             _______, _______, ADJUST,       _______,  _______,    _______
),

/* Lower
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      | TG(1)| TG(2)| TG(3)| TG(4)|      |             |      |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |  Caps|      |      |      |      |             |      |      |      |   |  |   "  |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *                          ,--------------------.    ,--------------------.
 *                          |   \  | Enter| LOWER|    | RAISE| Space| Del  |
 *                          `--------------------'    `--------------------.
 */
[_LOWER] = LAYOUT_ffkb(
  _______, KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,      KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______, TG(_LOWER), TG(_RAISE), TG(_ADJUST), TG(_EXTRA), _______,      _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
  _______, KC_CAPS,    _______,    _______,    _______,     _______,      _______, _______, _______, KC_PIPE,  KC_DQT, _______,
                                   _______,    _______,     _______,      ADJUST,  _______, _______
),

/* Adjust (Lower + Raise)

 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      | RGB_T| RGB_R| RGB_F|      |      |             |   F1 |  F2  |  F3  |  F4  |  F5  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      | SPD_I| HUE_I| SAT_I| VAL_I|      |             |   F6 |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      | SPD_D| HUE_D| SAT_D| VAL_D|      |             |  F11 |  F12 |      |      | Reset|      |
 * `-----------------------------------------'             `-----------------------------------------'
 *                          ,--------------------.    ,--------------------.
 *                          |   \  | Enter| LOWER|    | RAISE| Space| Del  |
 *                          `--------------------'    `--------------------.
 */
[_ADJUST] =  LAYOUT_ffkb(
  _______, _______, _______,  _______, _______, _______,      KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,  _______,
  _______, _______, _______,  _______, _______, _______,      KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10, _______,
  _______, _______, _______,  _______, _______, _______,      KC_F11,  KC_F12,  _______, _______,  QK_BOOT,  _______,
                              _______, _______, _______,      _______, _______, _______
),

/* Extra
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *                          ,--------------------.    ,--------------------.
 *                          |      |      |      |    |      |      |      |
 *                          `--------------------'    `--------------------.
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_EXTRA] = LAYOUT_ffkb(
  _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
                             _______, _______, _______,       _______, _______, _______
)
};
