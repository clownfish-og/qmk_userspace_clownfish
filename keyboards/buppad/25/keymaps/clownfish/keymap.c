// Copyright (C) 2024 ClownFish (@clownfish-og)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <ctype.h>
#include "keymap.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        TO(1),      CHEESE,     AMNESIA,    GROOVY,     DUCKDANCE,
        DISCO,      DIDDY,      CATDANCE,   SLAY,       BEARDDANCE,
        PATBANG,    FREAKOUT,   DRUMS,      FROG,       KEKW,
        BACKDOOR,   LOVE,       THANKS,     ZEJIBO,     BUG,
        BITS,       MOOSE,      BUP,        CAPGEN5,    KC_ENT
    ),
    [1] = LAYOUT(
        TO(0),      TO(5),      TO(2),      TO(3),      TO(4),
        WATER,      DONUT,      DYE,        SMIRK,      EXCUSEME,
        RUMP,       TINFOIL,    CLOUDS,     SALT,       WINK,
        BALLOON,    HEART,      ASCEND,     JELLY,      BUPO,
        RAVE,       CROWN,      TIEDYE,     SUS,        DRAGON
    ),
    [2] = LAYOUT(
        TO(0),      TO(1),      TO(5),      TO(3),      TO(4),
        DUCKHEAD,   WIZ,        CHEFKISS,   MAPLE,      BIGBRAIN,
        CALL,       DOIT,       GROGU,      JAWNESSA,   BART,
        BUPS,       BROC,       BUPWAD,     LUIGIBUP,   ZELDABUP,
        AYO,        TUNE,       SH,         EE,         ID
    ),
    [3] = LAYOUT(
        TO(0),      TO(1),      TO(2),      TO(5),      TO(4),
        BASSSFACE,  BOB,        LIGHTER,    UWU,        UP,
        NOD,        GOOSE,      BOOMER,     WUB,        WOOK,
        HEADOUT,    RAINBOW,    SALUTE,     SWEATY,     HORN,
        FLUTE,      FIRE,       CHEERS,     KEYS,       CHILLGUY
    ),
    [4] = LAYOUT(
        TO(0),      TO(1),      TO(2),      TO(3),      TO(5),
        WHIYA,      BDANCE,     GPTUNE,     KSMUG,      KHUG,
        WGRIN,      KYLGHT,     GPMNKY,     KRDNC,      KLOVE,
        WHRTBT,     KYPOLR,     GPLFG,      KCLAP,      BOPBOP,
        WCLNFSH,    KYCFOG,     GPCFSW,     TTHIS,      ETGOLD
    ),
    [5] = LAYOUT(
        TO(0),      TO(1),      TO(2),      TO(3),      TO(4),
        UG_NEXT,    UG_VALU,    UG_HUEU,    UG_SATU,    UG_SPDU,
        UG_PREV,    UG_VALD,    UG_HUED,    UG_SATD,    UG_SPDD,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
        TT(6),      RMAM,       RMPL,       RMSW,       UG_TOGG
    ),
    [6] = LAYOUT(
        TO(0),      KC_NUM,     KC_PSLS,    KC_PAST,    KC_BSPC,
        KC_NO,      KC_P7,      KC_P8,      KC_P9,      KC_PMNS,
        KC_NO,      KC_P4,      KC_P5,      KC_P6,      KC_PPLS,
        KC_NO,      KC_P1,      KC_P2,      KC_P3,      KC_NO,
        _______,    KC_P0,      KC_P0,      KC_PDOT,    KC_PENT
    ),
};

const char amnesia[] PROGMEM = "bupAmnesia";
const char ayo[] PROGMEM = "bupAyo";
const char backdoor[] PROGMEM = "bupBackdoor";
const char balloon[] PROGMEM = "bupBalloon";
const char bart[] PROGMEM = "bupBart";
const char bearddance[] PROGMEM = "bupBEARDDANCE";
const char bigbrain[] PROGMEM = "bupBigBrain";
const char bits[] PROGMEM = "bupBITS";
const char boomer[] PROGMEM = "bupBOOMER";
const char bug[] PROGMEM = "bupBug";
const char bup[] PROGMEM = "bupBup";
const char bups[] PROGMEM = "bupBUPS";
const char bupwad[] PROGMEM = "bupBUPWAD";
const char call[] PROGMEM = "bupCall";
const char catdance[] PROGMEM = "bupCATDANCE";
const char cheers[] PROGMEM = "bupCHEERS";
const char cheese[] PROGMEM = "bupCheese";
const char chefkiss[] PROGMEM = "bupChefkiss";
const char crown[] PROGMEM = "bupCrown";
const char diddy[] PROGMEM = "bupDiddy";
const char disco[] PROGMEM = "bupDisco";
const char doit[] PROGMEM = "bupDOIT";
const char donut[] PROGMEM = "bupDonut";
const char drums[] PROGMEM = "bupDrums";
const char duckdance[] PROGMEM = "bupDUCKDANCE";
const char duckhead[] PROGMEM = "bupDuckhead";
const char dye[] PROGMEM = "bupDye";
const char ee[] PROGMEM = "bupEE";
const char fire[] PROGMEM = "bupFire";
const char flute[] PROGMEM = "bupFLUTE";
const char freakout[] PROGMEM = "bupFreakout";
const char frog[] PROGMEM = "bupFROG";
const char grogu[] PROGMEM = "bupGrogu";
const char groovy[] PROGMEM = "bupGroovy";
const char headout[] PROGMEM = "bupHEADOUT";
const char horn[] PROGMEM = "bupHORN";
const char house[] PROGMEM = "bupHouse";
const char id[] PROGMEM = "bupID";
const char kekw[] PROGMEM = "bupKekw";
const char keys[] PROGMEM = "bupKEYS";
const char lighter[] PROGMEM = "bupLighter";
const char love[] PROGMEM = "bupLOVE";
const char luigibup[] PROGMEM = "bupLUIGIBUP";
const char moose[] PROGMEM = "bupMOOSE";
const char bupo[] PROGMEM = "bupO";
const char patbang[] PROGMEM = "bupPATBANG";
const char salute[] PROGMEM = "bupSalute";
const char sh[] PROGMEM = "bupSh";
const char slay[] PROGMEM = "bupSlay";
const char spin[] PROGMEM = "bupSpin";
const char sweaty[] PROGMEM = "bupSweaty";
const char thanks[] PROGMEM = "bupTHANKS";
const char thing[] PROGMEM = "bupThing";
const char wook[] PROGMEM = "bupWOOK";
const char wub[] PROGMEM = "bupWUB";
const char zejibo[] PROGMEM = "bupZejibo";
const char zeldabup[] PROGMEM = "bupZELDABUP";
const char broc[] PROGMEM = "bupBroc";
const char clouds[] PROGMEM = "bupClouds";
const char goose[] PROGMEM = "bupGoose";
const char heart[] PROGMEM = "bupHeart";
const char jawnessa[] PROGMEM = "bupJAWNESSA";
const char rave[] PROGMEM = "bupRave";
const char salt[] PROGMEM = "bupSalt";
const char tinfoil[] PROGMEM = "bupTINFOIL";
const char water[] PROGMEM = "bupWater";
const char wiz[] PROGMEM = "bupWiz";
const char basssface[] PROGMEM = "bupBASSSFACE";
const char bob[] PROGMEM = "bupBOB";
const char chillguy[] PROGMEM = "bupChillguy";
const char dragon[] PROGMEM = "bupDragon";
const char jelly[] PROGMEM = "bupJelly";
const char maple[] PROGMEM = "bupMaple";
const char rump[] PROGMEM = "bupRump";
const char smirk[] PROGMEM = "bupSmirk";
const char uwu[] PROGMEM = "bupUWU";
const char wink[] PROGMEM = "bupWink";
const char abducktion[] PROGMEM = "bupAbDUCKtion";
const char ascend[] PROGMEM = "bupAscend";
const char ashduckem[] PROGMEM = "bupASHDUCKEM";
const char demayo[] PROGMEM = "bupDEMAYO";
const char excuseme[] PROGMEM = "bupEXCUSEME";
const char fancyduck[] PROGMEM = "bupFANCYDUCK";
const char gold[] PROGMEM = "bupGold";
const char headphones[] PROGMEM = "bupHEADPHONES";
const char ktuluehug[] PROGMEM = "bupKTULUEHUG";
const char rainbow[] PROGMEM = "bupRAINBOW";
const char smug[] PROGMEM = "bupSmug";
const char sus[] PROGMEM = "bupSus";
const char nod[] PROGMEM = "bupNod";
const char tiedye[] PROGMEM = "bupTIEDYE";
const char tune[] PROGMEM = "bupTUNE";
const char up[] PROGMEM = "bupUp";
const char wave[] PROGMEM = "bupWAVE";
const char bop[] PROGMEM = "BOP";
const char bopbop[] PROGMEM = "BopBop";
const char dinodance[] PROGMEM = "DinoDance";
const char glitchlit[] PROGMEM = "GlitchLit";
const char goatemotey[] PROGMEM = "GoatEmotey";
const char goldplz[] PROGMEM = "GoldPLZ";
const char kappa[] PROGMEM = "Kappa";
const char kreygasm[] PROGMEM = "Kreygasm";
const char modlove[] PROGMEM = "ModLove";
const char notlikethis[] PROGMEM = "NotLikeThis";
const char powerupl[] PROGMEM = "PowerUpL";
const char powerupr[] PROGMEM = "PowerUpR";
const char singsmic[] PROGMEM = "SingsMic";
const char singsnote[] PROGMEM = "SingsNote";
const char stinkycheese[] PROGMEM = "StinkyCheese";
const char tombraider[] PROGMEM = "TombRaid";
const char twitchconhype[] PROGMEM = "TwitchConHYPE";
const char twitchlit[] PROGMEM = "TwitchLit";
const char twitchraid[] PROGMEM = "twitchRaid";
const char unity[] PROGMEM = "TwitchUnity";
const char votenay[] PROGMEM = "VoteNay";
const char voteyea[] PROGMEM = "VoteYea";
const char bdance[] PROGMEM = "bexfroDance";
const char bmingo[] PROGMEM = "bexfroMingo";
const char bmonkey[] PROGMEM = "bexfroMonkey";
const char bpug[] PROGMEM = "bexfroPug";
const char bugh[] PROGMEM = "bexfroUgh";
const char kclap[] PROGMEM = "ktulueClap";
const char kgato[] PROGMEM = "ktulueGato";
const char kggs[] PROGMEM = "ktulueGGs";
const char kglutes[] PROGMEM = "ktulueGLUTES";
const char khi[] PROGMEM = "ktulueHI";
const char khug[] PROGMEM = "ktulueHUG";
const char klei[] PROGMEM = "ktulueLei";
const char klove[] PROGMEM = "ktulueLove";
const char krdnc[] PROGMEM = "ktulueRdnc";
const char ksmug[] PROGMEM = "ktulueSMUG";
const char wbongo[] PROGMEM = "wertyo2Bongo";
const char wclnfsh[] PROGMEM = "wertyo2Clownfish";
const char wexcite[] PROGMEM = "wertyo2Excite";
const char wglutes[] PROGMEM = "wertyo2Glutes";
const char whrtbt[] PROGMEM = "wertyo2Heartbeat";
const char whiya[] PROGMEM = "wertyo2Hiya";
const char wgrin[] PROGMEM = "wertyo2Grin";
const char kycfog[] PROGMEM = "koby36Clownfishog";
const char kypolr[] PROGMEM = "koby36Polar";
const char kysmnk[] PROGMEM = "koby36Smonk";
const char kyyes[] PROGMEM = "koby36Yes";
const char kylght[] PROGMEM = "koby36Lighter";
const char kyhart[] PROGMEM = "koby36Heartwarp";
const char gpcfsw[] PROGMEM = "gopros2Cfswag";
const char gplfg[] PROGMEM = "gopros2Lfg";
const char gpmnky[] PROGMEM = "gopros2RaveMonkey";
const char gptune[] PROGMEM = "gopros2Tune";
const char gpglch[] PROGMEM = "gopros2Glitched";
const char tthis[] PROGMEM = "tinosThis";
const char mklove[] PROGMEM = "mrkitt10ALLLOVE";
const char etgold[] PROGMEM = "etownGold";

PGM_P const emotes[] PROGMEM = {  // pointers to the strings above, in the same order as the custom_keycodes enum
    amnesia,
    ayo,
    backdoor,
    balloon,
    bart,
    bearddance,
    bigbrain,
    bits,
    boomer,
    bug,
    bup,
    bups,
    bupwad,
    call,
    catdance,
    cheers,
    cheese,
    chefkiss,
    crown,
    diddy,
    disco,
    doit,
    donut,
    drums,
    duckdance,
    duckhead,
    dye,
    ee,
    fire,
    flute,
    freakout,
    frog,
    grogu,
    groovy,
    headout,
    horn,
    house,
    id,
    kekw,
    keys,
    lighter,
    love,
    luigibup,
    moose,
    bupo,
    patbang,
    salute,
    sh,
    slay,
    spin,
    sweaty,
    thanks,
    thing,
    wook,
    wub,
    zejibo,
    zeldabup,
    broc,
    clouds,
    goose,
    heart,
    jawnessa,
    rave,
    salt,
    tinfoil,
    water,
    wiz,
    basssface,
    bob,
    chillguy,
    dragon,
    jelly,
    maple,
    rump,
    smirk,
    uwu,
    wink,
    abducktion,
    ascend,
    ashduckem,
    demayo,
    excuseme,
    fancyduck,
    gold,
    headphones,
    ktuluehug,
    rainbow,
    smug,
    sus,
    nod,
    tiedye,
    tune,
    up,
    wave,
    bop,
    bopbop,
    dinodance,
    glitchlit,
    goatemotey,
    goldplz,
    kappa,
    kreygasm,
    modlove,
    notlikethis,
    powerupl,
    powerupr,
    singsmic,
    singsnote,
    stinkycheese,
    tombraider,
    twitchconhype,
    twitchlit,
    twitchraid,
    unity,
    votenay,
    voteyea,
    bdance,
    bmingo,
    bmonkey,
    bpug,
    bugh,
    kclap,
    kgato,
    kggs,
    kglutes,
    khi,
    khug,
    klei,
    klove,
    krdnc,
    ksmug,
    wbongo,
    wclnfsh,
    wexcite,
    wglutes,
    whrtbt,
    whiya,
    wgrin,
    kycfog,
    kypolr,
    kysmnk,
    kyyes,
    kylght,
    kyhart,
    gpcfsw,
    gplfg,
    gpmnky,
    gptune,
    gpglch,
    tthis,
    mklove,
    etgold
};

const int first_emote = FIRST_EMOTE;
const int last_emote = LAST_EMOTE;

// This function inverts the capitalization of each character in the given string.
void invert_caps(char *str) {
    while (*str) {
        if (islower(*str)) {
            *str = toupper(*str);
        } else if (isupper(*str)) {
            *str = tolower(*str);
        }
        str++;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case FIRST_EMOTE ... LAST_EMOTE: {
                uint8_t i = keycode - FIRST_EMOTE;  // Convert the keycode to an index into the emotes array
                bool caps = host_keyboard_led_state().caps_lock;  //track caps lock state
                char emote_buffer[36];
                emote_buffer[0] = '\0';  // Ensure we start with an empty string
                strncpy_P(emote_buffer, (PGM_P)pgm_read_ptr(&(emotes[i])), sizeof(emote_buffer) - 2);  // -2 to leave room for the space and null terminator
                strcat(emote_buffer, " ");  // Always add a space after the emote
                if (caps) {
                    invert_caps(emote_buffer);
                }
                send_string(emote_buffer);
                return false;
            }
        }
    }
    return true;
}

#ifndef MAGIC_ENABLE
uint8_t mod_config(uint8_t mod) {
    return mod;
}
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}
#endif
