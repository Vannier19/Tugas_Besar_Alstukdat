#include "wordl3.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *validWords[] = {"ABUSE", "ADULT", "AGENT", "ANGER", "APPLE", "AWARD", "BASIS", "BEACH", "BIRTH", "BLOCK", "BLOOD", "BOARD", "BRAIN", "BREAD", "BREAK", "BROWN", "BUYER", "CAUSE", "CHAIN", "CHAIR", "CHEST", "CHIEF", "CHILD", "CHINA", "CLAIM", "CLASS", "CLOCK", "COACH", "COAST", "COURT", "COVER",  
"CREAM", "CRIME", "CROSS", "CROWD", "CROWN", "CYCLE", "DANCE", "DEATH", "DEPTH", "DOUBT", "DRAFT", "DRAMA", "DREAM", "DRESS", "DRINK", "DRIVE", "EARTH", "ENEMY", "ENTRY", "ERROR", "EVENT", "FAITH", "FAULT", "FIELD", "FIGHT", "FINAL", "FLOOR", "FOCUS", "FORCE", "FRAME", "FRANK", "FRONT", "FRUIT", "GLASS", "GRANT", "GRASS", "GREEN", "GROUP", "GUIDE", "HEART", "HENRY", "HORSE", "HOTEL", "HOUSE", "IMAGE", "INDEX", "INPUT", "ISSUE", "JAPAN", "JONES", "JUDGE", "KNIFE", "LAURA", "LAYER", "LEVEL", "LEWIS", "LIGHT", "LIMIT", "LUNCH", "MAJOR", "MARCH", "MATCH", "METAL", "MODEL", "MONEY", "MONTH", "MOTOR", "MOUTH", "MUSIC", "NIGHT", "NOISE", "NORTH", "NOVEL", "NURSE", "OFFER", "ORDER", "OTHER", "OWNER", "PANEL", "PAPER", "PARTY", "PEACE", "PETER", "PHASE", "PHONE", "PIECE", "PILOT", "PITCH", "PLACE", "PLANE", "PLANT", "PLATE", "POINT", "POUND", "POWER", "PRESS", "PRICE", "PRIDE", "PRIZE", "PROOF", "QUEEN", "RADIO", "RANGE", "RATIO", "REPLY", "RIGHT", "RIVER", "ROUND", "ROUTE", "RUGBY", "SCALE", "SCENE", "SCOPE", "SCORE", "SENSE", "SHAPE", "SHARE", "SHEEP", "SHEET", "SHIFT", "SHIRT", "SHOCK", "SIGHT", "SIMON", "SKILL", "SLEEP", "SMILE", "SMITH", "SMOKE", "SOUND", "SOUTH", "SPACE", "SPEED", "SPITE", "SPORT", "SQUAD", "STAFF", "STAGE", "START", "STATE", 
"STEAM", "STEEL", "STOCK", "STONE", "STORE", "STUDY", "STUFF", "STYLE", "SUGAR", "TABLE", "TASTE", "TERRY", "THEME", "THING", "TITLE", "TOTAL", "TOUCH", "TOWER", "TRACK", "TRADE", "TRAIN", "TREND", "TRIAL", "TRUST", "TRUTH", "UNCLE", "UNION", "UNITY", "VALUE", "VIDEO", "VISIT", "VOICE", "WASTE", "WATCH", "WATER", "WHILE", "WHITE", "WHOLE", "WOMAN", "WORLD", "YOUTH", "ALCON", "AUGHT", "HELLA", "ONE’S", "OUGHT", "THAME", "THERE", "THINE", "THINE", "WHERE", "WHICH", "WHOSE", "WHOSO", "YOURS", "YOURS", "ADMIT", "ADOPT", "AGREE", "ALLOW", "ALTER", "APPLY", "ARGUE", "ARISE", "AVOID", "BEGIN", "BLAME", "BREAK", "BRING", "BUILD", "BURST", "CARRY", "CATCH", "CAUSE", "CHECK", "CLAIM", "CLEAN", "CLEAR", "CLIMB", "CLOSE", "COUNT", "COVER", "CROSS", "DANCE", "DOUBT", "DRINK", "DRIVE", "ENJOY", "ENTER", "EXIST", "FIGHT", "FOCUS", "FORCE", "GUESS", "IMPLY", "ISSUE", "JUDGE", "LAUGH", "LEARN", "LEAVE", "LET’S", "LIMIT", "MARRY", "MATCH", "OCCUR", "OFFER", "ORDER", "PHONE", "PLACE", "POINT", "PRESS", "PROVE", "RAISE", "REACH", "REFER", "RELAX", "SERVE", "SHALL", "SHARE", "SHIFT", "SHOOT", "SLEEP", "SOLVE", "SOUND", "SPEAK", "SPEND", "SPLIT", "STAND", "START", "STATE", "STICK", "STUDY", "TEACH", "THANK", "THINK", "THROW", "TOUCH", "TRAIN", "TREAT", "TRUST", 
"VISIT", "VOICE", "WASTE", "WATCH", "WORRY", "WOULD", "WRITE", "ABOVE", "ACUTE", "ALIVE", "ALONE", "ANGRY", "AWARE", "AWFUL", "BASIC", "BLACK", "BLIND", "BRAVE", "BRIEF", "BROAD", "BROWN", "CHEAP", "CHIEF", "CIVIL", "CLEAN", "CLEAR", "CLOSE", "CRAZY", "DAILY", "DIRTY", "EARLY", "EMPTY", "EQUAL", "EXACT", "EXTRA", "FAINT", "FALSE", "FIFTH", "FINAL", "FIRST", "FRESH", "FRONT", "FUNNY", "GIANT", "GRAND", "GREAT", "GREEN", "GROSS", "HAPPY", "HARSH", "HEAVY", "HUMAN", "IDEAL", "INNER", "JOINT", "LARGE", "LEGAL", "LEVEL", "LIGHT", "LOCAL", "LOOSE", "LUCKY", "MAGIC", "MAJOR", "MINOR", "MORAL", "NAKED", "NASTY", "NAVAL", "OTHER", "OUTER", "PLAIN", "PRIME", "PRIOR", "PROUD", "QUICK", "QUIET", "RAPID", "READY", "RIGHT", "ROMAN", "ROUGH", "ROUND", "ROYAL", "RURAL", "SHARP", "SHEER", "SHORT", "SILLY", "SIXTH", "SMALL", "SMART", "SOLID", "SORRY", "SPARE", "STEEP", "STILL", "SUPER", "SWEET", "THICK", "THIRD", "TIGHT", "TOTAL", "TOUGH", "UPPER", "UPSET", "URBAN", "USUAL", "VAGUE", "VALID", "VITAL", "WHITE", "WHOLE", "WRONG", "YOUNG", "AFORE", "AFTER", "BOTHE", "OTHER", "SINCE", "SLASH", "UNTIL", "WHERE", "WHILE", "ABACK", "ABAFT", "ABOON", "ABOUT", "ABOVE", "ACCEL", "ADOWN", "AFOOT", "AFORE", "AFOUL", "AFTER", "AGAIN", "AGAPE", "AGOGO", "AGONE", "AHEAD", 
"AHULL", "ALIFE", "ALIKE", "ALINE", "ALOFT", "ALONE", "ALONG", "ALOOF", "ALOUD", "AMISS", "AMPLY", "AMUCK", "APACE", "APART", "APTLY", "AREAR", "ASIDE", "ASKEW", "AWFUL", "BADLY", "BALLY", "BELOW", "CANNY", "CHEAP", "CLEAN", "CLEAR", "COYLY", "DAILY", "DIMLY", "DIRTY", "DITTO", "DRILY", "DRYLY", "DULLY", "EARLY", "EXTRA", "FALSE", "FATLY", "FEYLY", "FIRST", "FITLY", "FORTE", "FORTH", "FRESH", "FULLY", "FUNNY", "GAILY", "GAYLY", "GODLY", "GREAT", "HAPLY", "HEAVY", "HELLA", "HENCE", "HOTLY", "ICILY", "INFRA", "INTL.", "JILDI", "JOLLY", "LAXLY", "LENTO", "LIGHT", "LOWLY", "MADLY", "MAYBE", "NEVER", "NEWLY", "NOBLY", "ODDLY", "OFTEN", "OTHER", "OUGHT", "PARTY", "PIANO", "PLAIN", "PLONK", "PLUMB", "PRIOR", "QUEER", "QUICK", "QUITE", "RAMEN", "RAPID", "REDLY", "RIGHT", "ROUGH", "ROUND", "SADLY", "SECUS", "SELLY", "SHARP", "SHEER", "SHILY", "SHORT", "SHYLY", "SILLY", "SINCE", "SLEEK", "SLYLY", "SMALL", "SO-SO", "SOUND", "SPANG", "SRSLY", "STARK", "STILL", "STONE", "STOUR", "SUPER", "TALLY", "TANTO", "THERE", "THICK", "TIGHT", "TODAY", "TOMOZ", "TRULY", "TWICE", "UNDER", "UTTER", "VERRY", "WANLY", "WETLY", "WHERE", "WRONG", "WRYLY", "ABAFT", "ABOON", "ABOUT", "ABOVE", "ADOWN", "AFORE", "AFTER", "ALONG", "ALOOF", "AMONG", "BELOW", "CIRCA", "CROSS", 
"FURTH", "MINUS", "NEATH", "ROUND", "SINCE", "SPITE", "UNDER", "UNTIL", "AARGH", "ADIEU", "ADIOS", "ALACK", "ALOHA", "AVAST", "BAKAW", "BASTA", "BEGAD", "BLESS", "BLIGE", "BRAVA", "BRAVO", "BRING", "CHOOK", "DAMME", "DILDO", "DITTO", "FRICK", "FUDGE", "GOLLY", "GRATZ", "HALLO", "HASTA", "HAVOC", "HELLA", "HELLO", "HOWAY", "HOWDY", "HULLO", "HUZZA", "JESUS", "KAPOW", "LOOSE", "LORDY", "MARRY", "MERCY", "NIGHT", "PLONK", "PSYCH", "QUITE", "SALVE", "SKOAL", "SNIFF", "SOOEY", "THERE", "THIAM", "THWAP", "TOUGH", "TWIRP", "VIOLA", "VIVAT", "WACKO", "WAHEY", "WHIST", "WILMA"};

char *targetWord;


int randomNumberGenerate() {
    return (rand() % 11); 
}

// Fungsi untuk mengecek apakah sebuah karakter ada di dalam sebuah string
int isCharInWord(char c, char *word) {
    int i = 0;
    while (word[i] != '\0') {
        if (word[i] == c) {
            return 1;
        }
        i++;
    }
    return 0;
}

// Fungsi untuk mencetak hasil pengecekan dari tebakan
void printFeedback(char *tebakan, char *targetWord) {
    for (int i = 0; i < 5; i++) {
        if (tebakan[i] == targetWord[i]) {
            printf("%c ", tebakan[i]); 
        } 
        else if (isCharInWord(tebakan[i], targetWord)) {
            printf("%c%% ", tebakan[i]);
        } 
        else {
            printf("%c* ", tebakan[i]);
        }
    }
    printf("\n");
}

void initializeHistory(char history[6][6]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            history[i][j] = '_'; // Inisialisasi dengan '_'
        }
    }
}


// Proses utama permainan
void playGame(int *saldo) {
    // Memilih targetWord
    srand(time(NULL));
    int targetIdx = randomNumberGenerate();
    targetWord = validWords[targetIdx];

    int attempts = 7;
    int statusMenang = 0;
    int biayaWordl = 500;
    int hadiahWordl = 1500;

    if (*saldo < biayaWordl) {
        printf("Yah... sayang sekali saldo Anda tidak cukup untuk bermain WORDL3.\n");
        return;
    }

    // char results[MAX_ATTEMPTS][WORD_LENGTH + 1] = {{0}};
    // int currentAttempt = 0;
    *saldo -= biayaWordl;
    // printf("SALDONYA SEGINI %d \n",saldo);
    printf("WELCOME TO W0RDL3, YOU HAVE %d CHANCES TO ANSWER BEFORE YOU LOSE!\n\n", MAX_ATTEMPTS);
    char history[6][6];
    initializeHistory(history);
    
    int currentAttempt = 0;

    for (int i = 0; i<MAX_ATTEMPTS; i++) {
        printf("_ _ _ _ _\n");
    }

    // char history[6][6];
    // initializeHistory(history);
    while (attempts > 0 && !statusMenang) {
        // Input tebakan
        printf("\nMasukan kata tebakan Anda: ");
        startKata();

        // Ubah currentWord menjadi stringS
        char tebakan[6] = {'\0'};
        for (int i=0; i<currentWord.Length; i++) {
            tebakan[i] = currentWord.TabWord[i];
        }
        tebakan[currentWord.Length] = '\0'; // ini null-terminator sebuah string

        for (int i = 0; i < 5; i++) {
            history[currentAttempt][i] = tebakan[i];
        }
        currentAttempt++;

        // Cek tebakan bener atau engga
        if (isEqualChar(tebakan, targetWord) == true) {
            printf("Selamat Anda menang!!\n");
            printf("+1500 rupiah telah ditambahkan kesaldo akun Anda.\n");
            statusMenang = 1;
            *saldo += hadiahWordl;
            printf("SALDONYA SEGINI %d \n",*saldo);
            break;
        } else {
            printf("Hasil:\n");
            printFeedback(tebakan, targetWord);
            attempts--;
        }

        // Tambahkan debug di sini
        printf("statusMenang: %d, attempts: %d\n", statusMenang, attempts);
    }
    // Kesempatan sudah abis, jadi kalah
    if (!statusMenang) {
        printf("Boo! Anda kalah. Kata yang benar adalah: %s\n", targetWord);
    }
    printf("\nSaldo Anda saat ini: %d rupiah\n", *saldo);
}
