// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "chimera_ls.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum chimera_lets_split_layers
{
	_QWERTY,
	_CAPS,
	_NUMPAD,
	_SYMBOLS,
	_MACROS,
	_NAV
};

#define KC_NMPD TG(_NUMPAD)
#define KC_SYMB TG(_SYMBOLS)
#define KC_SPFN LT(_NAV,KC_EQL)
#define KC_SCTL MT(MOD_LCTL, KC_BSLS)
#define KC_SCTR MT(MOD_LCTL, KC_RBRC)
#define KC_SPLT MT(MOD_LALT, KC_MINS)
#define KC_MESC LT(_MACROS, KC_ESC)
#define KC_INCL M(0)
#define KC_PULL M(1)
#define KC_PUSH M(2)
#define KC_SCAP M(3)
#define KC_SCOF M(4)
#define KC_CAD LALT(LCTL(KC_DEL))

#define LONGPRESS_DELAY 150
//#define LAYER_TOGGLE_DELAY 300

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define KC_ KC_TRNS 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     MESC, Q  , W  , E  , R  , T  ,      Y  , U  , I  , O  , P  ,BSPC,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     TAB , A  , S  , D  , F  , G  ,      H  , J  , K  , L  ,SCLN, ENT,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     LSPO, Z  , X  , C  , V  , B  ,      N  , M  ,COMM,DOT ,SLSH,RSPC,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     SCTL,SPFN,SPLT,AMPR,NMPD,SPC ,     SPC ,SYMB,ASTR,EXLM,LBRC,SCTR
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_CAPS] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    ,    ,    ,COLN,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,UNDS,    ,    ,    ,         ,    ,    ,    ,    ,    
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),


  [_NUMPAD] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,         ,  7 ,  8 ,  9 ,MINS,QUOT,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,  4 ,  5 ,  6 ,PLUS, ENT,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     LSFT,    ,    ,    ,    ,    ,         ,  1 ,  2 ,  3 ,ASTR, EQL,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,BSPC,     SPC ,  0 ,  0 , DOT,SLSH,    
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_SYMBOLS] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
         ,EXLM, AT ,HASH,DLR ,PERC,     CIRC,AMPR,ASTR,LPRN,RPRN,QUOT,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      F1 , F2 , F3 , F4 , F5 , F6 ,     TILD,EQL ,UNDS,LCBR,RCBR,PIPE,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      F7 , F8 , F9 , F10, F11, F12,     GRV ,PLUS,MINS,LBRC,RBRC,BSLS,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    , NO ,BSPC,     SPC ,    ,    ,    ,    ,    
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_NAV] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
         ,    ,    ,    , DEL,BSPC,         ,HOME, UP , END, INS,PSCR,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,LSFT,LCTL, ENT,         ,LEFT,DOWN,RGHT, DEL,   ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,PGUP,PGDN,    ,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,DEL ,         ,    ,    ,    ,    ,   
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_MACROS] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,         ,    ,INCL,    ,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,CAD ,    ,    ,         ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     SCOF,    ,    ,    ,    ,    ,         ,    ,PULL,PUSH,    ,SCAP,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,   
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

};


const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    /* include some kind of library or header */
    case 0:
      if (record->event.pressed) {
        SEND_STRING("#include <>");
        return MACRO( T(LEFT), END);
      }
      break;
    case 1:
      if (record->event.pressed) {
        SEND_STRING("git pull");
        return MACRO( T(ENT), END );
      }
      break;
    case 2:
      if (record->event.pressed){
        SEND_STRING("git push");
        return MACRO( T(ENT), END );
      }
      break;
    case 3:
      if (record->event.pressed){
        layer_on(_CAPS);
        register_code(KC_CAPSLOCK);
        unregister_code(KC_CAPSLOCK);
      }
      break;
    case 4:
      if (record->event.pressed){
        layer_off(_CAPS);
        register_code(KC_CAPSLOCK);
        unregister_code(KC_CAPSLOCK);
      }
      break;
  }
  return MACRO_NONE;
};
 

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);
    
    switch (layer) {
    	case _QWERTY:
    	    set_led_green;
    	    break;
        case _CAPS:
	    set_led_white;
	    break;
        case _NUMPAD:
            set_led_blue;
            break;
        case _SYMBOLS:
            set_led_red;
            break;
        case _NAV:
	    set_led_magenta;
	    break;
        case _MACROS:
	    set_led_cyan;
	    break;
       default:
            set_led_green;
            break;
    }
};
