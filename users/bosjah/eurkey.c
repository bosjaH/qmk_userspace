#include <quantum.h>
#include "eurkey.h"

const uint32_t unicode_map[] PROGMEM = {
    // Row 1 (numbers)
    [INVERTED_EXCLAMATION] = 0x00A1,                [SUPERSCRIPT_ONE] = 0x00B9,                // ¡ ¹
    [FEMININE_ORDINAL] = 0x00AA,                    [SUPERSCRIPT_TWO] = 0x00B2,                // ª ²
    [MASCULINE_ORDINAL] = 0x00BA,                   [SUPERSCRIPT_THREE] = 0x00B3,              // º ³
    [POUND_SIGN] = 0x00A3,                          [YEN_SIGN] = 0x00A5,                       // £ ¥
    [EURO_SIGN] = 0x20AC,                           [CENT_SIGN] = 0x00A2,                      // € ¢
    [DOUBLE_LOW_9_QUOTATION] = 0x201E,              [SINGLE_LOW_9_QUOTATION] = 0x201A,         // „ ‚
    [LEFT_DOUBLE_QUOTATION] = 0x201C,               [LEFT_SINGLE_QUOTATION] = 0x2018,          // " '
    [RIGHT_DOUBLE_QUOTATION] = 0x201D,              [RIGHT_SINGLE_QUOTATION] = 0x2019,         // " '
    [CHECK_MARK] = 0x2713,                          [X_MARK] = 0x2717,                         // ✓ ✗
    [MULTIPLICATION_SIGN] = 0x00D7,                 [DIVISION_SIGN] = 0x00F7,                  // × ÷

    // Row 2 (QWERTY)
    [SMALL_AE] = 0x00E6,                            [CAPITAL_AE] = 0x00C6,                     // æ Æ
    [SMALL_A_RING] = 0x00E5,                        [CAPITAL_A_RING] = 0x00C5,                 // å Å
    [SMALL_E_DIAERESIS] = 0x00EB,                   [CAPITAL_E_DIAERESIS] = 0x00CB,            // ë Ë
    [SMALL_Y_ACUTE] = 0x00FD,                       [CAPITAL_Y_ACUTE] = 0x00DD,                // ý Ý
    [SMALL_THORN] = 0x00FE,                         [CAPITAL_THORN] = 0x00DE,                  // þ Þ
    [SMALL_Y_DIAERESIS] = 0x00FF,                   [CAPITAL_Y_DIAERESIS] = 0x0178,            // ÿ Ÿ
    [SMALL_U_DIAERESIS] = 0x00FC,                   [CAPITAL_U_DIAERESIS] = 0x00DC,            // ü Ü
    [SMALL_I_DIAERESIS] = 0x00EF,                   [CAPITAL_I_DIAERESIS] = 0x00CF,            // ï Ï
    [SMALL_O_DIAERESIS] = 0x00F6,                   [CAPITAL_O_DIAERESIS] = 0x00D6,            // ö Ö
    [SMALL_OE] = 0x0153,                            [CAPITAL_OE] = 0x0152,                     // œ Œ
    [LEFT_DOUBLE_ANGLED_BRACKET] = 0x00AB,          [LEFT_SINGLE_ANGLED_BRACKET] = 0x2039,     // « ‹
    [RIGHT_DOUBLE_ANGLED_BRACKET] = 0x00BB,         [RIGHT_SINGLE_ANGLED_BRACKET] = 0x203A,    // » ›
    [NOT_SIGN] = 0x00AC,                            [BROKEN_BAR] = 0x00A6,                     // ¬ ¦

    // Row 3 (ASDF)
    [SMALL_A_DIAERESIS] = 0x00E4,                   [CAPITAL_A_DIAERESIS] = 0x00C4,            // ä Ä
    [SMALL_SHARP_S] = 0x00DF,                       [CAPITAL_SHARP_S] = 0x1E9E,                // ß ẞ
    [SMALL_D_STROKE] = 0x0111,                      [CAPITAL_D_STROKE] = 0x0110,               // đ Đ
    [SMALL_E_GRAVE] = 0x00E8,                       [CAPITAL_E_GRAVE] = 0x00C8,                // è È
    [SMALL_E_ACUTE] = 0x00E9,                       [CAPITAL_E_ACUTE] = 0x00C9,                // é É
    [SMALL_U_GRAVE] = 0x00F9,                       [CAPITAL_U_GRAVE] = 0x00D9,                // ù Ù
    [SMALL_U_ACUTE] = 0x00FA,                       [CAPITAL_U_ACUTE] = 0x00DA,                // ú Ú
    [SMALL_IJ] = 0x0133,                            [CAPITAL_IJ] = 0x0132,                     // ĳ Ĳ
    [SMALL_O_STROKE] = 0x00F8,                      [CAPITAL_O_STROKE] = 0x00D8,               // ø Ø
    [DEGREE_SIGN] = 0x00B0,                         [MIDDLE_DOT] = 0x00B7,                     // ° ·

    // Row 4 (ZXCV)
    [SMALL_A_GRAVE] = 0x00E0,                       [CAPITAL_A_GRAVE] = 0x00C0,                // à À
    [SMALL_A_ACUTE] = 0x00E1,                       [CAPITAL_A_ACUTE] = 0x00C1,                // á Á
    [SMALL_C_CEDILLA] = 0x00E7,                     [CAPITAL_C_CEDILLA] = 0x00C7,              // ç Ç
    [SMALL_I_GRAVE] = 0x00EC,                       [CAPITAL_I_GRAVE] = 0x00CC,                // ì Ì
    [SMALL_I_ACUTE] = 0x00ED,                       [CAPITAL_I_ACUTE] = 0x00CD,                // í Í
    [SMALL_N_TILDE] = 0x00F1,                       [CAPITAL_N_TILDE] = 0x00D1,                // ñ Ñ
    [GREEK_SMALL_MU] = 0x03BC,                      [INFINITY] = 0x221E,                       // μ ∞
    [SMALL_O_GRAVE] = 0x00F2,                       [CAPITAL_O_GRAVE] = 0x00D2,                // ò Ò
    [SMALL_O_ACUTE] = 0x00F3,                       [CAPITAL_O_ACUTE] = 0x00D3,                // ó Ó
    [INVERTED_QUESTION_MARK] = 0x00BF,              [HORIZONTAL_ELLIPSIS] = 0x2026,            // ¿ …
};
