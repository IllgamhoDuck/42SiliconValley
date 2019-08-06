/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_input.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 01:38:16 by hypark            #+#    #+#             */
/*   Updated: 2019/08/05 20:59:59 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_INPUT_H
# define FDF_INPUT_H

/*
** ===========MOUSE============
*/

# define M_LEFT 1
# define M_RIGHT 2
# define M_THIRD 3
# define M_S_UP 5
# define M_S_DOWN 4
# define M_S_LEFT 7
# define M_S_RIGHT 6

/*
** ===========KEYBOARD============
*/

# define KEY_ESC 53
# define KEY_SPA 49

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define KEY_5 23
# define KEY_6 22
# define KEY_7 26
# define KEY_8 28
# define KEY_9 25
# define KEY_0 29

# define NUM_1 83
# define NUM_2 84
# define NUM_3 85
# define NUM_4 86
# define NUM_5 87
# define NUM_6 88
# define NUM_7 89
# define NUM_8 91
# define NUM_9 92
# define NUM_0 82

/*
** !@#$%^&*()_+ is exactly same as the following KEYPAD number 0123~
*/

# define KEY_MINUS 27
# define KEY_EQU 24
# define KEY_REVERSE_QUO 50
# define KEY_WAVE 257

/*
** LSH - LSHIFT RSH - RSHIFT LCM - LCOMMAND RCM - RCOMMAND
*/

# define KEY_LSH 257
# define KEY_RSH 258
# define KEY_LCM 259
# define KEY_RCM 260
# define KEY_LOP 261
# define KEY_ROP 262
# define KEY_LCT 256
# define KEY_RCT 269

# define KEY_DEL 18
# define KEY_TAB 48
# define KEY_ENT 36
# define KEY_CAP 272

/*
** Other function key is used by MACOS
*/

# define KEY_F5 96
# define KEY_F6 97
# define KEY_F13 105
# define KEY_F14 107
# define KEY_F15 113
# define KEY_F16 106
# define KEY_F17 64
# define KEY_F18 79
# define KEY_F19 80

/*
** LBR - left bracket {[ RBR - right bracket }] SLA - slash \|
** COL - colon :; QUO - quotation '" COM - comma ,< DOT .> QUE - question ?
*/

# define KEY_LBR 33
# define KEY_RBR 30
# define KEY_SLA 42
# define KEY_COL 41
# define KEY_QUO 39
# define KEY_COM 43
# define KEY_DOT 47
# define KEY_QUE 44

# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_T 17
# define KEY_Y 16
# define KEY_U 32
# define KEY_I 34
# define KEY_O 31
# define KEY_P 35

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_G 5
# define KEY_H 4
# define KEY_J 38
# define KEY_K 40
# define KEY_L 37

# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_N 45
# define KEY_M 46

# define KEY_FN 279
# define KEY_HM 115
# define KEY_PUP 116
# define KEY_PDO 121
# define KEY_DEL2 117
# define KEY_END 119

# define NUM_EQU 81
# define NUM_SLA 75
# define NUM_ASTERISK 67
# define NUM_MINUS 78
# define NUM_PLUS 69
# define NUM_ENT 76
# define NUM_DOT 65

#endif
