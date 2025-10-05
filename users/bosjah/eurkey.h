#pragma once

enum unicode_names {
    // Row 1 (numbers) - AltGr and Shift+AltGr
    INVERTED_EXCLAMATION,                   SUPERSCRIPT_ONE,                    // ¡ and ¹
    FEMININE_ORDINAL,                       SUPERSCRIPT_TWO,                    // ª and ²
    MASCULINE_ORDINAL,                      SUPERSCRIPT_THREE,                  // º and ³
    POUND_SIGN,                             YEN_SIGN,                           // £ and ¥
    EURO_SIGN,                              CENT_SIGN,                          // € and ¢
    DOUBLE_LOW_9_QUOTATION,                 SINGLE_LOW_9_QUOTATION,             // „ and ‚
    LEFT_DOUBLE_QUOTATION,                  LEFT_SINGLE_QUOTATION,              // " and '
    RIGHT_DOUBLE_QUOTATION,                 RIGHT_SINGLE_QUOTATION,             // " and '
    CHECK_MARK,                             X_MARK,                             // ✓ and ✗
    MULTIPLICATION_SIGN,                    DIVISION_SIGN,                      // × and ÷

    // Row 2 (QWERTY) - AltGr and Shift+AltGr
    SMALL_AE,                               CAPITAL_AE,                         // æ and Æ
    SMALL_A_RING,                           CAPITAL_A_RING,                     // å and Å
    SMALL_E_DIAERESIS,                      CAPITAL_E_DIAERESIS,                // ë and Ë
    SMALL_Y_ACUTE,                          CAPITAL_Y_ACUTE,                    // ý and Ý
    SMALL_THORN,                            CAPITAL_THORN,                      // þ and Þ
    SMALL_Y_DIAERESIS,                      CAPITAL_Y_DIAERESIS,                // ÿ and Ÿ
    SMALL_U_DIAERESIS,                      CAPITAL_U_DIAERESIS,                // ü and Ü
    SMALL_I_DIAERESIS,                      CAPITAL_I_DIAERESIS,                // ï and Ï
    SMALL_O_DIAERESIS,                      CAPITAL_O_DIAERESIS,                // ö and Ö
    SMALL_OE,                               CAPITAL_OE,                         // œ and Œ
    LEFT_DOUBLE_ANGLED_BRACKET,             LEFT_SINGLE_ANGLED_BRACKET,         // « and ‹
    RIGHT_DOUBLE_ANGLED_BRACKET,            RIGHT_SINGLE_ANGLED_BRACKET,        // » and ›
    NOT_SIGN,                               BROKEN_BAR,                         // ¬ and ¦

    // Row 3 (ASDF) - AltGr and Shift+AltGr
    SMALL_A_DIAERESIS,                      CAPITAL_A_DIAERESIS,                // ä and Ä
    SMALL_SHARP_S,                          CAPITAL_SHARP_S,                    // ß and ẞ
    SMALL_D_STROKE,                         CAPITAL_D_STROKE,                   // đ and Đ
    SMALL_E_GRAVE,                          CAPITAL_E_GRAVE,                    // è and È
    SMALL_E_ACUTE,                          CAPITAL_E_ACUTE,                    // é and É
    SMALL_U_GRAVE,                          CAPITAL_U_GRAVE,                    // ù and Ù
    SMALL_U_ACUTE,                          CAPITAL_U_ACUTE,                    // ú and Ú
    SMALL_IJ,                               CAPITAL_IJ,                         // ĳ and Ĳ
    SMALL_O_STROKE,                         CAPITAL_O_STROKE,                   // ø and Ø
    DEGREE_SIGN,                            MIDDLE_DOT,                         // ° and ·

    // Row 4 (ZXCV) - AltGr and Shift+AltGr
    SMALL_A_GRAVE,                          CAPITAL_A_GRAVE,                    // à and À
    SMALL_A_ACUTE,                          CAPITAL_A_ACUTE,                    // á and Á
    SMALL_C_CEDILLA,                        CAPITAL_C_CEDILLA,                  // ç and Ç
    SMALL_I_GRAVE,                          CAPITAL_I_GRAVE,                    // ì and Ì
    SMALL_I_ACUTE,                          CAPITAL_I_ACUTE,                    // í and Í
    SMALL_N_TILDE,                          CAPITAL_N_TILDE,                    // ñ and Ñ
    GREEK_SMALL_MU,                         INFINITY_SIGN,                      // μ and ∞
    SMALL_O_GRAVE,                          CAPITAL_O_GRAVE,                    // ò and Ò
    SMALL_O_ACUTE,                          CAPITAL_O_ACUTE,                    // ó and Ó
    INVERTED_QUESTION_MARK,                 HORIZONTAL_ELLIPSIS,                // ¿ and …
};

extern const uint32_t unicode_map[] PROGMEM;

// Unicode characters for Eurkey AltGr layer using Unicode Map
// Row 1 (numbers)
#define EU_1    UP(INVERTED_EXCLAMATION, SUPERSCRIPT_ONE)                       // ¡ on 1, ¹ on shift
#define EU_2    UP(FEMININE_ORDINAL, SUPERSCRIPT_TWO)                           // ª on 2, ² on shift
#define EU_3    UP(MASCULINE_ORDINAL, SUPERSCRIPT_THREE)                        // º on 3, ³ on shift
#define EU_4    UP(POUND_SIGN, YEN_SIGN)                                        // £ on 4, ¥ on shift
#define EU_5    UP(EURO_SIGN, CENT_SIGN)                                        // € on 5, ¢ on shift
// 6 and 7 are dead keys - skipping for now
#define EU_8    UP(DOUBLE_LOW_9_QUOTATION, SINGLE_LOW_9_QUOTATION)              // „ on 8, ‚ on shift
#define EU_9    UP(LEFT_DOUBLE_QUOTATION, LEFT_SINGLE_QUOTATION)                // " on 9, ' on shift
#define EU_0    UP(RIGHT_DOUBLE_QUOTATION, RIGHT_SINGLE_QUOTATION)              // " on 0, ' on shift
#define EU_MINS UP(CHECK_MARK, X_MARK)                                          // ✓ on -, ✗ on shift
#define EU_EQL  UP(MULTIPLICATION_SIGN, DIVISION_SIGN)                          // × on =, ÷ on shift

// Row 2 (QWERTY)
#define EU_Q    UP(SMALL_AE, CAPITAL_AE)                                        // æ on Q, Æ on shift
#define EU_W    UP(SMALL_A_RING, CAPITAL_A_RING)                                // å on W, Å on shift
#define EU_E    UP(SMALL_E_DIAERESIS, CAPITAL_E_DIAERESIS)                      // ë on E, Ë on shift
#define EU_R    UP(SMALL_Y_ACUTE, CAPITAL_Y_ACUTE)                              // ý on R, Ý on shift
#define EU_T    UP(SMALL_THORN, CAPITAL_THORN)                                  // þ on T, Þ on shift
#define EU_Y    UP(SMALL_Y_DIAERESIS, CAPITAL_Y_DIAERESIS)                      // ÿ on Y, Ÿ on shift
#define EU_U    UP(SMALL_U_DIAERESIS, CAPITAL_U_DIAERESIS)                      // ü on U, Ü on shift
#define EU_I    UP(SMALL_I_DIAERESIS, CAPITAL_I_DIAERESIS)                      // ï on I, Ï on shift
#define EU_O    UP(SMALL_O_DIAERESIS, CAPITAL_O_DIAERESIS)                      // ö on O, Ö on shift
#define EU_P    UP(SMALL_OE, CAPITAL_OE)                                        // œ on P, Œ on shift
#define EU_LBRC UP(LEFT_DOUBLE_ANGLED_BRACKET, LEFT_SINGLE_ANGLED_BRACKET)      // « on [, ‹ on shift
#define EU_RBRC UP(RIGHT_DOUBLE_ANGLED_BRACKET, RIGHT_SINGLE_ANGLED_BRACKET)    // » on ], › on shift
#define EU_BSLS UP(NOT_SIGN, BROKEN_BAR)                                        // ¬ on backslash, ¦ on shift

// Row 3 (ASDF)
#define EU_A    UP(SMALL_A_DIAERESIS, CAPITAL_A_DIAERESIS)                      // ä on A, Ä on shift
#define EU_S    UP(SMALL_SHARP_S, CAPITAL_SHARP_S)                              // ß on S, ẞ on shift
#define EU_D    UP(SMALL_D_STROKE, CAPITAL_D_STROKE)                            // đ on D, Đ on shift
#define EU_F    UP(SMALL_E_GRAVE, CAPITAL_E_GRAVE)                              // è on F, È on shift
#define EU_G    UP(SMALL_E_ACUTE, CAPITAL_E_ACUTE)                              // é on G, É on shift
#define EU_H    UP(SMALL_U_GRAVE, CAPITAL_U_GRAVE)                              // ù on H, Ù on shift
#define EU_J    UP(SMALL_U_ACUTE, CAPITAL_U_ACUTE)                              // ú on J, Ú on shift
#define EU_K    UP(SMALL_IJ, CAPITAL_IJ)                                        // ĳ on K, Ĳ on shift
#define EU_L    UP(SMALL_O_STROKE, CAPITAL_O_STROKE)                            // ø on L, Ø on shift
#define EU_SCLN UP(DEGREE_SIGN, MIDDLE_DOT)                                     // ° on ;, · on shift
// ' is a dead key - skipping for now

// Row 4 (ZXCV)
#define EU_Z    UP(SMALL_A_GRAVE, CAPITAL_A_GRAVE)                              // à on Z, À on shift
#define EU_X    UP(SMALL_A_ACUTE, CAPITAL_A_ACUTE)                              // á on X, Á on shift
#define EU_C    UP(SMALL_C_CEDILLA, CAPITAL_C_CEDILLA)                          // ç on C, Ç on shift
#define EU_V    UP(SMALL_I_GRAVE, CAPITAL_I_GRAVE)                              // ì on V, Ì on shift
#define EU_B    UP(SMALL_I_ACUTE, CAPITAL_I_ACUTE)                              // í on B, Í on shift
#define EU_N    UP(SMALL_N_TILDE, CAPITAL_N_TILDE)                              // ñ on N, Ñ on shift
#define EU_M    UP(GREEK_SMALL_MU, INFINITY_SIGN)                               // μ on M, ∞ on shift
#define EU_COMM UP(SMALL_O_GRAVE, CAPITAL_O_GRAVE)                              // ò on comma, Ò on shift
#define EU_DOT  UP(SMALL_O_ACUTE, CAPITAL_O_ACUTE)                              // ó on period, Ó on shift
#define EU_SLSH UP(INVERTED_QUESTION_MARK, HORIZONTAL_ELLIPSIS)                 // ¿ on slash, … on shift    _______
