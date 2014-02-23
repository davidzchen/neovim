/* vi:set ts=8 sts=4 sw=4:
 *
 * VIM - Vi IMproved	by Bram Moolenaar
 *
 * Do ":help uganda"  in Vim to read copying and usage conditions.
 * Do ":help credits" in Vim to see a list of people who contributed.
 */

/*
 * Definitions of various common control characters.
 * For EBCDIC we have to use different values.
 */


/* IF_EB(ASCII_constant, EBCDIC_constant) */
#define IF_EB(a, b)     a

#define CharOrd(x)      ((x) < 'a' ? (x) - 'A' : (x) - 'a')
#define CharOrdLow(x)   ((x) - 'a')
#define CharOrdUp(x)    ((x) - 'A')
#define ROT13(c, a)     (((((c) - (a)) + 13) % 26) + (a))

#define NUL             '\000'
#define BELL            '\007'
#define BS              '\010'
#define TAB             '\011'
#define NL              '\012'
#define NL_STR          (char_u *)"\012"
#define FF              '\014'
#define CAR             '\015'  /* CR is used by Mac OS X */
#define ESC             '\033'
#define ESC_STR         (char_u *)"\033"
#define ESC_STR_nc      "\033"
#define DEL             0x7f
#define DEL_STR         (char_u *)"\177"
#define CSI             0x9b    /* Control Sequence Introducer */
#define CSI_STR         "\233"
#define DCS             0x90    /* Device Control String */
#define STERM           0x9c    /* String Terminator */

#define POUND           0xA3

#define Ctrl_chr(x)     (TOUPPER_ASC(x) ^ 0x40) /* '?' -> DEL, '@' -> ^@, etc. */
#define Meta(x)         ((x) | 0x80)

#define CTRL_F_STR      "\006"
#define CTRL_H_STR      "\010"
#define CTRL_V_STR      "\026"

enum CtrlChar {
  Ctrl_AT,  /* @ */
  Ctrl_A,
  Ctrl_B,
  Ctrl_C,
  Ctrl_D,
  Ctrl_E,
  Ctrl_F,
  Ctrl_G,
  Ctrl_H,
  Ctrl_I,
  Ctrl_J,
  Ctrl_K,
  Ctrl_L,
  Ctrl_M,
  Ctrl_N,
  Ctrl_O,
  Ctrl_P,
  Ctrl_Q,
  Ctrl_R,
  Ctrl_S,
  Ctrl_T,
  Ctrl_U,
  Ctrl_V,
  Ctrl_W,
  Ctrl_X,
  Ctrl_Y,
  Ctrl_Z,
  /* CTRL- [ Left Square Bracket == ESC*/
  Ctrl_BSL = 28,  /* \ BackSLash */
  Ctrl_RSB,       /* ] Right Square Bracket */
  Ctrl_HAT,       /* ^ */
  Ctrl__
};

/*
 * Character that separates dir names in a path.
 * For MS-DOS, WIN32 and OS/2 we use a backslash.  A slash mostly works
 * fine, but there are places where it doesn't (e.g. in a command name).
 * For Acorn we use a dot.
 */
#ifdef BACKSLASH_IN_FILENAME
# define PATHSEP        psepc
# define PATHSEPSTR     pseps
#else
# define PATHSEP        '/'
# define PATHSEPSTR     "/"
#endif
