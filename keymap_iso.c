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
    [0] = KEYMAP(  
        FN8 ,1   ,2   ,3   ,4   ,5   ,6   ,7   ,8   ,9   ,0   ,MINS,EQL ,BSPC,    GRV ,\
        TAB ,Q   ,W   ,E   ,R   ,T   ,Y   ,U   ,I   ,O   ,P   ,LBRC,RBRC,          DEL,\
        LCTL,A   ,S   ,D   ,F   ,G   ,H   ,J   ,K   ,L   ,FN3 ,QUOT,NUHS,ENT ,    PGUP,\
        LSFT,FN2 ,Z   ,X   ,C   ,V   ,B   ,N   ,M   ,COMM,DOT ,SLSH,RSFT,     UP, PGDN,\
        FN1 ,LGUI,LALT,               SPC,           RALT,RGUI,FN1 ,    LEFT,DOWN,RGHT  ),
    [1] = KEYMAP(  
        FN8 ,F1  ,F2  ,F3  ,F4  ,F5  ,F6  ,F7  ,F8  ,F9  ,F10 ,F11 ,F12 ,BSPC,    CAPS,\
        TAB ,DEL ,TRNS,UP  ,PSCR,BRK ,TRNS,PSCR,UP  ,TRNS,DEL ,TRNS,TRNS,          INS,\
        LCTL,TRNS,LEFT,DOWN,RGHT,TRNS,TRNS,LEFT,DOWN,RGHT,FN3 ,INS ,SLCK,ENT ,    HOME,\
        LSFT,FN2 ,HOME,PGUP,PGDN,END ,TRNS,TRNS,HOME,PGUP,PGDN,END ,RSFT,     UP,  END,\
        FN1 ,LGUI,LALT,              BSPC,           RALT,RGUI,FN1 ,    LEFT,DOWN,RGHT  ),
    [2] = KEYMAP(  
        FN8 ,F1  ,F2  ,F3  ,F4  ,F5  ,F6  ,F7  ,F8  ,F9  ,F10 ,F11 ,F12 ,BSPC,    NLCK ,\
        TAB ,DEL ,PMNS,PPLS,PAST,PSLS,TRNS,P7  ,P8  ,P9  ,PSLS,TRNS,TRNS,          DEL,\
        LCTL,EQL ,DEL ,PENT,TAB ,FN6 ,TRNS,P4  ,P5  ,P6  ,FN3 ,TRNS,NLCK,TRNS,    PGUP,\
        LSFT,FN2 ,TRNS,TRNS,TRNS,FN7 ,PDOT,P0  ,P1  ,P2  ,P3  ,PDOT,RSFT,     UP, PGDN,\
        FN1 ,LGUI,LALT,              BSPC,           RALT,RGUI,FN1 ,    LEFT,DOWN,RGHT  ),
    [3] = KEYMAP(  
        FN8 ,F1  ,F2  ,F3  ,F4  ,F5  ,F6  ,F7  ,F8  ,F9  ,F10 ,F11 ,F12 ,BSPC,    GRV ,\
        TAB ,TRNS,BTN4,WH_U,BTN5,TRNS,TRNS,TRNS,MS_U,TRNS,TRNS,TRNS,TRNS,          DEL,\
        LCTL,TRNS,BTN2,BTN3,BTN1,TRNS,TRNS,MS_L,MS_D,MS_R,FN3 ,TRNS,TRNS,TRNS,    PGUP,\
        LSFT,FN2 ,TRNS,TRNS,WH_D,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,RSFT,     UP, PGDN,\
        FN1 ,LGUI,LALT,               SPC,           RALT,RGUI,FN1 ,    LEFT,DOWN,RGHT  ),
    [4] = KEYMAP(  
        FN8 , NO , NO , NO , NO , NO , NO , NO , NO , NO , NO ,VOLD,VOLU,PWR ,     NO ,\
         NO , NO , NO , NO , NO , NO , NO , NO , NO , NO ,MPLY,MPRV,MNXT,          NO ,\
         NO , NO , NO , NO , NO , NO , NO , NO , NO , NO , NO , NO , NO,  NO ,     NO ,\
         NO , NO , NO , NO , NO , NO , NO , NO , NO , NO , NO , NO , NO ,     NO,  NO ,\
         NO , NO , NO ,                NO,            NO , NO , NO ,     NO , NO , NO   ),

};

const uint16_t fn_actions[] = {
    [1] = ACTION_LAYER_MOMENTARY(1),
    [2] = ACTION_LAYER_TAP_KEY(2, KC_NUBS),
    [3] = ACTION_LAYER_TAP_KEY(3, KC_SCLN),
    [4] = ACTION_MODS_ONESHOT(MOD_LSFT),
    [5] = ACTION_MODS_ONESHOT(MOD_RSFT),
    [6] = ACTION_MODS_KEY(MOD_LSFT, KC_SCLN),
    [7] = ACTION_MODS_KEY(MOD_LSFT, KC_TAB),
    [8] = ACTION_LAYER_TAP_KEY(4, KC_ESC),
};
