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
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backspc|Grv|
     * |---------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|     |Del|
     * |------------------------------------------------------Enter----|
     * |FN0   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  #|    |PgU|
     * |---------------------------------------------------------------|
     * |Shif|  \|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Up |PgD|
     * |---------------------------------------------------------------|
     * |Ctrl|Alt |Gui|         Space         |Gui |Alt |FN0|Lef|Dow|Rig|
     * `---------------------------------------------------------------'
     */
    [0] = KEYMAP_ISO(  
        ESC ,1   ,2   ,3   ,4   ,5   ,6   ,7   ,8   ,9   ,0   ,MINS,EQL ,BSPC,    GRV ,\
        TAB ,Q   ,W   ,E   ,R   ,T   ,Y   ,U   ,I   ,O   ,P   ,LBRC,RBRC,         DEL,\
        FN0, A   ,S   ,D   ,F   ,G   ,H   ,J   ,K   ,L   ,SCLN ,QUOT,NUHS,  ENT,   PGUP,\
        LSFT,NUBS ,Z   ,X   ,C   ,V   ,B   ,N   ,M   ,COMM,DOT ,SLSH,RSFT,    UP, PGDN,\
        LCTL,LALT,LGUI,               SPC,          RGUI,RALT,FN0 ,    LEFT,DOWN,RGHT  ),
    /* Layer 1: Other keys layer
     * ,---------------------------------------------------------------.
     * |Grv| F1| F2| F3| F4| F5| F6| F7| F8| F9| F0|   |   |  Del  |   |
     * |---------------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |   |
     * |------------------------------------------------------     ----|
     * |      |   |   |   |   |   |   |   |   |   |   |   |   |    |   |
     * |---------------------------------------------------------------|
     * |    |   |   |   |   |   |   |   |   |   |   |   |      |PgU|   |
     * |---------------------------------------------------------------|
     * |    |    |    |                  |    |    |    |  |   |PgD|   |
     * `---------------------------------------------------------------'
     */

    [1] = KEYMAP_ISO(  
        GRV,	F1,	F2,	F3,	F4,	F5,	F6,	F7,	F8,	F9,	F10,	F11,	F12,	DEL,	TRNS,\
		TRNS,	TRNS,	TRNS,	TRNS,	TRNS,	TRNS,	TRNS,	TRNS,	TRNS,	TRNS,	TRNS,	TRNS,	TRNS,	TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS ,TRNS ,TRNS,TRNS ,    TRNS,\
        TRNS,TRNS ,TRNS,TRNS,TRNS,TRNS ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS ,TRNS,   PGUP,  TRNS,\
        TRNS ,TRNS,TRNS,              TRNS,           TRNS,TRNS,TRNS ,    TRNS,PGDN,TRNS  ),
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
	[0] = ACTION_LAYER_MOMENTARY(1),                  // FN0
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
