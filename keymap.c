#include QMK_KEYBOARD_H
#include "eeprom.h"
#include "i18n.h"
#include "keymap-estonian.h"

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
};

uint8_t layer_state_set_user(uint8_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    +-----------------------------------------------------------------------------------------------+
    | BASE LAYER                                                                                    |
    +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    |       |       |       |       |       |       |       |       |       |       |       |       |
    |  ESC  |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |   <-  |
    |       |       |       |       |       |       |       |       |       |       |       |       |
    +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    |       |       |       |       |       |       |       |       |       |       |       |       |
    |  TAB  |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   l   |   ;   |   '   |
    |       |       |       |       |       |       |       |       |       |       |       |       |
    +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    |       |       |       |       |       |       |       |       |       |       |       |       |
    | SHIFT |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   |  <─┘  |
    |       |       |       |       |       |       |       |       |       |       |       |       |
    +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    |       |       |       |       |       |               |       |       |       |       |       |
    |  CTRL | CAPS  |  ALT  | SUPER | LOWER |     SPACE     | RAISE | LEFT  | DOWN  |   UP  | RIGHT |
    |       | LOCK  |       |       |       |               |       |       |       |       |       |
    +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    */
    [_BASE] = LAYOUT_planck_grid(
      KC_ESCAPE     , EE_Q      , EE_W          , EE_E          , EE_R  , EE_T      , EE_Y      , EE_U  , EE_I      , EE_O      , EE_P      , KC_BSPC   ,        
      KC_TAB        , EE_A      , EE_S          , EE_D          , EE_F  , EE_G      , EE_H      , EE_J  , EE_K      , EE_L      , EE_SCLN   , EE_QUOT   ,       
      KC_LEFT_SHIFT , EE_Z      , EE_X          , EE_C          , EE_V  , EE_B      , EE_N      , EE_M  , EE_COMM   , EE_DOT    , EE_SLSH   , KC_ENTER  ,       
      KC_LEFT_CTRL  , KC_CAPS   , KC_LEFT_ALT   , KC_LEFT_GUI   , LOWER , _______   , KC_SPC    , RAISE , KC_LEFT   , KC_DOWN   , KC_UP     , KC_RIGHT  
    ),

    /*
    +-----------------------------------------------------------------------------------------------+
    | LOWER LAYER                                                                                   |
    +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    |       |       |       |       |       |       |       |       |       |       |       |       |
    |  ESC* |   !   |   @   |   #   |   $   |   %   |   ^   |   &   |   *   |   (   |   )   |   <-* |
    |       |       |       |       |       |       |       |       |       |       |       |       |
    +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    |       |       |       |       |       |       |       |       |       |       |       |       |
    |  DEL  |   Ä   |   Ö   |   Õ   |   Ü   |   Š   |   Ž   |   _   |   +   |   {   |   }   |   |   |
    |       |       |       |       |       |       |       |       |       |       |       |       |
    +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    |       |       |       |       |       |       |       |       |       |       |       |       |
    | SHIFT*|   €   |   £   |       |       |       |   ~   |   `   |   ´   |   [   |   ]   |  <─┘* |
    |       |       |       |       |       |       |       |       |       |       |       |       |
    +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    |       |       |       |       |       |               |       |       |       |       |       |
    | CTRL* | CAPS  |  ALT* | SUPER*| LOWER*|     SPACE*    | RASIE*| PREV  |  VOL- |  VOL+ | NEXT  |
    |       | LOCK* |       |       |       |               |       | TRACK |       |       | TRACK |
    +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    */
    [_LOWER] = LAYOUT_planck_grid(
      _______   , EE_EXLM   , EE_AT     , EE_HASH   , EE_DLR    , EE_PERC   , EE_CIRC   , EE_AMPR   , EE_ASTR               , EE_LPRN           , EE_RPRN           , _______               , 
      KC_DELETE , EE_ADIA   , EE_ODIA   , EE_OTIL   , EE_UDIA   , EE_SCAR   , EE_ZCAR   , EE_UNDS   , EE_PLUS               , EE_LCBR           , EE_RCBR           , EE_PIPE               ,        
      _______   , EE_EURO   , EE_PND    , XXXXXXX   , XXXXXXX   , XXXXXXX   , EE_TILD   , EE_GRV    , EE_ACUT               , EE_LBRC           , EE_RBRC           , _______               , 
      _______   , _______   , _______   , _______   , _______   , _______   , _______   , _______   , KC_MEDIA_PREV_TRACK   , KC_AUDIO_VOL_DOWN , KC_AUDIO_VOL_UP   , KC_MEDIA_NEXT_TRACK   
    ),

    /*
    +-----------------------------------------------------------------------------------------------+
    | RAISE LAYER                                                                                   |
    +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    |       |       |       |       |       |       |       |       |       |       |       |       |
    |  ESC* |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |   <-* |
    |       |       |       |       |       |       |       |       |       |       |       |       |
    +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    |       |       |       |       |       |       |       |       |       |       |       |       |
    |  DEL  |  F1   |   F2  |   F3  |   F4  |   F5  |   F6  |   -   |   =   |   <   |   >   |   \   |
    |       |       |       |       |       |       |       |       |       |       |       |       |
    +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    |       |       |       |       |       |       |       |       |       |       |       |       |
    | SHIFT*|   F7  |   F8  |   F9  |  F10  |  F11  |  F12  |  HOME |  END  | PAGE  | PAGE  |  <─┘* |
    |       |       |       |       |       |       |       |       |       | UP    | DOWN  |       |
    +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    |       |       |       |       |       |               |       |       |       |       |       |
    | CTRL* | CAPS  |  ALT* | SUPER*| LOWER*|     SPACE*    | RAISE*|  MUTE |  VOL- |  VOL+ | PLAY- |
    |       | LOCK* |       |       |       |               |       |       |       |       | PAUSE |
    +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    */
    [_RAISE] = LAYOUT_planck_grid(
      _______   , EE_1      , EE_2      , EE_3      , EE_4      , EE_5      , EE_6      , EE_7      , EE_8          , EE_9              , EE_0              , _______               , 
      KC_DELETE , KC_F1     , KC_F2     , KC_F3     , KC_F4     , KC_F5     , KC_F6     , EE_MINS   , EE_EQL        , EE_LABK           , EE_RABK           , EE_BSLS               ,        
      _______   , KC_F7     , KC_F8     , KC_F9     , KC_F10    , KC_F11    , KC_F12    , KC_HOME   , KC_END        , KC_PAGE_UP        , KC_PGDN           , _______               , 
      _______   , _______   , _______   , _______   , _______   , _______   , _______   , _______   , KC_AUDIO_MUTE , KC_AUDIO_VOL_DOWN , KC_AUDIO_VOL_UP   , KC_MEDIA_PLAY_PAUSE   
    ),

    /*
    +---------------+-------------------------------------------------------------------------------+
    | ADJUST LAYER  | LOWER + RAISE                                                                 |
    +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    |       |       |       |       |       |       |       |       |       |       |       |       |
    |       |       |       |       |       |       |       |       |       |       |       |       |
    |       |       |       |       |       |       |       |       |       |       |       |       |
    +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    |       |       |       |       |       |       |       |       |       |       |       |       |
    |       |       | AUDIO | AUDIO | AUDIO |       |       | RGB   | RGB   |  RGB  |       | BOOT  |
    |       |       | ON    | OFF   | TOGGLE|       |       | TOGGLE| VAI   |  VAD  |       |       |
    +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    |       |       |       |       |       |       |       | RGB   |       |       |       |       |
    |       |       | MUSIC | MUSIC | MUSIC |       |       | MODE  | RGB   |  RGB  |       |       |
    |       |       | ON    | OFF   | TOGGLE|       |       |FORWARD| HUI   |  HUD  |       |       |
    +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    |       |       |       |       |       |               |       |       |       |       |       |
    |       |       |       |       |       |               |       |       |       |       |       |
    |       |       |       |       |       |               |       |       |       |       |       |
    +-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+
    */
    [_ADJUST] = LAYOUT_planck_grid(
      XXXXXXX   , XXXXXXX   , XXXXXXX       , XXXXXXX       , XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX           , XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   ,
      XXXXXXX   , XXXXXXX   , QK_AUDIO_ON   , QK_AUDIO_OFF  , AU_TOGG   , XXXXXXX   , XXXXXXX   , RGB_TOG           , RGB_VAI   , RGB_VAD   , XXXXXXX   , QK_BOOT   ,        
      XXXXXXX   , XXXXXXX   , QK_MUSIC_ON   , QK_MUSIC_OFF  , MU_TOGG   , XXXXXXX   , XXXXXXX   , RGB_MODE_FORWARD  , RGB_HUI   , RGB_HUD   , XXXXXXX   , XXXXXXX   , 
      XXXXXXX   , XXXXXXX   , XXXXXXX       , XXXXXXX       , XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX           , XXXXXXX   , XXXXXXX   , XXXXXXX   , XXXXXXX   
    ),
};
