#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
#include "i18n.h"

enum planck_keycodes {
  RGB_SLD = SAFE_RANGE,
};


enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
};

// Aliases
#define EE_CARN KC_GRV  // ˇ (dead)
#define EE_1    KC_1    // 1
#define EE_2    KC_2    // 2
#define EE_3    KC_3    // 3
#define EE_4    KC_4    // 4
#define EE_5    KC_5    // 5
#define EE_6    KC_6    // 6
#define EE_7    KC_7    // 7
#define EE_8    KC_8    // 8
#define EE_9    KC_9    // 9
#define EE_0    KC_0    // 0
#define EE_PLUS KC_MINS // +
#define EE_ACUT KC_EQL  // ´ (dead)
#define EE_Q    KC_Q    // Q
#define EE_W    KC_W    // W
#define EE_E    KC_E    // E
#define EE_R    KC_R    // R
#define EE_T    KC_T    // T
#define EE_Y    KC_Y    // Y
#define EE_U    KC_U    // U
#define EE_I    KC_I    // I
#define EE_O    KC_O    // O
#define EE_P    KC_P    // P
#define EE_UDIA KC_LBRC // Ü
#define EE_OTIL KC_RBRC // Õ
#define EE_A    KC_A    // A
#define EE_S    KC_S    // S
#define EE_D    KC_D    // D
#define EE_F    KC_F    // F
#define EE_G    KC_G    // G
#define EE_H    KC_H    // H
#define EE_J    KC_J    // J
#define EE_K    KC_K    // K
#define EE_L    KC_L    // L
#define EE_ODIA KC_SCLN // Ö
#define EE_ADIA KC_QUOT // Ä
#define EE_QUOT KC_NUHS // '
#define EE_LABK KC_NUBS // <
#define EE_Z    KC_Z    // Z
#define EE_X    KC_X    // X
#define EE_C    KC_C    // C
#define EE_V    KC_V    // V
#define EE_B    KC_B    // B
#define EE_N    KC_N    // N
#define EE_M    KC_M    // M
#define EE_COMM KC_COMM // ,
#define EE_DOT  KC_DOT  // .
#define EE_MINS KC_SLSH // -
#define EE_TILD S(EE_CARN) // ~ (dead)
#define EE_EXLM S(EE_1)    // !
#define EE_DQUO S(EE_2)    // "
#define EE_HASH S(EE_3)    // #
#define EE_CURR S(EE_4)    // ¤
#define EE_PERC S(EE_5)    // %
#define EE_AMPR S(EE_6)    // &
#define EE_SLSH S(EE_7)    // /
#define EE_LPRN S(EE_8)    // (
#define EE_RPRN S(EE_9)    // )
#define EE_EQL  S(EE_0)    // =
#define EE_QUES S(EE_PLUS) // ?
#define EE_GRV  S(EE_ACUT) // ` (dead)
#define EE_ASTR S(EE_QUOT) // *
#define EE_RABK S(EE_LABK) // >
#define EE_SCLN S(EE_COMM) // ;
#define EE_COLN S(EE_DOT)  // :
#define EE_UNDS S(EE_MINS) // _
#define EE_AT   ALGR(EE_2)    // @
#define EE_PND  ALGR(EE_3)    // £
#define EE_DLR  ALGR(EE_4)    // $
#define EE_EURO ALGR(EE_5)    // €
#define EE_LCBR ALGR(EE_7)    // {
#define EE_LBRC ALGR(EE_8)    // [
#define EE_RBRC ALGR(EE_9)    // ]
#define EE_RCBR ALGR(EE_0)    // }
#define EE_BSLS ALGR(EE_PLUS) // (backslash)
#define EE_SECT ALGR(EE_OTIL) // §
#define EE_SCAR ALGR(EE_S)    // š
#define EE_CIRC ALGR(EE_ADIA) // ^ (dead)
#define EE_HALF ALGR(EE_QUOT) // ½
#define EE_PIPE ALGR(EE_LABK) // |
#define EE_ZCAR ALGR(EE_Z)    // ž

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
    KC_ESCAPE,      EE_Q,           EE_W,           EE_E,           EE_R,           EE_T,           EE_Y,           EE_U,           EE_I,           EE_O,           EE_P,           KC_BSPC,        
    KC_TAB,         EE_A,           EE_S,           EE_D,           EE_F,           EE_G,           EE_H,           EE_J,           EE_K,           EE_L,           EE_SCLN,        EE_QUOT,       
    KC_LEFT_SHIFT,  EE_Z,           EE_X,           EE_C,           EE_V,           EE_B,           EE_N,           EE_M,           EE_COMM,        EE_DOT,         EE_SLSH,        KC_ENTER,       
    KC_LEFT_CTRL,   CW_TOGG,        KC_LEFT_ALT,    KC_LEFT_GUI,    LOWER,          KC_TRANSPARENT, KC_SPC,         RAISE,          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT
  ),

  [_LOWER] = LAYOUT_planck_grid(
    KC_TRANSPARENT, EE_EXLM,        EE_AT,          EE_HASH,        EE_DLR,         EE_PERC,        EE_CIRC,        EE_AMPR,        EE_ASTR,        EE_LPRN,        EE_RPRN,        KC_TRANSPARENT, 
    KC_DELETE,      EE_ADIA,        EE_ODIA,        EE_OTIL,        EE_UDIA,        KC_NO,          KC_NO,          EE_UNDS,        EE_PLUS,        EE_LCBR,        EE_RCBR,        EE_PIPE,        
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          EE_TILD,        EE_LBRC,        EE_RBRC,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_NEXT_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_PLAY_PAUSE
  ),

  [_RAISE] = LAYOUT_planck_grid(
    KC_TRANSPARENT, EE_1,           EE_2,           EE_3,           EE_4,           EE_5,           EE_6,           EE_7,           EE_8,           EE_9,           EE_0,           KC_TRANSPARENT, 
    KC_DELETE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          EE_MINS,        EE_EQL,         EE_LABK,        EE_RABK,        EE_BSLS,        
    KC_TRANSPARENT, KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_HOME,        KC_END,         KC_PAGE_UP,     KC_PGDN,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_NEXT_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_PLAY_PAUSE
  ),

  [_ADJUST] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_DELETE,      KC_TRANSPARENT, QK_AUDIO_ON,    QK_AUDIO_OFF,   AU_TOGG,        KC_TRANSPARENT, KC_TRANSPARENT, RGB_TOG,         RGB_VAI,        RGB_VAD,        KC_TRANSPARENT, QK_BOOT,        
    KC_TRANSPARENT, KC_TRANSPARENT, QK_MUSIC_ON,    QK_MUSIC_OFF,   MU_TOGG,        KC_TRANSPARENT, KC_TRANSPARENT, RGB_MODE_FORWARD,RGB_HUI,        RGB_HUD,        KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

};




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case RGB_SLD:
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
  }
  return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint8_t layer_state_set_user(uint8_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}



