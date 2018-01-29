/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

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
#include "keymap_common.h"

#include "led_controller.h"

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,---------------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backspc|Ins|
     * |---------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|     |Del|
     * |------------------------------------------------------Enter----|
     * |CapsLo|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  #|    |PgU|
     * |---------------------------------------------------------------|
     * |Shif|  \|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Up |PgD|
     * |---------------------------------------------------------------|
     * |Ctrl|Gui |Alt |         Space    |Fn0 |Alt |Gui |  |Lef|Dow|Rig|
     * `---------------------------------------------------------------'
     */
    [0] = KEYMAP_ISO(  
        FN8 ,1   ,2   ,3   ,4   ,5   ,6   ,7   ,8   ,9   ,0   ,MINS,EQL ,BSPC,    FN11 ,\
        TAB ,Q   ,W   ,E   ,R   ,T   ,Y   ,U   ,I   ,O   ,P   ,LBRC,RBRC,          FN4,\
        CAPS,A   ,S   ,D   ,F   ,G   ,H   ,J   ,K   ,L   ,FN3 ,QUOT,NUHS,ENT ,    FN5,\
        LSFT,FN2 ,Z   ,X   ,C   ,V   ,B   ,N   ,M   ,COMM,DOT ,SLSH,RSFT,     UP, PGDN,\
        LCTL ,LGUI,LALT,               SPC,           RALT,RGUI,FN1 ,    LEFT,DOWN,RGHT  ),
    [1] = KEYMAP_ISO(  
        FN8 ,F1  ,F2  ,F3  ,F4  ,F5  ,F6  ,F7  ,F8  ,F9  ,F10 ,F11 ,F12 ,BSPC,    CAPS,\
        TAB ,DEL ,TRNS,UP  ,PSCR,BRK ,TRNS,PSCR,UP  ,TRNS,DEL ,TRNS,TRNS,          INS,\
        LCTL,TRNS,LEFT,DOWN,RGHT,TRNS,TRNS,LEFT,DOWN,RGHT,FN3 ,INS ,SLCK,ENT ,    HOME,\
        LSFT,FN2 ,HOME,PGUP,PGDN,END ,TRNS,TRNS,HOME,PGUP,PGDN,END ,RSFT,     UP,  END,\
        FN1 ,LGUI,LALT,              BSPC,           RALT,RGUI,FN1 ,    LEFT,DOWN,RGHT  ),
    [2] = KEYMAP_ISO(  
        FN8 ,F1  ,F2  ,F3  ,F4  ,F5  ,F6  ,F7  ,F8  ,F9  ,F10 ,F11 ,F12 ,BSPC,    NLCK ,\
        TAB ,DEL ,PMNS,PPLS,PAST,PSLS,TRNS,P7  ,P8  ,P9  ,PSLS,TRNS,TRNS,          DEL,\
        LCTL,EQL ,DEL ,PENT,TAB ,FN6 ,TRNS,P4  ,P5  ,P6  ,FN3 ,TRNS,NLCK,TRNS,    PGUP,\
        LSFT,FN2 ,TRNS,TRNS,TRNS,FN7 ,PDOT,P0  ,P1  ,P2  ,P3  ,PDOT,RSFT,     UP, PGDN,\
        FN1 ,LGUI,LALT,              BSPC,           RALT,RGUI,FN1 ,    LEFT,DOWN,RGHT  ),
    [3] = KEYMAP_ISO(  
        FN8 ,F1  ,F2  ,F3  ,F4  ,F5  ,F6  ,F7  ,F8  ,F9  ,F10 ,F11 ,F12 ,BSPC,    GRV ,\
        TAB ,TRNS,BTN4,WH_U,BTN5,TRNS,TRNS,TRNS,MS_U,TRNS,TRNS,TRNS,TRNS,          DEL,\
        LCTL,TRNS,BTN2,BTN3,BTN1,TRNS,TRNS,MS_L,MS_D,MS_R,FN3 ,TRNS,TRNS,TRNS,    PGUP,\
        LSFT,FN2 ,TRNS,TRNS,WH_D,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,RSFT,     UP, PGDN,\
        FN1 ,LGUI,LALT,               SPC,           RALT,RGUI,FN1 ,    LEFT,DOWN,RGHT  ),
    [4] = KEYMAP_ISO(  
        FN8 , NO , NO , NO , NO , NO , NO , NO , NO , NO , NO ,VOLD,VOLU,PWR ,     NO ,\
         NO , NO , NO , NO , NO , NO , NO , NO , NO , NO ,MPLY,MPRV,MNXT,          NO ,\
         NO , NO , NO , NO , NO , NO , NO , NO , NO , NO , NO , NO , NO,  NO ,     NO ,\
         NO , NO , NO , NO , NO , NO , NO , NO , NO , NO , NO , NO , NO ,     NO,  NO ,\
         NO , NO , NO ,                NO,            NO , NO , NO ,     NO , NO , NO   ),

};


/* Give numbers some descriptive names */
#define ACTION_LEDS_ALL 1
#define ACTION_LEDS_GAME 2
#define ACTION_TILDE_LED 3

#define TILDE_LED 0x3b
#define DELETE_LED 0x5a
#define PGUP_LED 0x79
#define PGDOWN_LED 0x98


const action_t fn_actions[] = {
    [3] = ACTION_LAYER_TAP_KEY(3, KC_SCLN),
    [4] = ACTION_FUNCTION(ACTION_LEDS_ALL),
    [5] = ACTION_FUNCTION(ACTION_LEDS_GAME),
    [6] = ACTION_MODS_KEY(MOD_LSFT, KC_SCLN),
    [7] = ACTION_MODS_KEY(MOD_LSFT, KC_TAB),
    [8] = ACTION_LAYER_TAP_KEY(4, KC_ESC),
    [9] = ACTION_MODS_ONESHOT(MOD_LSFT),
    [10] = ACTION_MODS_ONESHOT(MOD_RSFT),
    [11] = ACTION_FUNCTION(ACTION_TILDE_LED),
};
/* custom action function */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  (void)opt;
  uint8_t temp;
  switch(id) {
    case ACTION_LEDS_ALL:
        if(record->event.pressed) {
          // signal the LED controller thread
          chMBPost(&led_mailbox, LED_MSG_GAME_TOGGLE, TIME_IMMEDIATE);
        }
      break;
    case ACTION_LEDS_GAME:
      if(record->event.pressed) {
        // signal the LED controller thread
        chMBPost(&led_mailbox, LED_MSG_ALL_TOGGLE, TIME_IMMEDIATE);
		register_code(KC_PGUP);
		unregister_code(KC_PGUP);
		send_keyboard_report();
      }
      break;
	case ACTION_TILDE_LED:
	  is31_read_register(0, TILDE_LED, &temp);
	  chThdSleepMilliseconds(1);
	  if(temp) {
		  // turn off on pages 1 and 2
		  is31_write_register(0, TILDE_LED, 0);
		  is31_write_register(1, TILDE_LED, 0);
	  } else {
		  // turn on on pages 1 and 2
		  is31_write_register(0, TILDE_LED, 0xFF);
		  is31_write_register(1, TILDE_LED, 0xFF);
	  }
	  register_code(KC_GRV);
	  unregister_code(KC_GRV);
	  send_keyboard_report();

	  break;
  }
}
